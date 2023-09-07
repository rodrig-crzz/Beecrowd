/*
    1340 - I Can Guess the Data Structure!
    author: rodrig-crzz
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct pilha
{
    int info;
    struct pilha* ant;
} variavelPilha;
typedef struct
{
    variavelPilha* topo;
} estruturaPilha;
typedef struct fila
{
    int info;
    struct fila* prox;
} variavelFila;
typedef struct
{
    variavelFila* inicio;
    variavelFila* fim;
} estruturaFila;

void push(estruturaPilha* p, int i)
{
    variavelPilha* novo = (variavelPilha*) malloc(sizeof(variavelPilha));
    novo->info = i;
    novo->ant = p->topo;
    p->topo = novo;
}
void pop(estruturaPilha* p)
{
    variavelPilha* temp = p->topo;
    p->topo = p->topo->ant;
    free(temp);
}
void enfileirar(estruturaFila* f, int i)
{
    variavelFila* novo = (variavelFila*) malloc(sizeof(variavelFila));
    novo->info = i;
    novo->prox = NULL;
    if(f->inicio == NULL)
        f->inicio = novo;
    else
        f->fim->prox = novo;
    f->fim = novo;
}
void enfileirarNaPrioridade(estruturaFila* f, int i)
{
    variavelFila* ant;
    variavelFila* aux;
    variavelFila* novo = (variavelFila*) malloc(sizeof(variavelFila));
    novo->info = i;
    novo->prox = NULL;
    if(f->inicio == NULL)
    {
        f->inicio = novo;
        f->fim = novo;
        return;
    }
    else if(novo->info >= f->inicio->info)
    {
        novo->prox = f->inicio;
        f->inicio = novo;
        return;
    }
    else
    {
        ant = NULL;
        aux = f->inicio;
        for( ; aux ; ant = aux, aux = aux->prox)
            if(novo->info >= aux->info)
            {
                ant->prox = novo;
                novo->prox = aux;
                return;
            }
    }
    f->fim->prox = novo;
    f->fim = novo;
}
void desenfileirar(estruturaFila* f)
{
    variavelFila* temp = f->inicio;
    f->inicio = f->inicio->prox;
    if(f->inicio == NULL)
        f->fim = NULL;
    free(temp);
}

int main()
{
    estruturaPilha pilha;
    estruturaFila fila;
    estruturaFila filaPrioritaria;
    int Nlinhas;
    int comando;
    int elemento;
    bool VerifPilha;
    bool VerifFila;
    bool VerifFilaPrioritaria;

    while(scanf("%i", &Nlinhas) != EOF)
    {
        pilha.topo = NULL;
        fila.inicio = fila.fim = NULL;
        filaPrioritaria.inicio = filaPrioritaria.fim = NULL;

        VerifPilha = VerifFila = VerifFilaPrioritaria = true;

        while(Nlinhas--)
        {
            scanf("%i %i", &comando, &elemento);

            switch(comando)
            {
                case 1:
                    push(&pilha, elemento);
                    enfileirar(&fila, elemento);
                    enfileirarNaPrioridade(&filaPrioritaria, elemento);
                break;
                case 2:
                    if(pilha.topo && pilha.topo->info == elemento)
                        pop(&pilha);
                    else
                        VerifPilha = false;

                    if(fila.inicio && fila.inicio->info == elemento)
                        desenfileirar(&fila);
                    else
                        VerifFila = false;

                    if(filaPrioritaria.inicio && filaPrioritaria.inicio->info == elemento)
                        desenfileirar(&filaPrioritaria);
                    else
                        VerifFilaPrioritaria = false;
                break;
            }
        }

        if(!VerifPilha && !VerifFila && !VerifFilaPrioritaria)
            printf("impossible\n");
        else if(VerifPilha && VerifFilaPrioritaria)
            printf("not sure\n");
        else if(VerifPilha && VerifFila)
            printf("not sure\n");
        else if(VerifFilaPrioritaria && VerifFila)
            printf("not sure\n");
        else if(VerifFilaPrioritaria)
            printf("priority queue\n");
        else if(VerifFila)
            printf("queue\n");
        else if(VerifPilha)
            printf("stack\n");
    }

    return 0;
}