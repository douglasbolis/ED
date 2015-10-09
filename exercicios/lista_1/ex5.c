#include <stdio.h>

/*
Escreva um algoritmo que lê do teclado uma matriz 4×2 de inteiros. A seguir, troque os elementos
da primeira linha com os elementos da segunda linha e os da terceira linha com a quarta linha.
Imprima a matriz resultante.
*/

#define LINHA 4
#define COLUNA 2

void inverte_linhas(int mat[LINHA][COLUNA]) {
	int i, j, aux = 0;

	for (i = 0; i < LINHA; i = i+2) {
		for (j = 0; j < COLUNA; j++) {
			aux = mat[i][j];
			mat[i][j] = mat[i+1][j];
			mat[i+1][j] = aux;
		}
	}
}

void imprime_matriz(int mat[LINHA][COLUNA]) {
	int i, j;

	for (i = 0; i < LINHA; i++) {
		for (j = 0; j < COLUNA; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int i, j;
	int mat[LINHA][COLUNA];

	for (i = 0; i < LINHA; i++) {
		for (j = 0; j < COLUNA; j++) {
			printf("\nInforme o valor para A[%d][%d] na matriz: ", i, j);
			scanf("%d", &mat[i][j]);
		}
	}

	inverte_linhas(mat);
	imprime_matriz(mat);
	
	return 0;
}