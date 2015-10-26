#ifndef LIBTRAB1_H
#define LIBTRAB1_H

typedef struct cell Cell;
typedef struct mat Mat;

/**
  *	Cria uma matriz NxN vazia.
  */
Mat* cria_matriz(int);

/**
  *	Insere uma célula na posição i, j da matriz.
  */
void insere_celula(Mat*, int, int, float);

/**
  *	Remove uma célula na posição i, j da matriz.
  */
void remove_celula(Mat*);

/**
  *	Imprime matriz.
  */
void imprime_matriz(Mat*);

/**
  *	Soma as duas matrizes.
  */
void soma_matriz(Mat*, Mat*);

/**
  *	Desaloca a matriz.
  */
void desaloca_matriz(Mat*);

#endif	