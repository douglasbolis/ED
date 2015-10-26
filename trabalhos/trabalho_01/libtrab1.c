#include <stdio.h>
#include <stdlib.h>
#include "libtrab1.h"

#define TRUE 1
#define FALSE 0

typedef struct cell Cell;
typedef struct mat Mat;

/**
  *	Definindo a estrutura das células da matriz.
  */
struct cell {
	int posI;
	int posJ;
	float info;
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
Cell* cria_celula(int i, int j, float info) {
	Cell * celula = malloc(sizeof(Cell));	

	celula->posI = i;
	celula->posJ = j;
	celula->info = info;
	celula->nextLin = NULL;
	celula->nextCol = NULL;

	return celula;
}

/**
  *	Insere uma célula na posição i, j da matriz.
  */
void insere_celula(Mat *matriz, int i, int j, float info) {
	if (info == 0.0) {
// Se o valor da célula for igual a zero a célula será removida.
		remove_celula(matriz, i, j);
	} else
	if (posicao_existe(matriz, i, j)) {
// Atualizando uma célula existente.
		atualiza_celula(matriz, i, j, info);
	} else {
// Criando a nova célula.
		Cell * celula = cria_celula(i, j, info);
// Com a célula já criada, agora a inserção da célula na matriz \
// primeiro linha depois coluna, separadamente.
		insere_na_linha(matriz, celula, i, j);
		insere_na_coluna(matriz, celula, i, j);
	}
	return;
}

/**
  * Descobre se existe uma célula na posição (i, j)
  */
int posicao_existe(Mat *matriz, int i, int j) {
// Verificando se a linha ou coluna possui alguma célula.
	if (matriz->linha[i] == NULL || matriz->coluna[j] == NULL) return 0;

	Cell *c = matriz->linha[i];
// Buscando a célula na posição j da linha i.
	while (c->nextLin != NULL && c->posJ < j) {
		c = c->nextLin;
	}

// Verificando se a execução saiu do while por causa de c->nextLin == NULL.
	if (c == NULL || c->nextLin->posJ > j) {
		return 0
	} else {
		return 1;
	}
}

/**
  * Atualiza a celula na posição (i, j)
  */
void atualiza_celula(Mat *matriz, int i, int j, float info) {
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
	Cell *c = matriz->linha[i];

// Buscando a célula na posição j da linha i.
	while (c->nextLin != NULL && c->posJ < j) {
		c = c->nextLin;
	}

// Verificando se a execução saiu do while por causa de c->nextLin == NULL.
	if (c == NULL) {
		celula->nextLin = NULL;
		c->nextLin = celula;
	} else
// Senão, a inserção ocorrerá entre duas células.
	if (c->nextLin->posJ > j) {
		celula->nextLin = c->nextLin;
		c->nextLin = celula;
	}

	return;
}

/**
  * Descobre se existe uma célula na posição (i, j)
  */
void insere_na_coluna(Mat *matriz, Cell *celula, int i, int j) {
	Cell *c = matriz->coluna[j];

// Buscando a célula na posição j da linha i.
	while (c->nextCol != NULL && c->posI < i) {
		c = c->nextCol;
	}

// Verificando se a execução saiu do while por causa de c->nextCol == NULL.
	if (c == NULL) {
		celula->nextCol = NULL;
		c->nextCol = celula;
	} else
// Senão, a inserção ocorrerá entre duas células.
	if (c->nextCol->posI > i) {
		celula->nextCol = c->nextCol;
		c->nextCol = celula;
	}

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
void remove_na_coluna(Mat *matriz, Cell *celula, int i, int j) {
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
  *	Soma as duas matrizes.
  */
Mat* soma_matriz(Mat *matrizA, Mat *matrizB) {
	Mat *matrizC = malloc(sizeof(Mat));


	return matrizC;
}

/**
  *	Imprime matriz.
  */
void imprime_matriz(Mat *matriz) {
	int i, j;

	for (i = 0; i < matriz->lin; i++) {
		for (j = 0; j < matriz->col; j++) {
			
		}
	}
}

/**
  *	Desaloca a célula.
  */
void desaloca_celula(Cell *cell) {
	free(cell);
}

/**
  *	Desaloca a matriz.
  */
void desaloca_matriz(Mat *matriz) {
	free(matriz);
}