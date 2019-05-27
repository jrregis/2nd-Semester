#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int vazia(pilha *p)
{
    return (p->prim == NULL);
}

pilha *cria(void)
{
    pilha *p = (pilha *)malloc(sizeof(pilha));
    p->prim = NULL;
    return p;
}

void push(pilha *p, float v)
{
    lista *n = (lista *)malloc(sizeof(lista));

    n->info = v;
    n->prox = p->prim;
    p->prim = n;
}

void pop(pilha *p)
{
    lista *t;

    if (vazia(p))
    {
        printf("VAZIA\n");
        exit(1);
    }

    t = p->prim;
    p->prim = t->prox;

    free(t);
}

void imprime(pilha *p)
{
    lista *l;
    for (l = p->prim; l != NULL; l = l->prox)
    {
        printf("%f\n", l->info);
    }
}

void concatena(pilha *p, pilha *p1)
{
    pilha *aux = cria();

    while (p1->prim != NULL)
    {
        push(aux, p1->prim->info);
        pop(p1);
    }

    while (aux->prim != NULL)
    {
        push(p, aux->prim->info);
        pop(aux);
    }
    imprime(p);
}