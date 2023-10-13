/*
    1028 - Collectable Cards
    author: rodrig-crzz
*/
#include <stdio.h>

int main(void)
{
    int _n;
    scanf("%d", &_n);

    while(_n--)
    {
        int f1;
        int f2;
        scanf("%d %d", &f1, &f2);

        while(f2 != 0)
        {
            int temp = f1 % f2;
            f1 = f2;
            f2 = temp;
        }

        printf("%d\n", f1);
    }

    return 0;
}
