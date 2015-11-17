/* 
 * File:   libtrab2.h
 * Author: douglas
 */

#ifndef LIBTRAB2_H
#define	LIBTRAB2_H

typedef int info_t;
typedef struct pino Pino;
typedef struct hanoi Hanoi;

struct hanoi {
    Pino *A;
    Pino *B;
    Pino *C;
};

Hanoi* create_hanoi(int);

void resolve_jogo(int, Pino*, Pino*, Pino*, int);

void print_hanoi(Hanoi*);

void free_hanoi(Hanoi*);

void push_pino(Pino*, info_t);

info_t pop_pino(Pino*);

info_t peek_pino(Pino*);

int size_pino(Pino*);

void print_pino(Pino*);

#endif	/* LIBTRAB2_H */

