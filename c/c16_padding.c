#include <stdio.h>
#include <stdlib.h>

int main()
{   
    // TensorFlow
    // 먼저 padding 후 Conv계산
    // 오른쪽 상단부터 padding

    // Conv layer output_size = ( W - F + 2*P) / S + 1
    // W : image_width
    // F : Filter width
    // P : Padding size
    // S : Stride number

    int *x = (int*)calloc(7 * 7, sizeof(int));
    int *k = (int*)malloc(3 * 3 *sizeof(int));
    int *b = (int*)malloc(1 * sizeof(int));

    int *o = (int*)malloc(5 * 5 *sizeof(int)); // calloc : 메모리를 할당하고 0으로 초기화

    int num[5 * 5] = {1, 2, 3, 5, 3, 2, 2, 6, 3, 1, 2, 3, 5, 3, 2, 2, 6, 3, 1, 2, 3, 5, 3, 2, 2};
    int weight[3 * 3] = {1, 0, 1, 0, 1, 1, 0, 0, 1};
    b[0] = 1;   // => *b = 1;


    // check num
    printf("num\n");
    for (int h = 0; h < 5; h++){
        for (int w = 0; w < 5; w++){
            printf("%d\t", num[h*5 +w]);
        }
        printf("\n");
    }

    // Padding
    for (int h = 0; h < 5; h++){
        for (int w = 0; w < 5; w++){
            x[(h+1)*7 + (w+1)] = num[h*5 + w];  // 7 = padding 후 image size
        }
    }

    // check input x
    printf("\ninput x\n");
    for (int ph = 0; ph < 7; ph++){         // ph : padding 후 height
        for (int pw = 0; pw < 7; pw++){     // pw : padding 후 widht
            printf("%d\t", x[ph*7 + pw]);
        }
        printf("\n");
    }
   
    printf("\nweight\n");
    for (int kh = 0; kh < 3; kh++){
        for (int kw = 0; kw < 3; kw++){
            k[kh*3 + kw] = weight[kh*3 + kw];
            printf("%d\t", k[kh*3 + kw]);
        }   
        printf("\n");
    }
    
    printf("\nbias : %d\n", *b);
    
    // Conv
    for (int p = 0; p < 5; p++){                        //  p = output image height
        for (int q = 0; q < 5; q++){                    //  q = output image width
            int s = 0;
            for (int kh = 0; kh < 3; kh++){
                for (int kw = 0; kw < 3; kw++){
                    s += x[(p+kh)*7 + q+kw]  *k[kh*3 + kw]; // 7 = input image_size, 3 = kernel_size
                }
            }
            o[p*5 + q] = s;       // 5 = output image_size
        }
    }

    printf("\nresult\n");
    for (int p = 0; p < 5; p++){
        for (int q = 0; q < 5; q++){
            printf("%d\t", o[p*5 +q]);
        }
        printf("\n");
    }


    // bias
    for (int p = 0; p < 5; p++){
        for (int q = 0; q < 5; q++){
            o[p*5 + q] += b[0];
        }
    }

    printf("\nresult with bias\n");
    for (int p = 0; p < 5; p++){
        for (int q = 0; q < 5; q++){
            printf("%d\t", o[p*5 + q]);
        }
        printf("\n");
    }

    
    // ᄁᆃᆨ 해줘야 한다!!!!!(습관 들이기)
   free(x);
   free(k);
   free(b);
   free(o);
    
}
