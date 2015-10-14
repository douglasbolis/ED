#include <stdio.h>

void swap(int *a, int *b) {
	int i;

	i = *a;
	*a = *b;
	*b = i;
}

int main() {
	int a, b;

	a = 12;
	b = 24;

	printf("Original:\nA: %d\n", a);
	printf("B: %d\n", b);

	swap(&a, &b);

	printf("\n\nAlterado:\nA: %d\n", a);
	printf("B: %d\n", b);

	return 0;
}