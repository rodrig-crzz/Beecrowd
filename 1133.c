/*
    1133 - Rest of a Division
    author: rodrig-crzz
*/
#include <stdio.h>

void ordem(int *, int *);

int main()
{

    int x;
    int y;
    scanf("%i %i", &x, &y);

    ordem(&x, &y);  //organiza para x < y ou x == y

    for(int i = x+1 ; i < y ; i++)
        if(i % 5 == 2 || i % 5 == 3)
            printf("%i\n", i);

    return 0;
}

void ordem(int *a, int *b)
{
    if(*a > *b)
    {
        int temp = *b;
        *b = *a;
        *a = temp;
    }
}
