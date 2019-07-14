#include "abb.h"

abb *cria_vazia(void)
{
    return NULL;
}

int vazia(abb *a)
{
    return a == NULL;
}

abb *insere(abb *a, int v)
{
    if (vazia(a))
    {
        a = (abb *)malloc(sizeof(abb));

        a->v = v;
        a->esq = a->dir = NULL;
    }

    else if (v < a->v)
        a->esq = insere(a->esq, v);

    else if (v >= a->v)
        a->dir = insere(a->dir, v);

    return a;
}

abb *inverter(abb *a)
{
    if (a != NULL)
    {
        abb *aux = a->esq;
        a->esq = a->dir;
        a->dir = aux;
        a->esq = inverter(a->esq);
        a->dir = inverter(a->dir);
    }
    return a;
}

void imprime(abb *a)
{
    if (!vazia(a))
    {
        imprime(a->esq);
        printf("%d ", a->v);
        imprime(a->dir);
    }
}