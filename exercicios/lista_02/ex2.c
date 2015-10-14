#include <stdio.h>

void imprime(int *v, int tam) {
	int i;

	for (i = 0; i < tam; i++) {
		printf(" %d", v[i]);
	}
	printf("\n");
}

int main() {
	int tam = 5;
	int vet[] = {13, 25, 30, 4, 2};

	imprime(vet, tam);

	return 0;
}