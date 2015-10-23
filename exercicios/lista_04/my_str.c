#include "my_str.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Questão_1
struct string {
	char v[];
	int size;
};

// Questão_2
typedef struct string String;

// Questão_3
String cria_string() {
	String str = malloc(sizeof(String));
	return str;
}

// Questão_4
void preenche_string(String *str, char *c, int len) {

}

// Questão_5
void imprime_string(String *str) {
	printf("\nString: %s\nTamanho: %d\n", str->v, str->size);
}

// Questão_6
void free_string(String *str) {
	free(str);
}

// Questão_7
String concat_string(String *str1, String *str2) {
	String new_string = cria_string();
	int i;

	for(i = 0; i < str1->size; i++) {
		new_string->v[i] = str1->v[i];
	}

	for(i = 0; i < str2->size; i++) {
		new_string->v[i] = str2->v[i];
	}

	return new_string;
}