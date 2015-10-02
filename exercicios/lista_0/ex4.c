#include <stdio.h>

/**
  *	Faça um programa que leia do teclado uma matriz 3 × 3 de float e normalize os seus valores,
  * dividindo-os pelo maior valor da matriz. Imprima a matriz normalizada
  */

int main() {
	int i, j;
	int l = 3, c = 3;
	float maiorValor = -1000000.0;
	float mat[l][c];

	for (i = 0; i < l; i++) {
		for (j = 0; j < c; j++) {
			printf("\nInforme o valor para A[%d][%d] na matriz: ", i, j);
			scanf("%f", &mat[i][j]);
			if (mat[i][j] > maiorValor) {
				maiorValor = mat[i][j];
			}
		}
	}

	mat = normaliza_matriz(mat, l, c, maiorValor);
	imprime_matriz(mat, l, c);

	return 0;
}

float normaliza_matriz(float mat, int l, int c, float maiorValor) {
	int i, j;

	for (i = 0; i < l; i++) {
		for (j = 0; j < c; j++) {
			mat[i][j] = mat[i][j] / maiorValor;
		}
	}

	return mat;
}

void imprime_matriz(float mat, int l, int c) {
	int i, j;

	for (i = 0; i < l; i++) {
		printf("\n");
		for (j = 0; j < c; j++) {
			printf("%f ", mat[i][j]);
		}
	}
}