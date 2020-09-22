#include <stdio.h>

int main(void) 
{
  int a[5] = {1, 2, 3, 4, 5}; // 5개짜리 array(배열)

  for (int i = 0; i < 5; i++) {
    printf("a: %d\n", a[i]);
  }

  for (int i = 0; i < 5; i++) {
  printf("a: %p\n", &a[i]); // int는 4byte여서 주소 4씩 증가, str는 1byte
  }
}


