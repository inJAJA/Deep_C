// C로 convolution, maxpooling 구현
#include <stdio.h>

int main()
{
  int image[5][5] = {{3, 2, 4, 5, 6},
                   {4, 5, 6, 1, 2},
                   {2, 3, 1, 0, 2},
                   {4, 2, 1, 4, 3},
                   {3, 4, 7, 2, 1},};

  int kernel[2][2] = {{1, 1},{0, 1}};

  int feature[4][4] = {{0, 0, 0, 0},
                      {0, 0, 0, 0},
                      {0, 0, 0, 0},
                      {0, 0, 0, 0}};

  int maxpool[2][2] = {{0, 0}, {0, 0}};

  // convolution 5*5 & 2*2
  for (int h = 0; h < 4; h++){
    for (int w = 0; w < 4; w++){
      int s = 0;
      for (int kh = 0; kh < 2; kh++){
        for (int kw = 0; kw < 2; kw++){
          s += image[h+kh][w+kw] * kernel[kh][kw];
        }
      }
    feature[h][w] = s;
    printf("%d\n", s);
    printf("---------\n");
    }
  }

// maxpooling
  for (int h = 0; h < 2; h++){
    for (int w = 0; w < 2; w++){
      int max = -(2^1000);
      for (int kh = 0; kh < 2; kh++){
        for (int kw =0; kw < 2; kw++){
          if (max < feature[h*2+kh][w*2+kw]){
            max = feature[h*2+kh][w*2+kw];
          }        
        }
      }
      maxpool[h][w] = max;
      printf("%d\n", max);
    }
  }
  return 0;
}
