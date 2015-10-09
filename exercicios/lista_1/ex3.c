#include <stdio.h>
#include <lib.h>

/**
  * Faça um programa que lê um vetor de inteiros e “remove” os elementos contendo
  * o valor 0 (transfira os para o final do vetor). Mostre o vetor resultante na tela.
  * Exemplo: O vetor 0 1 3 -1 0 0 5 
  *				fica 1 3 -1 5 0 0 0.
  */

int main() {
	int vet[7] = {-1, 0, 1, 0, -3, 6, 4};
	int tamVet = sizeof(vet) / sizeof(int);

	imprimeVetorInt(vet, tamVet);
	imprimeVetorInt(retiraNum(vet, tamVet, 0), tamVet);

	return 0;
}