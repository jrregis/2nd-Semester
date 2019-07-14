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

    else if (v >= a->v)
    {
        a->dir = insere(a->dir, v);
    }

    else if (v < a->v)
    {
        a->esq = insere(a->esq, v);
    }
    return a;
}

void decrescente(abb *a)
{
    if (!vazia(a))
    {
        decrescente(a->dir);
        printf("%d ", a->v);
        decrescente(a->esq);
    }
}
