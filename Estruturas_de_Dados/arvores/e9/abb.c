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

bool eh_abb(abb *a)
{
    if (vazia(a))
        return true;

    if ((!vazia(a->esq) && a->esq->v >= a->v) || (!vazia(a->dir) && a->dir->v < a->v))
        return false;

    else
        return (eh_abb(a->esq) && eh_abb(a->dir));
}