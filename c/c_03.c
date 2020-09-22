#include <stdio.h>

int main(void) 
{
  for (int i = 0; i < 5; i++) {
    if (i % 2 ==0) {
      printf("%d\n", i);
    }
    else {
        printf("odd\n");
    }
  }
  return 0;
}
