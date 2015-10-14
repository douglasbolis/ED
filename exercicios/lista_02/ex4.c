#include <stdio.h>

#define LINHAS 5
#define COLS 4

int main() {
  int m[LINHAS][COLS];
  int *p;
  int i, j;

  p = m[0];

  for (i = 0; i < LINHAS * COLS; i++) {
    *p = i;
    p++;
  }

  for (i = 0; i < LINHAS; i++){
  	printf("|");
    for (j = 0; j < COLS; j++){
      printf("%2d |", m[i][j]);
    }
    printf("\n");
  }

  return 0;
}