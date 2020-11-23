// pointer

#include <stdio.h>
#include <stdlib.h>

int main() 
{
  int* a = (int*)malloc(5 * sizeof(int)); 
                // memory locate : 메모리 할당
                // 4(int) * 5 byte를 할당
                // a[0], a[1] ... a[4] : 1개당 4byte
                
  for (int i = 0; i < 5; i++){
    printf("%d\n", a[i]); // array만 특별하게 실제값 반환
    printf("%p\n", &a[i]); // array만 특별하게 주소값 보려면 & 써야함
  }

  return 0;
}
