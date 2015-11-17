/* 
 * File:   main.c
 * Author: douglas
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libtrab2.h"

/*
 * 
 */
int main(int argc, char** argv) {
// Verificando a quantidade de parâmetros
// deve haver ao menos 2 parâmetros.
    if (argc == 1) {
        printf("Parametros insuficiente.\n");
        return 0;
    }

// Definindo quantidade de disco que os pinos terão.
    int n = atoi(argv[1]);
// Armazenando em 'h' a estrutura da 'Torre de Hanoi'.
    Hanoi *h = create_hanoi(n);
// Se 'h' for NULL é porque o número de discos é menor que 3
// e maior que MAX_SZ(definido em libtrab2.c).
    if (h == NULL) {
        printf("Programa encerrado devido à quantidade de discos inválida.\n");
        return 0;
    }
// Testando se a quantidade de parâmetros são 3
// e se o terceiro é '-v', que define se será impresso os passos.
    if (argc == 3 && strcmp(argv[2], "-v") == 0) {
        printf("=> Solving the Tower of Hanoi with %d disks.\n=> Initial configuration:", n);
// Imprimindo na tela a configuração inicial do jogo.
        print_hanoi(h);
        printf("=> Moves:");
// A função resolve_jogo é onde está todo o processo de empilhar e desempilhar
// os pinos, onde n é a quntidade de pino, seguido dos pinos A, B e C
// e um int(1 no caso) para o controle de verbosidade na saída.
        resolve_jogo(n, h->A, h->B, h->C, 1);
        printf("\n=> Final configuration:");
// Imprimindo na tela a configuração final do jogo.
        print_hanoi(h);
    }
// Aqui mesma coisa que anteriormente, mas com o int igual a 0(zero) para
// apenas resolver o jogo(sem verbosidade).
    else resolve_jogo(n, h->A, h->B, h->C, 0);
    
// Liberando memória para as variáveis alocadas dinamicamente.
    free_hanoi(h);

    return 0;
}