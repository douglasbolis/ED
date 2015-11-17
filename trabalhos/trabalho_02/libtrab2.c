/* 
 * File:   libtrab2.c
 * Author: douglas
 */

#include <stdio.h>
#include <stdlib.h>
#include "libtrab2.h"

#define MAX_SZ 30

// Implementação das estruturas utilizadas no jogo
struct pino {
    info_t *v;
    int top;
    char id;
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
    
    for (i = 0; i < size_pino(p); i++) {
        printf(" %d", p->v[i]);
    }
}

void print_hanoi(Hanoi *h) {
    printf("\n%4c:", h->A->id);
    print_pino(h->A);
    printf("\n%4c:", h->B->id);
    print_pino(h->B);
    printf("\n%4c:", h->C->id);
    print_pino(h->C);
    printf("\n");
}

void inicio_jogo(Pino *pino, int qtdDisco) {
    int i;
    
    for (i = qtdDisco; i > 0; i--) {
        push_pino(pino, i);
    }
}

Pino* create_pino() {
    Pino *p = malloc(sizeof(Pino));    
    p->v = malloc(MAX_SZ * sizeof(info_t));
    p->top = -1;
    
    return p;
}

Hanoi* create_hanoi(int qtdDisco) {
    if (qtdDisco <= 3 || qtdDisco > MAX_SZ) return NULL;
    
    Hanoi *h = malloc(sizeof(Hanoi));
    
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
    free(h->A->v);
    free(h->A);
    free(h->B->v);
    free(h->B);
    free(h->C->v);
    free(h->C);
    free(h);
}

void resolve_jogo(int n, Pino *orig, Pino *dest, Pino *aux, int verboso) {
    if (n == 0) return ;
    
    resolve_jogo(n-1, orig, aux, dest, verboso);    
    push_pino(dest, pop_pino(orig));    
    if (verboso) printf("\n%7s disk %d from %c to %c", "Move", n, orig->id, dest->id);
    resolve_jogo(n-1, aux, dest, orig, verboso);         
}