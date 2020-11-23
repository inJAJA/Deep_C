#include <stdio.h>
#include <stdlib.h>

int main()
{   
    // Pytorch 
    // (1, 3, 5, 5) -> (1, 1, 5, 5)

    int *x = (int*)calloc(3 * 7 * 7, sizeof(int)); // padding // calloc : 메모리를 할당하고 0으로 초기화
    int *k = (int*)malloc(3 * 3 * 3 * sizeof(int));
    int *b = (int*)malloc(3 * 1 * sizeof(int));

    int *o = (int*)malloc(1 * 5 * 5 * sizeof(int)); 

    // data (N, C, H, W) = (1, 3, 3, 3)
    int num[3*5*5] = {1, 2, 3, 5, 3, 2, 2, 6, 3, 1, 2, 3, 5, 3, 2, 2, 6, 3, 1, 2, 3, 5, 3, 2, 2,
                      3, 2, 2, 6, 3, 1, 2, 3, 5, 3, 2, 2, 1, 2, 3, 5, 3, 2, 2, 6, 3, 1, 2, 3, 5,
                      6, 3, 1, 2, 3, 5, 3, 2, 2, 1, 2, 3, 5, 3, 2, 2, 3, 2, 2, 6, 3, 1, 2, 3, 5};
    int weight[3*3*3] = {1, 0, 1, 0, 1, 1, 0, 0, 1,
                         0, 1, 0, 1, 0, 1, 1, 1, 0,
                         1, 1, 0, 0, 1, 0, 0, 1, 0};
    int bias[3 * 1] = {1, 1, 1};   // => *b = 1;                  // batch 하나당 bias 하나

    // Padding
    for (int c = 0; c < 3; c++){
        for (int h = 0; h < 5; h++){
            for (int w = 0; w < 5; w++){
                x[c*7*7 + (h+1)*7 + (w+1)] = num[c*5*5 + h*5 + w]; // 1 = padding
            }
        }
    }

    // check input x
    printf("\ninput x\n");
    for (int c = 0; c < 3; c++){                // channel
        printf("--------------%d\n", c);
        for (int ph = 0; ph < 7; ph++){
            for (int pw = 0; pw < 7; pw++){
                printf("%d\t", x[c*7*7 + ph*7 + pw]);
            }
            printf("\n");
        }
    }

    // weight
    printf("\nweight\n");
    for (int c = 0; c < 3; c++){
        printf("--------------%d\n", c);
        for (int kh = 0; kh < 3; kh++){
            for (int kw = 0; kw < 3; kw++){
                k[c*3*3 + kh*3 + kw] = weight[c*3*3 + kh*3 + kw];
                printf("%d\t", k[c*3*3 + kh*3 + kw]);
            }
            printf("\n");
        }
    }

    // bias
    printf("\nbias\n");
    for (int c = 0; c < 3; c++){
        b[c] = bias[c];
        printf("%d\n", b[c]);
    }

    // conv_padding_channel
    for (int p = 0; p < 5; p++){                        // p = output image height = feature height
        for (int q = 0; q < 5; q++){                    // q = output image width = feature width
            int s = 0;
            for (int c = 0; c < 3; c++){                // channel
                for (int kh = 0; kh < 3; kh++){
                    for (int kw = 0; kw < 3; kw++){
                    s += x[c*7*7 + (p+kh)*7 + q+kw]*k[c*3*3 + kh*3 + kw];   // 7 = input image_size, 3 = kernel_size
                    }
                }
                s += b[c];
                o[(p)*5 + q] = s;                         // 5 = output image_size
            }
        }
    }

    // result
    printf("\nresult\n");
    for (int p = 0; p < 5; p++){
        for (int q = 0; q < 5; q++){
            printf("%d\t", o[p*5 +q]);
        }
        printf("\n");
    }
    
    
    // ᄁᆃᆨ 해줘야 한다!!!!!(습관 들이기)
   free(x);
   free(k);
   free(b);
   free(o);


}
