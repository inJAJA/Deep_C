// pointer
#include <stdio.h>
#include <stdlib.h>

int main() 
{
  int* a; // a를 주소(pointer)로 쓰겠다. 
          // 이 주소에는 int값을 넣겠다

  // *a = 3; // 초기값
    
  // printf("%p\n", a);  // *를 쓰면 &필요 x
  printf("%d\n", *a); // 주소에 들어가 있는 실제 값. 
                      // 초기엔 쓰레기 값 들어감

  return 0;
}
