/*  
    1099 - Sum of Consecutive Odd Numbers II
    author: rodrig-crzz
*/

#include <stdio.h>

void organizar(int *, int *);

int main()
{
    int quant_test;
    int soma;
    int X;
    int Y;

    scanf("%i", &quant_test);

    while(quant_test--)
    {
        scanf("%i %i", &X, &Y);

        for(organizar(&X, &Y), soma = 0 , X++ ; X < Y ; X++)
            if(X % 2 == 1)
                soma += X;
        printf("%i\n", soma);
    }
    return 0;
}

void organizar(int *a, int *b)
{
    if(*a > *b)
    {
        int temp = *b;
        *b = *a;
        *a = temp;
    }
}
