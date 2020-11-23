#include <stdio.h>
#include <stdlib.h>

int main()
{   
    // Pytorch
    // (2, 3, 5, 5) -> (2, 1, 5, 5)

    // data
    int num[2 * 3 * 5 * 5] = {1, 2, 3, 5, 3, 2, 2, 6, 3, 1, 2, 3, 5, 3, 2, 2, 6, 3, 1, 2, 3, 5, 3, 2, 2,  // batch = 1
                        3, 2, 2, 6, 3, 1, 2, 3, 5, 3, 2, 2, 1, 2, 3, 5, 3, 2, 2, 6, 3, 1, 2, 3, 5,
                        6, 3, 1, 2, 3, 5, 3, 2, 2, 1, 2, 3, 5, 3, 2, 2, 3, 2, 2, 6, 3, 1, 2, 3, 5,
                        1, 2, 3, 5, 3, 2, 2, 6, 3, 1, 2, 3, 5, 3, 2, 2, 6, 3, 1, 2, 3, 5, 3, 2, 2,  // batch = 2
                        3, 2, 2, 6, 3, 1, 2, 3, 5, 3, 2, 2, 1, 2, 3, 5, 3, 2, 2, 6, 3, 1, 2, 3, 5,
                        6, 3, 1, 2, 3, 5, 3, 2, 2, 1, 2, 3, 5, 3, 2, 2, 3, 2, 2, 6, 3, 1, 2, 3, 5};
    int weight[2 * 3 * 3 * 3] = {1, 0, 1, 0, 1, 1, 0, 0, 1,     // batch = 1
                                0, 1, 0, 1, 0, 1, 1, 1, 0,
                                1, 1, 0, 0, 1, 0, 0, 1, 0,
                                1, 0, 1, 0, 1, 1, 0, 0, 1,      // batch = 2
                                0, 1, 0, 1, 0, 1, 1, 1, 0,
                                1, 1, 0, 0, 1, 0, 0, 1, 0};
    int bias[2 * 3 * 1] = {1, 3, 2, 1, 3, 2};   // => *b = 1; *(b+1) = 3;           // bias는 batch * channel 수 만큼 가진다.

    // 변수 
    int *x = (int*)calloc(2 * 3 * 7 * 7, sizeof(int)); // padding // calloc : 메모리를 할당하고 0으로 초기화
    int *k = (int*)malloc(2 * 3 * 3 * 3 * sizeof(int));
    int *b = (int*)malloc(2 * 3 * 1 * sizeof(int));

    int *y = (int*)malloc(2 * 1 * 5* 5 * sizeof(int)); 


    // Padding

    for (int n = 0; n < 2; n++){
        for (int c = 0; c < 3; c++){
            for (int h = 0; h < 5; h++){
                for (int w = 0; w < 5; w++){
                    x[n*3*7*7 + c*7*7 + (h+1)*7 + (w+1)] = num[n*3*5*5 + c*5*5 + h*5 + w]; // 7 = padding 후 image size  
                }
            }
        }
    }
    // 메모리 할당 방법
    // memcpy(x, num, 2*3*5*5*sizeof(int)); // memory copy : target = x, source = num, byte수

    // check input x
    printf("\ninput x\n");
    for (int n = 0; n < 2; n++){
        printf("batch : %d\n", n);
        for (int c = 0; c < 3; c++){
            printf("-------------- %d\n", c);
            for (int ph = 0; ph < 7; ph++){
                for (int pw = 0; pw < 7; pw++){
                    printf("%d\t", x[n*3*7*7 + c*7*7 + ph*7 + pw]);
                }
                printf("\n");
            }
        }
    }

    // kernel
    printf("\nweight\n");
    for (int n = 0; n < 2; n++){
        printf("batch : %d\n", n+1);
        for (int c = 0; c < 3; c++){
            printf("--------------%d\n", c);
            for (int kh = 0; kh < 3; kh++){
                for (int kw = 0; kw < 3; kw++){
                    k[n*3*3*3 + c*3*3 + kh*3 + kw] = weight[n*3*3*3 + c*3*3 + kh*3 + kw];
                    printf("%d\t", k[n*3*3*3 + c*3*3 + kh*3 + kw]);
                }
                printf("\n");
            }
        }
    }

    // bias
    printf("\nbias\n");
    for (int n = 0; n < 2; n++){
        for (int c = 0; c < 3; c++){
            b[n*3 + c] = bias[n*3 + c];
            printf("%d\n", b[n*3 + c]);
        }
    }

    // Conv
    printf("Conv\n");
    for (int n = 0; n < 2; n++){        // batch
        for (int p = 0; p < 5; p++){                        //  5 = output image size = feature_size
            for (int q = 0; q < 5; q++){
                int s = 0;
                for (int c = 0; c < 3; c++){                // 3 = channel
                    for (int kh = 0; kh < 3; kh++){
                        for (int kw = 0; kw < 3; kw++){
                            s += x[n*3*7*7 + c*7*7 + (p+kh)*7 + q+kw] * k[n*3*3*3 + c*3*3 + kh*3 + kw];   // 7 = input image_size, 3 = kernel_size
                        }   
                    }
                    s += b[n*3 + c];                        // bias 더하기
                    y[n*1*5*5 + p*5 + q] = s;               // 5 = output image_size, c = 1 이면 c는 계산 안함
                }
            }
        }
    }

    // result
    printf("\nresult\n");
    for (int n =0; n < 2; n++){
        printf("batch : %d\n", n+1);
        for (int p = 0; p < 5; p++){
            for (int q = 0; q < 5; q++){
                printf("%d\t", y[n*5*5 +p*5 + q]);
            }
            printf("\n");
        }
    }
      
    // ᄁᆃᆨ 해줘야 한다!!!!!(습관 들이기)
   free(x);
   free(k);
   free(b);
   free(y);


}
