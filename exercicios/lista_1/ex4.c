#include <stdio.h>
#include <lib.h>

/**
  *	Faça um programa que leia do teclado uma matriz 3 × 3 de float e normalize os seus valores,
  * dividindo-os pelo maior valor da matriz. Imprima a matriz normalizada
  */

#define LINHA 3
#define COLUNA 3

int main() {
	int i, j;
	float maiorValor = -1000000.0;
	float mat[LINHA][COLUNA];

	for (i = 0; i < LINHA; i++) {
		for (j = 0; j < COLUNA; j++) {
			printf("\nInforme o valor para A[%d][%d] na matriz: ", i, j);
			scanf("%f", &mat[i][j]);
			if (mat[i][j] > maiorValor) {
				maiorValor = mat[i][j];
			}
		}
	}

	normaliza_matriz(mat, maiorValor);
	imprime_matriz(mat);

	return 0;
}