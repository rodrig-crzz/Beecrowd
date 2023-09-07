/*
	1201 - BST Operations II
	author: rodrig-crzz
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//variavel para auxiliar na correta impressao
bool pTermo;

typedef struct NO
{
	int info;
	struct NO *esq;
	struct NO *dir;
} no;

void inserir(no **n, const int i)
{
	if(*n == NULL)
	{
		no *novo = (no *) malloc(sizeof(no));
		novo->esq = novo->dir = NULL;
		novo->info = i;
		*n = novo;
	}
	else
	{
		no *aux = *n;
		if(i < aux->info)
			inserir(&aux->esq, i);
		else
			inserir(&aux->dir, i);
	}
}
void infixa(const no *n)
{
	if(n)
	{
		infixa(n->esq);
		if(pTermo)
		{
			printf("%d", n->info);
			pTermo = false;
		}
		else
			printf(" %d", n->info);
		infixa(n->dir);
	}
}
void prefixa(const no *n)
{
	if(n)
	{
		if(pTermo)
		{
			printf("%d", n->info);
			pTermo = false;
		}
		else
			printf(" %d", n->info);
		prefixa(n->esq);
		prefixa(n->dir);
	}
}
void posfixa(const no *n)
{
	if(n)
	{
		posfixa(n->esq);
		posfixa(n->dir);
		if(pTermo)
		{
			printf("%d", n->info);
			pTermo = false;
		}
		else
			printf(" %d", n->info);
	}
}
bool pesquisa(const no *n, const int i)
{
	if(n)
		if(n->info == i)
			return true;
		else
		if(pesquisa(n->esq, i))
			return true;
		else
		if(pesquisa(n->dir, i))
			return true;
	return false;
}
void remover(no **n, const int i)
{
    if(*n)
    {
        no *aux = *n;
        if(i < aux->info)
            remover(&aux->esq, i);
        else
        if(i > aux->info)
            remover(&aux->dir, i);
        else
        if(!aux->esq && !aux->dir)
        {
            *n = NULL;
            free(aux);
        }
        else
        if(!aux->esq)
        {
            *n = aux->dir;
            free(aux);
        }
        else
        if(!aux->dir)
        {
            *n = aux->esq;
            free(aux);
        }
        else
        {
            no *aux2 = aux->esq;
            while(aux2->dir)
                aux2 = aux2->dir;
            aux->info = aux2->info;
            aux2->info = i;
            remover(&aux->esq, i);
        }
    }
}

int main()
{
	no *arvore = NULL;
	char *opcao = (char *) malloc(sizeof(8));
	int elemento;

	while(scanf("%s", opcao) != EOF)
	{
		if(strcmp(opcao, "I") == 0)
		{
			scanf("%d", &elemento);
			inserir(&arvore, elemento);
		}
		else
		if(strcmp(opcao, "INFIXA") == 0)
		{
			pTermo = true;
			infixa(arvore);
			printf("\n");
		}
		else
		if(strcmp(opcao, "PREFIXA") == 0)
		{
			pTermo = true;
			prefixa(arvore);
			printf("\n");
		}
		else
		if(strcmp(opcao, "POSFIXA") == 0)
		{
			pTermo = true;
			posfixa(arvore);
			printf("\n");
		}
		else
        if(strcmp(opcao, "P") == 0)
		{
			scanf("%d", &elemento);
			printf("%d ", elemento);
			if(pesquisa(arvore, elemento))
				printf("existe\n");
			else
				printf("nao existe\n");
		}
        else
        {
            scanf("%d", &elemento);
            remover(&arvore, elemento);
        }
	}

	return 0;
}
