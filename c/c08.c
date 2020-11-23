#include <stdio.h>
#include "header.h" // 함수 정의 파일, 내가 생성한 파일은 쌍따옴표("")
                    // header파일 안에 함수를 정의해 줘도 된다.(이럴 경우 다른 파일 필요 X)

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
