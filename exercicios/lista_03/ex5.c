#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct elem {
	int x;
	char s[100];
	float f[50];
} Elem;

void insere_zero(Elem *el) {
	int i;

	el->x = 0;
	for(i = 0; i < 100; i++) {
		el->s[i] = 0;
	}
	for(i = 0; i < 50; i++) {
		el->f[i] = 0.0;
	}
}

void print_elem(Elem *e) {
  int i;
  printf("%d\n%s\n", e->x, e->s);
  for (i = 0; i < 50; i++) {
    if (e->f[i] != 0.0) {
      printf("%f ", e->f[i]);
    }
  }
  printf("\n");
}

// Funcao que testa se duas structs sao iguais.
bool compara(Elem *e1, Elem *e2) {
  int i;
  bool igual;

  i = 0;
  igual = e1->x == e1->x;

  if (igual) {
    igual = strcmp(e1->s, e2->s) == 0;
  }

  while (igual && i < 50) {
    igual = e1->f[i] == e2->f[i];
    i++;
  }

  return igual;
}

int main() {
	Elem e1, e2, e3;

	insere_zero(&e1);
	insere_zero(&e2);
	insere_zero(&e3);

	e1.x = 10;
	strcpy(e1.s, "Blah");
	e1.f[0] = 5.0;
	e1.f[1] = 4.2;

	e2.x = 10;
	strcpy(e2.s, "Blah");
	e2.f[0] = 5.0;
	e2.f[1] = 4.2;

	e3.x = 10;
	strcpy(e3.s, "Blah");
	e3.f[0] = 5.0;
	e3.f[1] = 7.2; // Aqui eh diferente.

	print_elem(&e1);
	print_elem(&e2);
	print_elem(&e3);

	if(compara(&e1, &e2)) {
		printf("\nElem E1 é igual a E2.\n");
	} else {
		printf("\nElem E1 é diferente que E2.\n");
	}

	if(compara(&e2, &e3)) {
		printf("\nElem E2 é igual a E3.\n");
	} else {
		printf("\nElem E2 é diferente que E3.\n");
	}

	return 0;
}