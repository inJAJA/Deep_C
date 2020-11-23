#include <stdio.h>
#include <stdlib.h>

void add_array(int* z, int* x, int* y, int length)
{
    for (int i = 0; i < length; i++){
        z[i] = x[i] + y[i];
  }
}

int main() 
{
    int* a = (int*)malloc(5 * sizeof(int)); // int* a = int *a 동일
    int* b = (int*)malloc(5 * sizeof(int)); 
    
    /*
    int l = 5;
    int* a = (int*)malloc(l * sizeof(int)); // malloc은 변수 사용 가능 
    int* b = (int*)malloc(l * sizeof(int));
    */
    
    // int f[l] = {1, 2, 3, 4, 5}; // 배열에서 변수 사용 불가
    
    for (int i = 0; i < 5; i++){
        a[i] = 2 * i;
    } 

    for (int i = 0; i < 5; i++){
        b[i] = 2 * i + 1;
    }

    int* c = (int*)malloc(5 * sizeof(int));

    add_array(c, a, b, 5);
    
    for (int i = 0; i < 5; i++){
        printf("%d\n", c[i]);
    }

    free(a);  // program이 끝나면 memory 날리기
    free(b);  // free안하고 끝내면 계속 남아 있음
    free(c);

    return 0;
}
/* 이런식으로 짜면 안좋다
int* add_array( int* x, int* y, int length)
{
  int* c =(int*)malloc(length * sizeof(int));   // 함수 안에서 정의 하면 코드를 관리할 때 불편하다.(메모리 할당 관리 불편)
                                                // main안에서만 관리해 주는 것이 안전하고 접근하기 편함

  for (int i = 0; i < length; i++){
    c[i] = x[i] + y[i];
  }
}
*/