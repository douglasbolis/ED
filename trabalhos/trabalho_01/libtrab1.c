#include <stdio.h>
#include <stdlib.h>
#include "libtrab1.h"

/**
  *	Definindo a estrutura das células da matriz.
  */
struct cell {
	int posI;
	int posJ;
	info_t info;
	Cell *nextLin;
	Cell *nextCol;
};

/**
  *	Definindo estrutura da matriz.
  */
struct mat {
	int lin;
	int col;
	Cell **linha;
	Cell **coluna;
};

/**
  *	Cria uma matriz NxN vazia.
  */
Mat* cria_matriz(int n) {
// Alocando memória para a criação da matriz
	Mat *matriz = malloc(sizeof(Mat));
	int i;

	matriz->lin = n;
	matriz->col = n;
// Alocando memória para os vetores de célula para linha e coluna
	matriz->linha = malloc(n * sizeof(Cell*));
	matriz->coluna = malloc(n * sizeof(Cell*));
	
// Preenchendo os vetores de linha e coluna com NULL.
	for (i = 0; i < n; i++) {
            matriz->linha[i] = NULL;
            matriz->coluna[i] = NULL;
	}

	return matriz;
}

/**
  *	Cria uma célula vazia.
  */
Cell* cria_celula(int i, int j, info_t info) {
	Cell * celula = malloc(sizeof(Cell));
	celula->posI = i;
	celula->posJ = j;
	celula->info = info;
	celula->nextLin = NULL;
	celula->nextCol = NULL;

	return celula;
}

/**
  *	Desaloca a célula.
  */
void desaloca_celula(Cell *cell) {
    free(cell);
}

/**
  * Descobre se existe uma célula na posição (i, j)
  */
int posicao_existe(Mat *matriz, int i, int j) {
// Verificando se a linha ou coluna possui alguma célula.
	if (matriz->linha[i] == NULL || matriz->coluna[j] == NULL) return 0;

	Cell *c = matriz->linha[i];
// Buscando a célula na posição j da linha i.
	while (c != NULL && c->posJ < j) {
		c = c->nextLin;
	}

// Verificando se a execução saiu do while por causa de c->nextLin == NULL.
	if (c == NULL || c->posJ > j) {
		return 0;
	} else {
		return 1;
	}
}

/**
  *	Remove uma célula na linha i da matriz.
  */
void remove_na_linha(Mat *matriz, int i, int j) {
// Adicionando as células de controle \
// anterior iniciando com NULL e atual com a linha de onde a célula será removida.
	Cell *anter = NULL;
	Cell *atual = matriz->linha[i];

// Buscando a célula na posição j da linha i.
	while (atual->posJ < j) {
		anter = atual;
		atual = atual->nextLin;
	}

	if (anter == NULL) {
		matriz->linha[i] = atual->nextLin;
	} else {
		anter->nextLin = atual->nextLin;
	}
	
	return;
}

/**
  *	Remove uma célula na coluna j da matriz.
  */
void remove_na_coluna(Mat *matriz, int i, int j) {
// Adicionando as células de controle \
// anterior iniciando com NULL e atual com a coluna de onde a célula será removida.
	Cell *anter = NULL;
	Cell *atual = matriz->coluna[j];

// Buscando a célula na posição j da linha i.
	while (atual->posI < i) {
		anter = atual;
		atual = atual->nextCol;
	}

	if (anter == NULL) {
		matriz->coluna[j] = atual->nextCol;
	} else {
		anter->nextCol = atual->nextCol;
	}
// Desalocando célula removida da matriz.
	desaloca_celula(atual);
	
	return;
}

/**
  *	Remove uma célula na posição i, j da matriz.
  */
void remove_celula(Mat *matriz, int i, int j) {
// verifica se já existe uma célula na posição (i, j) da matriz.
	if (posicao_existe(matriz, i, j)) {
// Na função remove_na_coluna será desalocado a célula.
		remove_na_linha(matriz, i, j);
		remove_na_coluna(matriz, i, j);
	}
	
	return;
}

/**
  * Atualiza a celula na posição (i, j)
  */
void atualiza_celula(Mat *matriz, int i, int j, info_t info) {
	Cell *c = matriz->linha[i];
// Buscando a célula na linha i.
	while (c->posJ < j) {
		c = c->nextLin;
	}
	c->info = info;

	return;
}

/**
  * Descobre se existe uma célula na posição (i, j)
  */
