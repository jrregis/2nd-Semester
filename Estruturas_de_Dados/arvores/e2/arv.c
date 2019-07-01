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

int par(arv *a)
{
    int cont = 0;

    if (vazia(a))
        return 0;

    if (a->info % 2 == 0)
        cont = 1;

    return cont + par(a->esq) + par(a->dir);
}
