/*
    1861 - Hall of Murderers
    author: rodrig-crzz
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct NO
{
    char nome[15];
    int quant;
    bool vida;
    struct NO *esq;
    struct NO *dir;
} no;

void criarArvoreDeAssasinos(no **n, const char *nm)
{
    if(*n)
    {
        no *n0 = *n;
        int i = strcmp(n0->nome, nm);
        if(i > 0)
            criarArvoreDeAssasinos(&n0->esq, nm);
        else
        if(i < 0)
            criarArvoreDeAssasinos(&n0->dir, nm);
        else
            n0->quant++;
    }
    else
    {
        no *novo = (no *) malloc(sizeof(no));
        novo->esq = novo->dir = NULL;
        strcpy(novo->nome, nm);
        novo->quant = 1;
        novo->vida = true;
        *n = novo;
    }
}
void verificaVivos(no **n, const char *nm)
{
    if(*n)
    {
        no *n0 = *n;
        int i = strcmp(n0->nome, nm);
        if(i > 0)
            verificaVivos(&n0->esq, nm);
        else
        if(i < 0)
            verificaVivos(&n0->dir, nm);
        else
            n0->vida = false;
    }
}
void verificaMortos(const no *m, no **v)
{
    if(m)
    {
        verificaVivos(v, m->nome);
        verificaMortos(m->esq, v);
        verificaMortos(m->dir, v);
    }
}
void imprimirHall(const no *n)
{
    if(n)
    {
        imprimirHall(n->esq);
        if(n->vida)
            printf("%s %d\n", n->nome, n->quant);
        imprimirHall(n->dir);
    }
}

int main()
{
    no *assassinosVivos = NULL;
    no *assassinosMortos = NULL;
    char assassino[15];
    char assassinado[15];

    while(scanf("%s %s", assassino, assassinado) != EOF)
    {
        criarArvoreDeAssasinos(&assassinosVivos, assassino);
        criarArvoreDeAssasinos(&assassinosMortos, assassinado);
    }

    verificaMortos(assassinosMortos, &assassinosVivos);

    printf("HALL OF MURDERERS\n");
    imprimirHall(assassinosVivos);

    return 0;
}
