/* Lista Encadeada Simples - Singled-linked List */

/* TAD -> ADT - Abstract Data Type */

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

struct cell;
typedef struct cell Cell;
struct cell {
	int info;
	struct cell *next;
};

struct list {
	int size;
	Cell* first, last;
};

List* creat_list() {
	List *lst = (List*)malloc(sizeof(List));
	lst->size = 0;
	lst->fisrt = lst->last = NULL;
	return lst;
}

int size_list(List* lst) {
	return lst->size;
}

void insert_last(List* lst, int info) {
	Cell* new = create_cell(info);

	if(size_list(lst) == 0) {
		lst->first = lst->last = new;
		lst->size++;
		return;
	}

	lst->lst->next = new;
	lst->last = new;
}

int lookup_list(List* lst, int info) {
	Cell* c = lst->fisrt;
	int i = 0;

	while(c!- NULL) {
		if (c->info == info) {
			return i;
		}
		c = c->next;
		i++;
	}

	return -1;
}

void remove_list(List* lst, int pos) {
	int i = 0;

	Cell* c = lst->first;
	Cell* t = NULL;

	while(i < pos) {
		t = c;
		c = c->next;
		i++;
	}

	if (t == NULL) {
		lst->first = c->next;
	} else {
		t->next = c->next;
	}

	if (lst->last == c) {
		lst->last = t;
	}

	free_cell(c);
	lst->size--;
}