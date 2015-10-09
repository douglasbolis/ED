/* Lista Encadeada Simples - Singled-linked List */

/* TAD -> ADT - Abstract Data Type */
#ifndef list_h
#define list_h

struct list;;
typedef struct list List;

List* create_list();

void insert_last(List*, int);

#endif	