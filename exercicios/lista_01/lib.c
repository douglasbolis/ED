#include <stdio.h>
#include "lib.h"

void imprimeMedia(char* nome, float media) {
	printf("\n%s, você ficou com média de %.2f pontos.\n", nome, media);
}

float calculaMedia(float total, int qtd) {
	return total/qtd;
}

int calculaExpo(int base, int expo) {
	int res = 1, i;

	for (i = 0; i < expo; i++) {
		res *= base;
	}

	return res;
}

int* retiraNum(int* vet, int tam, int num) {
	int i, j, tamOrg = tam;

	for(i = 0; i < tam; i++) {
	    if(vet[i] == num) {
	       for(j = i; j < tam-1; j++) {
	          vet[j] = vet[j+1];
	       }

	       tam--;
	    }
	}

	for (i = tam; i < tamOrg; i++) {
		vet[i] = num;
	}

	return vet;
}

void imprimeVetorInt(int* vet, int tam) {
	int i, j;

	for (i = 0; i < tam; i++) {
		printf(" %d", vet[i]);
	}
	printf("\n");
}

void normaliza_matriz_float(float mat[3][3], int l, int c, float maiorValor) {
	int i, j;

	for (i = 0; i < l; i++) {
		for (j = 0; j < c; j++) {
			mat[i][j] = mat[i][j] / maiorValor;
		}
	}
}

void imprime_matriz_float(float mat[3][3], int l, int c) {
	int i, j;

	for (i = 0; i < l; i++) {
		for (j = 0; j < c; j++) {
			printf("%.2f ", mat[i][j]);
		}
		printf("\n");
	}
}

void inverte_linhas_int(int mat[4][2], int l, int c) {
	int i, j, aux = 0;

	for (i = 0; i < l; i = i+2) {
		for (j = 0; j < c; j++) {
			aux = mat[i][j];
			mat[i][j] = mat[i+1][j];
			mat[i+1][j] = aux;
		}
	}
}

void imprime_matriz_int(int mat[4][2], int l, int c) {
	int i, j;

	for (i = 0; i < l; i++) {
		for (j = 0; j < c; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}