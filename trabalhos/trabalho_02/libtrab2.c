/* 
 * File:   libtrab2.c
 * Author: douglas
 */

#include <stdio.h>
#include <stdlib.h>
#include "libtrab2.h"

#define MAX_SZ 12

// Implementação das estruturas utilizadas no jogo
struct pino {
    info_t *v;
    int top;
};

struct hanoi {
    Pino *A;
    Pino *B;
    Pino *C;
};

/**
 * Retorna a quantidade de discos presentes no pino
 */
int size_pino(Pino *p) {
    return p->top+1;
}

void push_pino(Pino *p, info_t disco) {
    if (size_pino(p) == MAX_SZ) {
        printf("Error! O pino está completo.");
        return;
    }
    
    p->v[++p->top] = disco;
}

info_t pop_pino(Pino *p) {
    if (size_pino(p) == 0) {
        printf("Error! O pino está vazio.");
        return 0;
    }
    
    return p->v[p->top--];
}

info_t peek_pino(Pino *p) {
    if (size_pino(p) == 0) {
        printf("Error! O pino está vazio.");
        return 0;
    }
    
    return p->v[p->top];
}

void print_pino(Pino *p) {
    int i;
    
    for (i = 0; i < size_pino(p); i++, printf(" %d", p->v[i]));
}

void inicio_jogo(Pino *pino, int qtdDisco) {
    for (qtdDisco; qtdDisco > 0; qtdDisco--) {
        push_pino(pino, qtdDisco);
    }
}

Pino* create_pino() {
    Pino *p = malloc(sizeof(Pino));    
    p->v = malloc(MAX_SZ * sizeof(info_t));
    p->top = -1;
    
    return p;
}

Hanoi* create_hanoi(int qtdDisco) {
    if (qtdDisco <= 0) return NULL;
    
    Hanoi *h = malloc(sizeof(Hanoi));
    
    h->A = create_pino();
    h->B = create_pino();
    h->C = create_pino();
    
    inicio_jogo(h->A, qtdDisco);
    
    return h;
}

void free_hanoi(Hanoi *h) {
    free(h->A->v);
    free(h->A);
    free(h->B->v);
    free(h->B);
    free(h->C->v);
    free(h->C);
    free(h);
}