void insere_na_linha(Mat *matriz, Cell *celula, int i, int j) {
    if (matriz->linha[i] == NULL) {
        celula->nextLin = NULL;
        matriz->linha[i] = celula;
        return;
    }

    Cell *c = matriz->linha[i];
// Buscando a célula na posição j da linha i.
    while (c->nextLin != NULL && c->posJ < j) {
        c = c->nextLin;
    }

// Verificando se a execução saiu do while por causa de c->nextCol == NULL.
    if (c == NULL) {
        celula->nextLin = NULL;
        // erro aqui (NULL não possui nextCol. rsrs)
        c->nextLin = celula;
    } else {
// Senão, a inserção ocorrerá entre duas células.
            celula->nextLin = c->nextLin;
            c->nextLin = celula;
    }
}

/**
  * Descobre se existe uma célula na posição (i, j)
  */
void insere_na_coluna(Mat *matriz, Cell *celula, int i, int j) {
    if (matriz->coluna[j] == NULL) {
        celula->nextCol = NULL;
        matriz->coluna[j] = celula;
        return;
    }

    Cell *c = matriz->coluna[j];
// Buscando a célula na posição j da linha i.
    while (c->nextCol != NULL && c->posI < i) {
        c = c->nextCol;
    }

// Verificando se a execução saiu do while por causa de c->nextCol == NULL.
    if (c == NULL) {
        celula->nextCol = NULL;
        // erro aqui (NULL não possui nextCol. rsrs)
        c->nextCol = celula;
    } else {
// Senão, a inserção ocorrerá entre duas células.
            celula->nextCol = c->nextCol;
            c->nextCol = celula;
    }
}

/**
  *	Insere uma célula na posição i, j da matriz.
  */
void insere_celula(Mat *matriz, int i, int j, info_t info) {
	if (info == 0.0) {
// Se o valor da célula for igual a zero a célula será removida.
            remove_celula(matriz, i, j);
	} else
	if (posicao_existe(matriz, i, j)) {
// Atualizando uma célula existente.
            atualiza_celula(matriz, i, j, info);
	} else {
// Criando a nova célula.
            Cell *celula = cria_celula(i, j, info);
// Com a célula já criada, agora a inserção da célula na matriz \
// primeiro linha depois coluna, separadamente.
            insere_na_linha(matriz, celula, i, j);
            insere_na_coluna(matriz, celula, i, j);
	}
	return;
}

/**
 * 
 */

Cell* get_celula(Mat* matriz, int i, int j) {
    if (matriz->linha[i] == NULL) {
        return NULL;
    }
    
    Cell *c = matriz->linha[i];
    
    while(c->nextCol != NULL && c->posJ < j) {
        c = c->nextCol;
    }
    
    if (c == NULL || c->posJ != j) {
        return NULL;
    }
    return c;
}

/**
  *	Soma as duas matrizes.
  */
Mat* soma_matriz(Mat *matrizA, Mat *matrizB) {
// Controle para o for,
    int i, j;
// Auxiliares tipo célula,
    Cell *a = NULL;
    Cell *b = NULL;
// Criando nova matriz de retorno,
    Mat *matrizC = cria_matriz(matrizA->lin);
    
    for (i = 0; i < matrizA->lin; i++) {
        for (j = 0; j < matrizA->col; j++) {
            a = get_celula(matrizA, i, j);
            b = get_celula(matrizB, i, j);
            
            if (a == NULL && b == NULL) {
                insere_celula(matrizC, i, j, 0.0);
            } else
            if (a == NULL) {
                insere_celula(matrizC, i, j, b->info);
            } else 
            if (b == NULL) {
                insere_celula(matrizC, i, j, a->info);
            } else {
                insere_celula(matrizC, i, j, a->info + b->info);
            }
        }
    }    

    return matrizC;
}

/**
  *	Imprime matriz.
  */
void imprime_matriz(Mat *matriz) {
	int i, j;

	Cell *atual = NULL;

	printf("%d\n", matriz->lin);

	for (i = 0; i < matriz->lin; i++) {
		atual = matriz->linha[i];

		while (atual != NULL) {
			printf("%d;%d;%g\n", atual->posI+1, atual->posJ+1, atual->info);
			atual = atual->nextLin;
		}
	}
}

/**
  *	Desaloca a matriz.
  */
void desaloca_matriz(Mat *matriz) {
    int i, j;

    Cell *atual = NULL;
    
    for (i = 0; i < matriz->lin; i++) {
        atual = matriz->linha[i];

        while (atual != NULL) {
            j = atual->posJ;
            atual = atual->nextLin;
            remove_celula(matriz, i, j);
        }
    }
    free(matriz->linha);
    free(matriz->coluna);
    free(matriz);
}