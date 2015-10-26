#include "libtrab1.h"
#include <stdio.h>

int main() {

	Mat *matrizA = cria_matriz(4);
	Mat *matrizB = cria_matriz(4);
	Mat *matrizC = cria_matriz(4);

	insere_celula(matrizA, 1, 1, 50);
	insere_celula(matrizA, 2, 1, 10);
	insere_celula(matrizA, 2, 3, 20);
	insere_celula(matrizA, 4, 1, -30);
	insere_celula(matrizA, 4, 3, -60);
	insere_celula(matrizA, 4, 4, 5);
/*
	insere_celula(matrizB, 1, 1, 35);
	insere_celula(matrizB, 2, 1, 10.4);
	insere_celula(matrizB, 2, 4, -20.5);
	insere_celula(matrizB, 3, 1, 5);
	insere_celula(matrizB, 3, 4, 8);
	insere_celula(matrizB, 4, 2, 17);
	insere_celula(matrizB, 4, 3, -60);
*/
	//soma_matriz(matrizA, matrizB);

	imprime_matriz(matrizA);
	//imprime_matriz(matrizC);

	return 0;
}