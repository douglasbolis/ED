#include <stdio.h>

struct pessoa {
	char nome[20];
	char tel[11];
	char end[30];
};

// Funcao para limpar o buffer do teclado.
void clear(void) {
  while ( getchar() != '\n' );
}


void imprime(struct pessoa dados[], int qtdPessoas) {
	int j;

	for(j = 0; j < qtdPessoas; j++) {
		printf("\n\n%dº Pessoa:\nnome: %s\ntelefone: %s\nendereço: %s\n", j+1, dados[j].nome, dados[j].tel, dados[j].end);
	}
}

int main() {
	int qtdPessoas = 1;
	struct pessoa dados[qtdPessoas];
	int i;

	for (i = 0; i < qtdPessoas; i++) {
		printf("\n\nNome: ");
		scanf("%[^\n]s", dados[i].nome); clear();
		printf("\nTelefone: ");
		scanf("%[^\n]s", dados[i].tel); clear();
		printf("\nEndereço: ");
		scanf("%[^\n]s", dados[i].end); clear();
	}

	imprime(dados, qtdPessoas);

	return 0;
}