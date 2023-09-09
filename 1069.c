/*
    1069 - Diamonds and Sand
    author: rodrig-crzz
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    char data;
    struct node *next;
} stackStructure;

void push(stackStructure **, char);
void pop(stackStructure **);
bool isEmpty(const stackStructure *);
void cleanStack(stackStructure **);

int main(void)
{
    int testCases;
    int amountDiamonds;
    char aux;
    stackStructure *stack = NULL;
    scanf("%d%*c", &testCases);

    while(testCases--)
    {
        amountDiamonds = 0;

        while(scanf("%c", &aux) && aux != '\n')
            if(aux == '<')
                push(&stack, '<');
            else if(aux == '>')
                if(!isEmpty(stack))
                {
                    pop(&stack);
                    amountDiamonds++;
                }

        cleanStack(&stack);
        printf("%d\n", amountDiamonds);
    }

    return 0;
}

void push(stackStructure **s, char d)
{
    stackStructure *new = (stackStructure *) malloc(sizeof(stackStructure));
    new->data = d;
    if(*s)
        new->next = *s;
    else
        new->next = NULL;
    *s = new;
}
void pop(stackStructure **s)
{
    if(!isEmpty(*s))
    {
        stackStructure *s0 = *s;
        *s = s0->next;
        free(s0);
    }
}
bool isEmpty(const stackStructure *s)
{
    if(s == NULL)
        return true;
    else
        return false;
}
void cleanStack(stackStructure **s)
{
    while(*s)
        pop(s);
}
