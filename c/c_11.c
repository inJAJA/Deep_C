#include <stdio.h>
#include <stdlib.h>

int main() 
{
  int* a = (int*)malloc(5 * sizeof(int)); // int* a = int *a 동일
  int* b = (int*)malloc(5 * sizeof(int)); 

  for (int i = 0; i < 5; i++){
    a[i] = 2 * i;
  } 

  for (int i = 0; i < 5; i++){
    b[i] = 2 * i + 1;
  }

  int* c = (int*)malloc(5 * sizeof(int));

  for (int j = 0; j < 5; j++){
    c[j] = a[j] + b[j];
    printf("%d\n", c[j]);
  }

  return 0;
}
