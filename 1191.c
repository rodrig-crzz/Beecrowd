/*  
    1191 - Tree Recovery
    author: rodrig-crzz
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NO
{
    char info;
    struct NO *esq;
    struct NO *dir;
} no;

void inserirNovoNo(no **n, const char i)
{
    no *novo = (no *) malloc(sizeof(no));
    novo->esq = novo->dir = NULL;
    novo->info = i;
    *n = novo;
}
void criarNo(no **n, const char *pre, const char *in)
{
    if(strlen(pre) == 0)
        return;

    inserirNovoNo(n, pre[0]);

    int i, j;
    char novoPre[100];
    char novoIn[100];

    for(i = 0 ; in[i] != pre[0] ; i++)
        novoIn[i] = in[i];
    for(j = 0 ; j < i ; j++)
        novoPre[j] = pre[j+1];
    
    novoPre[i] = novoIn[i] = '\0';

    no *n0 = *n;

    criarNo(&n0->esq, novoPre, novoIn);

    i++;
    for(j = 0 ; j < strlen(pre)-i ; j++)
        novoPre[j] = pre[i+j];
    for(int k = 0 ; k < j ; k++)
        novoIn[k] = in[i+k];
    novoPre[j] = novoIn[j] = '\0';

    criarNo(&n0->dir, novoPre, novoIn);
}
void imprimirPosfixo(const no *n)
{
    if(n)
    {
        imprimirPosfixo(n->esq);
        imprimirPosfixo(n->dir);
        printf("%c", n->info);
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
    no *arvore;
    char pre[100];
    char in[100];

    while(scanf("%s %s", pre, in) != EOF)
    {
        criarNo(&arvore, pre, in);
        imprimirPosfixo(arvore);
        limparArvore(&arvore);
        printf("\n");
    }
    return 0;
}
