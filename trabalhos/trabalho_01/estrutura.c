#include <stdio.h>
#include <stdlib.h>

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
Mat* create_matriz(int n) {
	// Alocando memória para a criação da matriz
	Mat *matriz = malloc(sizeof(Mat));
	int i;

	matriz->lin = l;
	matriz->col = c;
	// Alocando memória para os vetores de célula para linha e coluna
	matriz->linha = malloc(l * sizeof(Cell));
	matriz->coluna = malloc(c * sizeof(Cell));
	
	// Preenchendo os vetores de linha e coluna com NULL.
	for (i = 0; i < n; i++) {
		matriz->linha[i] = NULL;
		matriz->coluna[i] = NULL;
	}

	return matriz;
}

/**
  *	Insere uma célula na posição i, j da matriz.
  */
void insere_celula(Mat *matriz, int i, int c, float info) {
	// verificar se já existe uma célula na posição (i, j) da matriz
	// (se já existe o valor nesta posição)
}

/**
  *	Remove uma célula na posição i, j da matriz.
  */
void remove_celula(Mat *matriz) {
	// verificar se já existe uma célula na posição (i, j) da matriz
	// (se já existe o valor nesta posição)
}

/**
  *	Imprime matriz.
  */
void imprime_matriz(Mat *matriz) {
	
}

/**
  *	Soma as duas matrizes.
  */
void soma_matriz(Mat *matriz) {
	
}

/**
  *	Desaloca a matriz.
  */
void desaloca_matriz(Mat *matriz) {
	free(matriz);
}