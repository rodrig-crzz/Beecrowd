/*
    1581 - International Chat
    author: rodrig-crzz
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    int _n;
    scanf("%d", &_n);

    while(_n--)
    {
        int _k;
        char language[21];
        bool answer = true;

        scanf("%d", &_k);
        scanf("%s", language);

        while(--_k)
        {
            char temp[21];
            scanf("%s", temp);

            if(strcmp(language, temp) != 0)
                answer = false;
        }

        if(answer)
            printf("%s\n", language);
        else
            printf("ingles\n");
    }

    return 0;
}
