#include <stdio.h>

struct telefone {
	int DDD;
	char num[10];
	char tipo[7];
};

struct pessoa {
	char nome[20];
	struct telefone tel;
	char end[30];
};

// Funcao para limpar o buffer do teclado.
void clear(void) {
  while ( getchar() != '\n' );
}

void imprime(struct pessoa dados[], int qtdPessoas) {
	int j;

	for(j = 0; j < qtdPessoas; j++) {
		printf("\n\n%dº Pessoa:\nnome: %s\ntelefone: (%d)%s %s\nendereço: %s\n", 
			j+1, dados[j].nome, dados[j].tel.DDD, dados[j].tel.num, dados[j].tel.tipo, dados[j].end);
	}
}

int main() {
	int qtdPessoas = 2;
	struct pessoa dados[qtdPessoas];
	int i;

	for (i = 0; i < qtdPessoas; i++) {
		printf("\n\nNome: ");
		scanf("%[^\n]s", dados[i].nome); clear();

		printf("\nTelefone: ");
		printf("\n - DDD: ");
		scanf("%d", &dados[i].tel.DDD); clear();

		printf("\n - Número: ");
		scanf("%[^\n]s", dados[i].tel.num); clear();

		printf("\n - Tipo: ");
		scanf("%[^\n]s", dados[i].tel.tipo); clear();

		printf("\nEndereço: ");
		scanf("%[^\n]s", dados[i].end); clear();
	}

	imprime(dados, qtdPessoas);

	return 0;
}