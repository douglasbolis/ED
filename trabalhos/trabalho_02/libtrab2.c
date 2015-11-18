/* 
 * File:   libtrab2.c
 * Author: douglas
 */

#include <stdio.h>
#include <stdlib.h>
#include "libtrab2.h"

// Definindo tamanho máximo dos pinos da 'Torre de Hanoi'.
#define MAX_SZ 40

// Definindo estrutura pino
struct pino {
    info_t *v;
    int top;
    char id;
};

// Retorna a quantidade de discos presentes no pino
int size_pino(Pino *p) {
    return p->top+1;
}

// Empilha o disco no pino p.
void push_pino(Pino *p, info_t disco) {
// Caso p esteja cheio uma mensagem de erro será impressa.
    if (size_pino(p) == MAX_SZ) {
        printf("Error! O pino está completo.");
        return;
    }
    
    p->v[++p->top] = disco;
}

// Desempilha o disco do topo do pino p.
info_t pop_pino(Pino *p) {
// Caso p esteja vazio uma mensagem de erro será impressa.
    if (size_pino(p) == 0) {
        printf("Error! O pino está vazio.");
        return 0;
    }
    
    return p->v[p->top--];
}

// Apenas retorna o disco que está no topo do pino p.
info_t peek_pino(Pino *p) {
// Caso p esteja vazio uma mensagem de erro será impressa
// e retornará 0(zero) se o pino estiver vazio.
    if (size_pino(p) == 0) {
        printf("Error! O pino está vazio.");
        return 0;
    }
    
    return p->v[p->top];
}

// Imprime os discos que o pino p possue.
void print_pino(Pino *p) {
    int i;
    
    for (i = 0; i < size_pino(p); i++) {
        printf(" %d", p->v[i]);
    }
}

// Imprime os discos de todos os pinos
void print_hanoi(Hanoi *h) {
    printf("\n%4c:", h->A->id);
    print_pino(h->A);
    printf("\n%4c:", h->B->id);
    print_pino(h->B);
    printf("\n%4c:", h->C->id);
    print_pino(h->C);
    printf("\n");
}

// Esta função é executada apenas quando uma nova torre for alocada,
// geralmente o pino p será o pino 'A' da nova torre.
void inicio_jogo(Pino *p, int qtdDisco) {
    int i;
    
    for (i = qtdDisco; i > 0; i--) {
        push_pino(p, i);
    }
}

Pino* create_pino() {
// Cria dinamicamente um pino e o retorna.
    Pino *p = malloc(sizeof(Pino));
// Aloca dinamicamente para caberem <MAX_SZ> discos no pino.
    p->v = malloc(MAX_SZ * sizeof(info_t));
// <top> recebe -1 para controle do vetor de discos.
    p->top = -1;
    
    return p;
}

Hanoi* create_hanoi(int qtdDisco) {
// Se qtdDisco for menor que 3 ou maior que MAX_SZ returna NULL.
    if (qtdDisco < 3 || qtdDisco > MAX_SZ) return NULL;

// Cria dinamicamente uma 'Torre de Hanoi'.
    Hanoi *h = malloc(sizeof(Hanoi));

// Chamada à função para criar um pino
// Todos os 3(três) pinos receberão um identificador(id)
// para fim de controle na impressão dos passos.
    h->A = create_pino();
    h->A->id = 'A';
    h->B = create_pino();
    h->B->id = 'B';
    h->C = create_pino();
    h->C->id = 'C';
    
    inicio_jogo(h->A, qtdDisco);
    
    return h;
}

void free_hanoi(Hanoi *h) {
// Liberando espaço de memória para os vetores do pino
// para os pinos da torre e para a pŕopria torre.
    free(h->A->v);
    free(h->A);
    free(h->B->v);
    free(h->B);
    free(h->C->v);
    free(h->C);
    free(h);
}

// Aqui, literalmente, é onde o puzzle é resolvido.
void resolve_jogo(int n, Pino *orig, Pino *aux, Pino *dest, int verboso) {
// Condição de parada:
// Quando a quantidade de discos for 0(zero) retorna 'nada'.
    if (n == 0) return ;
    
// Chamada recursiva, passando n-1 e definindo a ordem de entrada dos pinos
// mantendo o sinal de verbosidade.
    resolve_jogo(n-1, orig, dest, aux, verboso);
// Inserindo no pino destino o disco removido da origem.
    push_pino(dest, pop_pino(orig));
// Verificando se o sinal de verbosidade é igual a 1,
// se sim, os passos serão impressos na tela.
    if (verboso) printf("\n%7s disk %d from %c to %c", "Move", n, orig->id, dest->id);
// Aqui, novamente, outra chamada recursiva.
    resolve_jogo(n-1, aux, orig, dest, verboso);         
}