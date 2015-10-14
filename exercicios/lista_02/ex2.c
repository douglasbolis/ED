#include <stdio.h>

void imprime(int *v, int tam) {
	int i;

	for (i = 0; i < tam; i++) {
		printf(" %d", v[i]);
	}
	printf("\n");
}

int main() {
	int vet[4] = {1, 2, 3, 4};

	imprime(vet, 4);

	return 0;
}