#include <stdio.h>

void calcula(float l, float *area, float *perimetro) {
	*area = l*l;
	*perimetro = l*4;
}

int main() {
	float lado, area, perimetro;

	lado = 2.7;

	calcula(lado, &area, &perimetro);

	printf("\nLado: %.2f", lado);
	printf("\nArea: %.2f", area);
	printf("\nPerimetro: %.2f\n", perimetro);

	return 0;
}