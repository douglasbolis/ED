#include <stdio.h>
#include <lib.h>

/*
Escreva um algoritmo que lê do teclado uma matriz 4×2 de inteiros. A seguir, troque os elementos
da primeira linha com os elementos da segunda linha e os da terceira linha com a quarta linha.
Imprima a matriz resultante.
*/

#define LINHA 4
#define COLUNA 2

int main() {
	int i, j;
	int mat[LINHA][COLUNA];

	for (i = 0; i < LINHA; i++) {
		for (j = 0; j < COLUNA; j++) {
			printf("\nInforme o valor para A[%d][%d] na matriz: ", i, j);
			scanf("%d", &mat[i][j]);
		}
	}

	inverte_linhas_int(mat);
	imprime_matriz_int(mat);
	
	return 0;
}