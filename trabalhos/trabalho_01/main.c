#include "libtrab1.h"
#include <stdio.h>
#include <stdlib.h>

Mat* busca_arquivo(Mat *matriz, char nomeArq[]) {
    int dim, lin, col;
    float info;
    
    FILE *arquivo = fopen(nomeArq, "r");

// Verifica se retornou nulo ao abrir o arquivo.
    if (arquivo){
        fscanf(arquivo, "%d\n", &dim);
        matriz = cria_matriz(dim);

        while (!feof(arquivo)) {
            fscanf(arquivo, "%d;%d;%g\n", &lin, &col, &info);
            insere_celula(matriz, lin, col, info);
        }
    }
    fclose(arquivo);
    
    return matriz;
}
int main(int argc, char **argv) {
    
// Verificando quantidade de arquivos na chamada de execução no terminal.
    if (argc != 3) {
        printf("ERROR!\nQuantidade de arquivos diferente do esperado.\n");
    } else {
        Mat *matrizA = NULL;
        Mat *matrizB = NULL;
        Mat *matrizC = NULL;
        
        matrizA = busca_arquivo(matrizA, argv[1]);        
        matrizB = busca_arquivo(matrizB, argv[2]);
	
        matrizC = soma_matriz(matrizA, matrizB);
        
        desaloca_matriz(matrizA);
        desaloca_matriz(matrizB);

	imprime_matriz(matrizC);
        
        desaloca_matriz(matrizC);
    }

    return 0;
}