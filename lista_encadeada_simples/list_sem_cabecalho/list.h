/* Lista Encadeada Simples - Singled-linked List */

/* TAD -> ADT - Abstract Data Type */
#ifndef list_h
#define list_h

struct cell;

typedef struct cell Cell;
typedef Cell List;

Cell* create_cell(int info) ;

List* insert_first(List* lst, int info);

List* create_list();

void print_list(List* lst);

void print_cell(Cell* c);

void free_list(List* lst);

void free_cell(Cell* c);

#endif	