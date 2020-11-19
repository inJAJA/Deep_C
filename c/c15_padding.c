#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *x = (int*)malloc(9 * sizeof(int));
    int *c = (int*)malloc(4 * sizeof(int));
    int *b = (int*)malloc(2 * sizeof(int));

    int *o = (int*)calloc(9, sizeof(int));

    printf("\no : ");                   // calloc : 메모리를 할당하고 0으로 초기화
    for (int i = 0; i < 9; i++){
        printf("%d\t", o[i]);
    }

    int num[9] = {1, 2, 3, 5, 3, 2, 2, 6, 3};
    int w[4] = {1, 0, 0, 1};
    b[0] = 1;   // => *b = 1;
    b[1] = 3;   // => *(b+1) = 3;

    printf("\ninput x : ");
    for (int i = 0; i < 9; i++){
        x[i] = num[i];
        printf("%d\t", x[i]);
    }

    printf("\nweight : ");
    for (int i = 0; i < 4; i++){
        c[i] = w[i];
        printf("%d\t", c[i]);
    }

    printf("\nbias : %d\n", *b);
    
    for (int h = 0; h < 2; h++){
        for (int w = 0; w < 2; w++){
            int s = 0;
            for (int kh = 0; kh < 2; kh++){
                for (int kw = 0; kw < 2; kw++){
                    s += x[3*(h+kh)+w+kw]*c[2*kh+kw]; // 3 = input image_size, 2 = kernel_size
                }
            }
            o[3*h+w] = s;       // 3 = output image_size
        }
    }

    printf("\nresult : ");
    for (int i = 0; i < 9; i++){
        printf("%d\t", o[i]);
    }


    // bias
    for (int h = 0; h < 2; h++){
        for (int w = 0; w < 2; w++){
            o[3*h+w] += b[0];
        }
    }

    printf("\nresult with bias :");
    for (int i = 0; i < 9; i++){
        printf("%d\t", o[i]);
    }

    
    // ᄁᆃᆨ 해줘야 한다!!!!!(습관 들이기)
   free(x);
   free(c);
   free(b);
   free(o);


}
