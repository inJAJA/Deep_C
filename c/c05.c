#include <stdio.h>

int main(void) 
{
  int a[3][3] = {{1, 2, 3},{5, 3, 2},{2, 6, 3}};
  int b[2][2] = {{1, 0},{1, 1}};
  int c[2][2] = {{0, 0},{0, 0}};

  
  for (int h = 0; h < 2; h++){
    for (int w = 0; w < 2; w++){
      int s = 0;
      for (int kh = 0; kh < 2; kh++){
        for (int kw = 0; kw < 2; kw++){
          s += a[h+kh][w+kw] * b[kh][kw];
        }
      }
      c[h][w] = s;
      printf("%d\n", c[h][w]);
    }
  }

  for (int h = 0; h < 2; h++){
    for (int w = 0; w < 2; w++){
      printf("%d\n", c[h][w]);
    }
  }

  return 0;
}
