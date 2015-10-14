#include <stdio.h>
#include "lib.h"

/**
  * Faça um programa que leia o nome de uma pessoa, a quantidade de provas realizadas por ela e suas
  * respectivas notas. O programa deve apresentar ao final o nome e a m´edia das notas obtidas pela
  * pessoa.
  */

main() {
	char nome[50];
	int qtdProvas = 0, p = 0;
	float notas[qtdProvas], media = 0.0;

	printf("Digite o seu nome: ");
	scanf("%[^\n]", nome);

	printf("\nQuantas provas você fez %s: ", nome);
	scanf("%d", &qtdProvas);

	for (p = 0; p < qtdProvas; p++) {
		printf("\nNota da prova %d: ", p+1);
		scanf("%f", &notas[p]);
		media += notas[p];
	}

	imprimeMedia(nome, calculaMedia(media, qtdProvas));
}