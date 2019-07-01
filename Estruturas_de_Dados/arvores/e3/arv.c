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

arv *copia(arv *a)
{
    if (vazia(a))
        return arv_criavazia();

    arv *cpy = arv_cria(a->info, copia(a->esq), copia(a->dir));
}

void preOrdem(arv *a)
{
    if (!vazia(a))
    {
        printf("%d ", a->info);
        preOrdem(a->esq);
        preOrdem(a->dir);
    }
}