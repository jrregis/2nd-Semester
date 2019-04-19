#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
/* função de criação: retorna uma lista vazia */
Lista *lst_cria(void)
{
	return NULL;
}
Lista *lst_insere(Lista *l, int i)
{
	Lista *novo = (Lista *)malloc(sizeof(Lista));
	novo->info = i;
	novo->prox = l;
	return novo;
}
void lst_imprime(Lista *l)
{
	Lista *p;
	for (p = l; p != NULL; p = p->prox)
		printf("info = %d\n", p->info);
}
int lst_vazia(Lista *l)
{
	return (l == NULL);
}
Lista *busca(Lista *l, int v)
{
	Lista *p;
	for (p = l; p != NULL; p = p->prox)
	{
		printf("%d\n", p->info);
		if (p->info == v)
			return p;
	}
	/* não achou o elemento */
	return NULL;
}
int comprimento(Lista *l)
{
	Lista *p = l;
	int cont = 0;
	while (p != NULL)
	{
		p = p->prox;
		cont++;
	}
	return cont;
}
int maiores(Lista *l, int n)
{
	Lista *p;
	int cont = 0;
	for (p = l; p != NULL; p = p->prox)
	{
		if (p->info > n)
			cont++;
	}
	return cont;
}
Lista *ultimo(Lista *l)
{
	Lista *ultimo = l;
	if (ultimo != NULL)
	{
		while (ultimo->prox != NULL)
		{
			ultimo = ultimo->prox;
		}
	}
	return ultimo;
}
Lista *Concat(Lista *l1, Lista *l2)
{
	Lista *p;
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;

	p = ultimo(l1);
	p->prox = l2;
	return l1;
}