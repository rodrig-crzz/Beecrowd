/*
    1463 - Binary Expression Tree
    author: rodrig-crzz
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NO
{
    char info;
    bool preferencia;
    struct NO *esq;
    struct NO *dir;
} no;

void inserirOperando(no **n, const char i)
{
    if(!*n)
    {
        no *novo = (no *) malloc(sizeof(no));
        novo->esq = novo->dir = NULL;
        novo->info = i;
        novo->preferencia = false;
        *n = novo;
    }
    else
    {
        no *n0 = *n;
        if(!n0->esq)
            inserirOperando(&n0->esq, i);
        else
            inserirOperando(&n0->dir, i);
    }
}
void inserirSoma(no **n, const char i)
{
    no *novo = (no *) malloc(sizeof(no));
    novo->esq = *n;
    novo->dir = NULL;
    novo->info = i;
    *n = novo;
}
void inserirMultiplicacao(no **n, const char i)
{
    no *n0 = *n;
    no *novo = (no *) malloc(sizeof(no));
    novo->dir = NULL;
    novo->info = i;
    if((n0->info == '+' || n0->info == '-') && !n0->preferencia)
    {
        novo->esq = n0->dir;
        n0->dir = novo;
    }
    else
    {
        novo->esq = *n;
        *n = novo;
    }
}
void inserirParenteses(no **n)
{
    no *subArvore = NULL;
    char aux;
    while(scanf("%c", &aux) && aux != ')')
    {
        if( (aux >= '0' && aux <= '9')||
            (aux >= 'a' && aux <= 'z')||
            (aux >= 'A' && aux <= 'Z'))
            inserirOperando(&subArvore, aux);
        else
        if(aux == '+' || aux == '-')
            inserirSoma(&subArvore, aux);
        else
        if(aux == '*' || aux == '/')
            inserirMultiplicacao(&subArvore, aux);
    }
    subArvore->preferencia = true;
    if(!*n)
        *n = subArvore;
    else
    {
        no *n0 = *n;
        while(n0->esq && n0->dir)
            n0 = n0->dir;
        if(!n0->esq)
            n0->esq = subArvore;
        else
            n0->dir = subArvore;

    }
}
void imprimirPorNiveis(const no *n, const int nv0, const int nv1)
{
    if(n)
    {
        if(nv0 < nv1)
        {
            imprimirPorNiveis(n->esq, nv0+1, nv1);
            imprimirPorNiveis(n->dir, nv0+1, nv1);
        }
        else
        if(nv0 == nv1)
            printf("%c", n->info);
    }
}
int alturaArvore(const no *n)
{
    if(n)
    {
        int e, d;
        e = alturaArvore(n->esq);
        d = alturaArvore(n->dir);
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
        no *n0 = *n;
        limparArvore(&n0->esq);
        limparArvore(&n0->dir);
        *n = NULL;
    }
}

int main()
{
    no *arvore = NULL;
    char aux;
    int altura;
    bool _n = false;

    while(scanf("%c", &aux) != EOF)
    {
        if(_n)
        {
            printf("\n");
            _n = false;
        }
        if( (aux >= '0' && aux <= '9')||
            (aux >= 'a' && aux <= 'z')||
            (aux >= 'A' && aux <= 'Z'))
            inserirOperando(&arvore, aux);
        else
        if(aux == '+' || aux == '-')
            inserirSoma(&arvore, aux);
        else
        if(aux == '*' || aux == '/')
            inserirMultiplicacao(&arvore, aux);
        else
        if(aux == '(')
            inserirParenteses(&arvore);
        else
        if(aux == '\n')
        {
            altura = alturaArvore(arvore);
            for(int i = 0 ; i <= altura ; i++)
            {
                printf("Nivel %d: ", i);
                imprimirPorNiveis(arvore, 0, i);
                printf("\n");
            }
            _n = true;
            limparArvore(&arvore);
        }
    }
    return 0;
}
