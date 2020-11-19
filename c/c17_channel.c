#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *x = (int*)malloc(3 * 25 * sizeof(int));
    int *k = (int*)malloc(3 *9 * sizeof(int));
    int *b = (int*)malloc(3 * 1 * sizeof(int));

    int *o = (int*)calloc(3 *25, sizeof(int));

    printf("\no : ");                   // calloc : 메모리를 할당하고 0으로 초기화
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d\t", o[3*i+j]);
        }
    }

    // data
    int num[3][25] = {{1, 2, 3, 5, 3, 2, 2, 6, 3, 1, 2, 3, 5, 3, 2, 2, 6, 3, 1, 2, 3, 5, 3, 2, 2},
                      {3, 2, 2, 6, 3, 1, 2, 3, 5, 3, 2, 2, 1, 2, 3, 5, 3, 2, 2, 6, 3, 1, 2, 3, 5},
                      {6, 3, 1, 2, 3, 5, 3, 2, 2, 1, 2, 3, 5, 3, 2, 2, 3, 2, 2, 6, 3, 1, 2, 3, 5}};
    int weight[3][9] = {{1, 0, 1, 0, 1, 1, 0, 0, 1},
                   {0, 1, 0, 1, 0, 1, 1, 1, 0},
                   {1, 1, 0, 0, 1, 0, 0, 1, 0}};
    int bias[3] = {1, 2, 3};   // => *b = 1;

    printf("\ninput x");
    for (int c = 0; c < 3; c++){
        printf("--------------%d\n", c);
        for (int h = 0; h < 5; h++){
            for (int w = 0; w < 5; w++){
                x[c*25+5*h+w] = num[c][5*h+w];
                printf("%d\t", x[c*25+5*h+w]);
            }
            printf("\n");
        }
    }

    printf("\nweight\n");
    for (int c = 0; c < 3; c++){
        printf("--------------%d\n", c);
        for (int h = 0; h < 3; h++){
            for (int w = 0; w < 3; w++){
                k[9*c+3*h+w] = weight[c][3*h+w];
                printf("%d\t", k[c*9+3*h+w]);
            }
            printf("\n");
        }
    }

    printf("\nbias\n");
    for (int c = 0; c < 3; c++){
        b[c] = bias[c];
        printf("%d\n", b[c]);
    }

    // conv_padding_channel
    for (int c = 0; c < 3; c++){                            // channel
        for (int h = 0; h < 3; h++){                        //  3 = feature_size
            for (int w = 0; w < 3; w++){
                int s = 0;
                for (int kh = 0; kh < 3; kh++){
                    for (int kw = 0; kw < 3; kw++){
                        s += x[c*25+5*(h+kh)+w+kw]*k[c*9+3*kh+kw];   // 3 = input image_size, 2 = kernel_size
                    }
                }
                o[c*25+5*(h+1)+w+1] = s;                         // 5 = output image_size, 1 = padding
            }
        }
    }

    // result
    printf("\nresult\n");
    for (int c = 0; c < 3; c++){
        printf("--------------%d\n", c);
        for (int h = 0; h < 5; h++){
            for (int w = 0; w < 5; w++){
                printf("%d\t", o[c*25+5*h+w]);
            }
            printf("\n");
        }
    }
    


    // bias
    for (int c = 0; c < 3; c++){
        for (int h = 0; h < 3; h++){
            for (int w = 0; w < 3; w++){
                o[c*25+5*(h+1)+w+1] += b[c];
            }
        }
    }

    // result with bias
    printf("\nresult with bias\n");
    for (int c = 0; c < 3; c++){
        printf("--------------%d\n", c);
        for (int h = 0; h < 5; h++){
            for (int w = 0; w < 5; w++){
                printf("%d\t", o[c*25+5*h+w]);
            }
            printf("\n");
        }
    }
    
    
    // ᄁᆃᆨ 해줘야 한다!!!!!(습관 들이기)
   free(x);
   free(k);
   free(b);
   free(o);


}
