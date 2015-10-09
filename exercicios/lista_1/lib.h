#ifndef LIB_H
#define LIB_H

/* Ex1 */
void imprimeMedia(char* nome, float media);
float calculaMedia(float total, int qtd);

/* Ex2 */
int calculaExpo(int base, int expo);

/* Ex3 */
int* retiraNum(int* vet, int tam, int num);
void imprimeVetorInt(int* vet, int tam);

/* Ex4 */
void normaliza_matriz_float(float mat[3][3], int l, int c, float maiorValor);
void imprime_matriz_float(float mat[3][3], int l, int c);

/* Ex5 */
void inverte_linhas_int(int mat[4][2], int l, int c);
void imprime_matriz_int(int mat[4][2], int l, int c);

#endif	