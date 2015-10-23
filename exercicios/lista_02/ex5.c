#include <stdio.h>

#define SZ 5

void print(char *v) {
  int i;
  for (i = 0; i < SZ; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

void memcpy1(char* dest, const char* src, int count) {
  while (count--) *dest++ = *src++;
}

void memcpy2(char* dest, const char* src, int count) {
  while (count--) dest[count] = src[count];
}

int main() {
  char v[] = {2, 3, 4, 5, 6};
  char w[SZ];
  char u[SZ];

  memcpy1(w, v, SZ);
  printf("w: ");
  print(w);

  memcpy2(u, v, SZ);
  printf("u: ");
  print(u);

  return 0;
}