/*
    1195 - Binary Search Tree
    author: rodrig-crzz
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct NO
{
    int info;
    struct NO *esq;
    struct NO *dir;
} no;

void inserir(no **n, const int i)
{
    if(!*n)
    {
        no *novo = (no *) malloc(sizeof(no));
        novo->esq = novo->dir = NULL;
        novo->info = i;
        *n = novo;
    }
    else
    {
        no *n0 = *n;
        if(i < n0->info)
            inserir(&n0->esq, i);
        else
            inserir(&n0->dir, i);
    }
}
void prefixo(const no *n)
{
    if(n)
    {
        printf(" %d", n->info);
        prefixo(n->esq);
        prefixo(n->dir);
    }
}
void infixo(const no *n)
{
    if(n)
    {
        infixo(n->esq);
        printf(" %d", n->info);
        infixo(n->dir);
    }
}
void posfixo(const no *n)
{
    if(n)
    {
        posfixo(n->esq);
        posfixo(n->dir);
        printf(" %d", n->info);
    }
}
void limparArvore(no **n)
{
    if(*n)
    {
        no *n0 = *n;
        limparArvore(&n0->esq);
        limparArvore(&n0->dir);
        *n = NULL;
    }
}

int main()
{
    no *arvore = NULL;
    int casos;
    int quantNos;
    int info;

    scanf("%d", &casos);

    for(int i = 1 ; i <= casos ; i++)
    {
        scanf("%d", &quantNos);

        while(quantNos--)
        {
            scanf("%d", &info);
            inserir(&arvore, info);
        }

        printf("Case %d:", i);
        printf("\nPre.:");
        prefixo(arvore);
        printf("\nIn..:");
        infixo(arvore);
        printf("\nPost:");
        posfixo(arvore);
        printf("\n\n");

        limparArvore(&arvore);
    }

    return 0;
}
