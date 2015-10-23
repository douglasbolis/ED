#ifndef MY_STR_H
#define MY_STR_H

// Questão_1
struct string;

// Questão_2
typedef struct string String;

// Questão_3
String cria_string();

// Questão_4
void preenche_string(String*, char*, int);

// Questão_5
void imprime_string(String*);

// Questão_6
void free_string(String*);

// Questão_7
String concat_string(String*, String*);

#endif	