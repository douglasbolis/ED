/* 
 * File:   libtrab2.h
 * Author: douglas
 */

#ifndef LIBTRAB2_H
#define	LIBTRAB2_H

// Definindo novos tipos para o programa.
typedef int info_t;
typedef struct pino Pino;
typedef struct hanoi Hanoi;

// Definindo a estrutura para a 'Torre de Hanoi'.
struct hanoi {
    Pino *A;
    Pino *B;
    Pino *C;
};

// Função para criar e retornar uma estrutura do tipo Hanoi*.
Hanoi* create_hanoi(int);

// Nesta função fica concentrada todo os movimentos do jogo.
void resolve_jogo(int, Pino*, Pino*, Pino*, int);

// Imprime os pinos com seus discos da torre.
void print_hanoi(Hanoi*);

// Libera todos os espaços de memória alocados dinamicamente que a torre
// possui(incluindo seus pinos e os vetores dos pinos).
void free_hanoi(Hanoi*);

// Insere um disco no topo do pino.
void push_pino(Pino*, info_t);

// Remove um disco do topo do pino.
info_t pop_pino(Pino*);

// Consulta o disco que está no topo do pino.
info_t peek_pino(Pino*);

// Retorna a quantidade de discos que o pino possui.
int size_pino(Pino*);

// Imprime os discos que o pino possui.
void print_pino(Pino*);

#endif	/* LIBTRAB2_H */

