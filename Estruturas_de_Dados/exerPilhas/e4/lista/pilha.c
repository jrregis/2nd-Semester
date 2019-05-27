#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int pilha_vazia(pilha *p)
{
    return (p->prim == NULL);
}

pilha *pilha_cria(void)
{
    pilha *p = (pilha *)malloc(sizeof(pilha));
    p->prim = NULL;

    return p;
}

void pilha_push(pilha *p, float v)
{
    lista *n = (lista *)malloc(sizeof(lista));

    n->info = v;
    n->prox = p->prim;
    p->prim = n;
}

void pilha_pop(pilha *p)
{
    lista *t;

    t = p->prim;
    p->prim = t->prox;

    free(t);
}

void imprime(pilha *p)
{
    lista *l;
    if (p->prim != NULL)
    {
        for (l = p->prim; l != NULL; l = l->prox)
        {
            printf("%f\n", l->info);
        }
    }
    else
        printf("PILHA VAZIA\n");
}

void pilha_esvazia(pilha *p)
{
    free(p);
    // p->prim = NULL;
}
