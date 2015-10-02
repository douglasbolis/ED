#include <stdio.h>

/**
  * Escreva um programa que gera e escreve os quatro primeiros números perfeitos.
  * Um número perfeito é aquele que é igual à soma dos seus divisores 
  * (por exemplo, 6, 28, etc)
  */

int calculaExpo(int base, int expo) {
	int res = 1, i;

	for (i = 0; i < expo; i++) {
		res *= base;
	}

	return res;
}

main() {
	int numPerfect[4];
	int num[4] = {2, 3, 5, 7};
	int n = 0;

	printf("\nOs quatros primeiros números perfeitos são:\n");
	for (n = 0; n < 4; n++) {
		numPerfect[n] = calculaExpo(2, num[n]-1)*(calculaExpo(2, num[n])-1);
		printf("%d\n", numPerfect[n]);
	}
}