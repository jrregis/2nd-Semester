#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

arv *arv_criavazia(void)
{
    return NULL;
}

arv *arv_cria(int v, arv *e, arv *d)
{
    arv *noh = (arv *)malloc(sizeof(arv));

    noh->info = v;
    noh->esq = e;
    noh->dir = d;

    return noh;
}

int vazia(arv *a)
{
    return a == NULL;
}

arv *arv_libera(arv *a)
{
    if (!vazia(a))
    {
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }
    return NULL;
}

int num_folha(arv *a)
{
    int folha = 0;
    if (a == NULL)
        return 0;

    if (a->esq == NULL && a->dir == NULL)
        folha = 1;

    return folha + num_folha(a->esq) + num_folha(a->dir);
}