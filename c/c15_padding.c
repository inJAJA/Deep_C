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

    int *x = (int*)calloc(4 * 4 , sizeof(int)); // padding 후 conv계산
    int *k = (int*)malloc(2* 2 * sizeof(int));
    int *b = (int*)malloc(2 * sizeof(int));

    int *o = (int*)malloc(3 * 3 * sizeof(int)); // calloc : 메모리를 할당하고 0으로 초기화

    printf("\no : ");                   
    for (int i = 0; i < 9; i++){
        printf("%d\t", o[i]);
    }

    int num[9] = {1, 2, 3, 5, 3, 2, 2, 6, 3};
    int weight[4] = {1, 0, 0, 1};
    b[0] = 1;   // => *b = 1;
    b[1] = 3;   // => *(b+1) = 3;


    for (int h = 0;  h < 3; h++){      // input x 
        for (int w = 0; w < 3; w++){
            x[(h+1)*4 + (w+1)] = num[h*3 + w];
        }
    }

    // Padding
    printf("\ninput x\n");              // check input 'x'
    for (int ph = 0; ph < 4; ph++){
        for (int pw = 0; pw < 4; pw++){
            printf("%d\t", x[ph*4 + pw]);
        }
        printf("\n");
    }

    printf("\nkernel\n");
    for (int kh = 0; kh < 2; kh++){
        for (int kw = 0; kw < 2; kw++){
            k[kh*2 + kw] = weight[kh*2 + kw];
            printf("%d\t", k[kh*2 + kw]);
        }
        printf("\n");
    }

    printf("\nbias : %d\n", *b);
    
    // Conv
    for (int p = 0; p < 3; p++){            // output image height
        for (int q = 0; q < 3; q++){        // output image width
            int s = 0;
            for (int kh = 0; kh < 2; kh++){
                for (int kw = 0; kw < 2; kw++){
                    s += x[(p+kh)*4 + q+kw] * k[kh*2 + kw]; // 4 = input image_size, 2 = kernel_size
                }
            }
            o[p*3 + q] = s;       // 3 = output image_size
        }
    }

    printf("\nresult\n");
    for (int p = 0; p < 3; p++){
        for (int q = 0; q < 3; q++){
            printf("%d\t", o[p*3 + q]);
        }
        printf("\n");
    }


    // bias
    for (int p = 0; p < 3; p++){
        for (int q = 0; q < 3; q++){
            o[p*3 + q] += b[0];
        }
    }

    printf("\nresult with bias\n");
    for (int p = 0; p < 3; p++){
        for (int q = 0; q < 3; q++){
            printf("%d\t", o[p*3 + q]);
        }
        printf("\n");
    }

    
    // ᄁᆃᆨ 해줘야 한다!!!!!(습관 들이기)
   free(x);
   free(k);
   free(b);
   free(o);


}
