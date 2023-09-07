/*
	1200 - BST Operations I
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
	char info;
	struct NO *esq;
	struct NO *dir;
} no;

void inserir(no **n, const char i)
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
			printf("%c", n->info);
			pTermo = false;
		}
		else
			printf(" %c", n->info);
		infixa(n->dir);
	}
}
void prefixa(const no *n)
{
	if(n)
	{
		if(pTermo)
		{
			printf("%c", n->info);
			pTermo = false;
		}
		else
			printf(" %c", n->info);
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
			printf("%c", n->info);
			pTermo = false;
		}
		else
			printf(" %c", n->info);
	}
}
bool pesquisa(const no *n, const char i)
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

int main()
{
	no *arvore = NULL;
	char *opcao = (char *) malloc(sizeof(8));
	char caracter;

	while(scanf("%s", opcao) != EOF)
	{
		if(strcmp(opcao, "I") == 0)
		{
			scanf(" %c", &caracter);
			inserir(&arvore, caracter);
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
		{
			scanf(" %c", &caracter);
			printf("%c ", caracter);

			if(pesquisa(arvore, caracter))
				printf("existe\n");
			else
				printf("nao existe\n");
		}
	}

	return 0;
}
