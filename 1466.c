/*
    1466 - Level Order Tree Traversal
    author: rodrig-crzz
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    struct no *esq;
    int info;
    int nivel;
    struct no *dir;
} no;

void inserir(no **n, const int i, const int j)
{
    if(!*n)
    {
        no *novo = (no *) malloc(sizeof(no));
        novo->esq = novo->dir =  NULL;
        novo->nivel = j;
        novo->info = i;
        *n = novo;
    }
    else
    {
        no *aux = *n;
        if(i < aux->info)
            inserir(&aux->esq, i, j+1);
        else
            inserir(&aux->dir, i, j+1);
    }
}
int altura(const no *n)
{
    if(n)
    {
        int e, d;
        e = altura(n->esq);
        d = altura(n->dir);
        if(e > d)
            return e+1;
        else
            return d+1;
    }
    return -1;
}
void limparArvore(no **n)
{
    if(*n)
    {
        no *aux = *n;
        limparArvore(&aux->esq);
        limparArvore(&aux->dir);
        *n = NULL;
    }
}
void imprimirNo(const no* n, const int nv)
{
    if(n)
    {
        if(n->nivel < nv)
        {
            imprimirNo(n->esq, nv);
            imprimirNo(n->dir, nv);
        }
        else if(n->nivel == nv)
            printf(" %d", n->info);
    }
}
void imprimirPorNiveis(const no *n, const int a)
{
    if(n)
    {
        printf("%d", n->info);
        for(int i = 2 ; i <= a+1 ; i++)
        {
            imprimirNo(n->esq, i);
            imprimirNo(n->dir, i);
        }
    }
}

int main()
{
    no *arvore = NULL;
    int casos;
    int quantElementos;
    int elemento;

    scanf("%d", &casos);

    for(int i = 1 ; i <= casos ; i++)
    {
        scanf("%d", &quantElementos);
        
        while(quantElementos--)
        {
            scanf("%d", &elemento);
            inserir(&arvore, elemento, 1);
        }

        printf("Case %d:\n", i);
        imprimirPorNiveis(arvore, altura(arvore));
        printf("\n\n");
        
        limparArvore(&arvore);
    }
}
