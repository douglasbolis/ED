/* Lista Encadeada Simples - Singled-linked List */

/* TAD -> ADT - Abstract Data Type */

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

struct cell {
	int info;
	struct cell *next;
};

typedef struct cell Cell;
typedef Cell List;

Cell* create_cell(int info) {
	Cell *c = (Cell*)malloc(sizeof(Cell));
	c->info = info;
	c->next = NULL;
	return c;
}

List* insert_first(List* lst, int info) {
	Cell *new = create_cell(info);
	new->next = lst;
	lst = new;
	return lst;
}

List* create_list() {
	return NULL;
}

void print_list(List* lst) {
	Cell *c = lst;

	while(c != NULL) {
		print_cell(c);
		c = c->next;
	}
}

void print_cell(Cell* c) {
	printf("%d\n", c->info);
}

void free_list(List* lst) {
	Cell *c = lst;

	while(c != NULL) {
		Cell *next = c->next;
		free_cell(c);
		c = next;
	}
}

void free_cell(Cell* c) {
	free(c);
}