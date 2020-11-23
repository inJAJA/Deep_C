#include <stdio.h>

int add(int x, int y);  // 함수 선언
                        // 밑에서 사용하기 위해 미리 선언
int multiply(int x, int y);

int main(void) 
{
  int a = 3;    
  int b = 4;

  int c = add(a, b);

  int d = multiply(a, b);

  printf("%d\n", c);
  printf("%d\n", d);

  return 0;
}

// gcc main.c add.c multiply.c -o main
// ./main 