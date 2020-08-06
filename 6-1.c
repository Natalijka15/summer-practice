#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define K 6
#define N 5

int main(int argc, char *argv[]) {
  int a[K][N], *max;
  int i, j, k;

  srand(time(NULL));

  printf("Votes:\n");
  for (i = 0; i < K; i++) {
    for (j = 0; j < N; j++) {
      a[i][j] = rand() % 121;
      printf("%d\t", a[i][j]);
    }
    printf("\n");
  }
  printf("\n");


  max = malloc((K * N) * (sizeof *max));
  if (!max) return 1;
  k = 0;
  for (i = 0; i < K; i++) {
    for (j = 0; j < N; j++) {
      if (a[i][j] == 120)
        max[k++] = j;
    }
  }
  
  printf("Max:\n");
  max = realloc(max, k * (sizeof *max));
  if (!max) return 1;
  for (i = 0; i < k; i++)
    printf("%d\t", max[i]);
  printf("\n");

  return 0;
}