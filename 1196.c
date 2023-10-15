/*
    1196 - WERTYU
    author: rodrig-crzz
*/
#include <stdio.h>

const char _wertyu[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
char substitution(char _i);

int main(void)
{
    char _input;

    while(scanf("%c", &_input) != EOF)
        printf("%c", substitution(_input));

    return 0;
}

char substitution(char _i)
{
    if(_i == ' ')
        return ' ';
    int i = 0;
    do
    {
        if(_i == _wertyu[i])
            return _wertyu[i-1];
    } while(_wertyu[++i] != '\0');
    return _i;
}
