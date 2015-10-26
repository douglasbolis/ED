/* Lista Encadeada Simples - Singled-linked List */

/* TAD -> ADT - Abstract Data Type */

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

struct cell;
typedef struct cell Cell;
struct cell {
	int info;
	Cell *next, *prev;
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
	int sizeList = size_list(lst);
	int realPos, i;

	if (sizeList == 0) return;

	if (pos < 0) realPos = 0;
	else if (pos > sizeList-1) realPos = size-1;
	else realPos = pos;

	Cell *c = lst->first;

	for(i = 0;i < realPos; c = c->next, i++);

	if (c == lst->last) {
		if (c->prev != NULL) c->prev->next = NULL;
		lst->last = c->prev;
	}

	if (c == lst->first) {
		if (c->next != NULL) c->next->prev = NULL;
		lst->first = c->next;
	}

	c->next->prev = c->prev;
	c->prev->next = c->next;

	free_cell(c);
	lst->size--;
}