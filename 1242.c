/*
	1242 - Alien Ribonucleic Acid
	author: rodrig-crzz
*/
#include <stdio.h>
#include <stdlib.h>
#define size 300

typedef enum{false, true} bool;
typedef struct 
{
    int top;
    char arr[size];
} stack_struct;

stack_struct* create();
char peek(stack_struct* s);
void push(stack_struct* s, char v);
void pop(stack_struct* s);
void clean_stack(stack_struct* s);
bool isEmpty(stack_struct* s);
bool isFull(stack_struct* s);
bool verify_bases(char b1, char b2);

int main()
{
    stack_struct* stack = create();
    char rnaa[301];

    while(scanf("%300[^\n]%*c", rnaa) != EOF)
    {
        int count = 0;
        int i = 0;

        do
        {
            if(isEmpty(stack) == false && verify_bases(peek(stack), rnaa[i]))
            {
                pop(stack);
                count++;
            }
            else
                push(stack, rnaa[i]);
        } while(rnaa[++i] != '\0');

        clean_stack(stack);
        printf("%d\n", count);
    }

    return 0;
}

stack_struct* create()
{
    stack_struct* new = (stack_struct*) malloc(sizeof(stack_struct));
    new->top = -1;
    return new;
}
char peek(stack_struct* s)
{
    return s->arr[s->top];
}
void push(stack_struct* s, char v)
{
    if(isFull(s))
        return;
    s->top++;
    s->arr[s->top] = v;
}
void pop(stack_struct* s)
{
    if(isEmpty(s))
        return;
    s->top--;
}
void clean_stack(stack_struct* s)
{
    s->top = -1;
}
bool isEmpty(stack_struct* s)
{
    if(s->top == -1)
        return true;
    return false;
}
bool isFull(stack_struct* s)
{
    if(s->top == size-1)
        return true;
    return false;
}
bool verify_bases(char b1, char b2)
{
    if(b1 != b2)
    {
        if(b1 == 'B' || b1 == 'S')
            if(b2 == 'B' || b2 == 'S')
                return true;
        if(b1 == 'C' || b1 == 'F')
            if(b2 == 'C' || b2 == 'F')
                return true;
    }
    return false;
}
