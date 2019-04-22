#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int pilha_vazia(pilha *p)
{
    return p->prim == NULL;
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

float pilha_pop(pilha *p)
{
    lista *t;
    float v;
    if (pilha_vazia(p))
    {
        printf("Pilha vazia.\n");
        exit(1);
    }
    t = p->prim;
    v = t->info;
    p->prim = t->prox;
    free(t);
    return v;
}

void imprime(pilha *p)
{
    printf("IMPRIMINDO LISTA DE VALORES DA PILHA:\n");
    lista *l;
    for (l = p->prim; l != NULL; l = l->prox)
        printf("%f \n", l->info);
}