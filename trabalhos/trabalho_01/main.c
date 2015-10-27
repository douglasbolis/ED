#include "libtrab1.h"
#include <stdio.h>

int main() {

	Mat *matrizA = cria_matriz(4);
	Mat *matrizB = cria_matriz(4);
        Mat *matrizC = NULL;

	insere_celula(matrizA, 1-1, 1-1, 50);
	insere_celula(matrizA, 2-1, 1-1, 10);
	insere_celula(matrizA, 2-1, 3-1, 20);
	insere_celula(matrizA, 4-1, 1-1, -30);
	insere_celula(matrizA, 4-1, 3-1, -60);
	insere_celula(matrizA, 4-1, 4-1, 5);
        
	insere_celula(matrizB, 1-1, 1-1, 35);
	insere_celula(matrizB, 2-1, 1-1, 10.4);
	insere_celula(matrizB, 2-1, 4-1, -20.5);
	insere_celula(matrizB, 3-1, 1-1, 5);
	insere_celula(matrizB, 3-1, 4-1, 8);
	insere_celula(matrizB, 4-1, 2-1, 17);
	insere_celula(matrizB, 4-1, 3-1, -60);
	
        matrizC = soma_matriz(matrizA, matrizB);
        
        desaloca_matriz(matrizA);
        desaloca_matriz(matrizB);

	imprime_matriz(matrizC);
        
        desaloca_matriz(matrizC);

	return 0;
}