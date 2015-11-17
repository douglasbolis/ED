/* 
 * File:   main.c
 * Author: douglas
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libtrab2.h"

/*
 * 
 */
int main(int argc, char** argv) {
    if (argc == 1) {
        printf("Parametros insuficiente.\n");
        return 0;
    }
    
    int n = atoi(argv[1]);
    Hanoi *h = create_hanoi(n);
    
    if (argc == 3 && strcmp(argv[2], "-v") == 0) {
        printf("=> Solving the Tower of Hanoi with %d disks.\n=> Initial configuration:", n);
        print_hanoi(h);
        printf("=> Moves:");
        resolve_jogo(n, h->A, h->C, h->B, 1);
        printf("\n=> Final configuration:");
        print_hanoi(h);
    }
    else resolve_jogo(n, h->A, h->C, h->B, 0);
    
    free_hanoi(h);

    return 0;
}