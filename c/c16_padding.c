#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *x = (int*)malloc(25 * sizeof(int));
    int *c = (int*)malloc(9 * sizeof(int));
    int *b = (int*)malloc(1 * sizeof(int));

    int *o = (int*)calloc(25, sizeof(int));

    printf("\no : ");                   // calloc : 메모리를 할당하고 0으로 초기화
    for (int i = 0; i < 9; i++){
        printf("%d\t", o[i]);
    }

    int num[25] = {1, 2, 3, 5, 3, 2, 2, 6, 3, 1, 2, 3, 5, 3, 2, 2, 6, 3, 1, 2, 3, 5, 3, 2, 2};
    int w[9] = {1, 0, 1, 0, 1, 1, 0, 0, 1};
    b[0] = 1;   // => *b = 1;

    printf("\ninput x : ");
    for (int i = 0; i < 25; i++){
        x[i] = num[i];
        printf("%d\t", x[i]);
    }

    printf("\nweight : ");
    for (int i = 0; i < 9; i++){
        c[i] = w[i];
        printf("%d\t", c[i]);
    }

    printf("\nbias : %d\n", *b);
    
    // conv_padding
    for (int h = 0; h < 3; h++){                       //  3 = feature_size
        for (int w = 0; w < 3; w++){
            int s = 0;
            for (int kh = 0; kh < 3; kh++){
                for (int kw = 0; kw < 3; kw++){
                    s += x[5*(h+kh)+w+kw]*c[3*kh+kw]; // 3 = input image_size, 2 = kernel_size
                }
            }
            o[5*(h+1)+w+1] = s;       // 5 = output image_size, 1 = padding
        }
    }

    printf("\nresult\n");
    for (int h = 0; h < 5; h++){
        for (int w = 0; w < 5; w++){
            printf("%d\t", o[5*h+w]);
        }
        printf("\n");
    }


    // bias
    for (int h = 0; h < 3; h++){
        for (int w = 0; w < 3; w++){
            o[5*(h+1)+w+1] += b[0];
        }
    }

    printf("\nresult with bias\n");
    for (int h = 0; h < 5; h++){
        for (int w = 0; w < 5; w++){
            printf("%d\t", o[5*h+w]);
        }
        printf("\n");
    }

    
    // ᄁᆃᆨ 해줘야 한다!!!!!(습관 들이기)
   free(x);
   free(c);
   free(b);
   free(o);


}
