/* 
 * File:   main.c
 * Author: douglas
 */

#include <stdio.h>
#include <stdlib.h>
#include "libtrab2.h"

/*
 * 
 */
//int main(int argc, char** argv) {
int main() {      
    Hanoi *h = create_hanoi(3);
    /*
    printf("\nA:");
    print_pino(h->A);
    printf("\nB:");
    print_pino(h->B);
    printf("\nC:");
    print_pino(h->C);
    */
    /*
    if (argc == 2) {
    }
    */
    
    free_hanoi(h);

    return 0;
}