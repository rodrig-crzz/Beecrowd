/*
    1142 - PUM
    author: rodrig-crzz
*/
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1, j = 0 ; j < n ; j++, i += 4)
        printf("%d %d %d PUM\n", i, i+1, i+2);
    return 0;
}