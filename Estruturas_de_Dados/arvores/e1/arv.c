#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

arv *arv_criavazia(void)
{
    return NULL;
}

arv *arv_cria(char c, arv *e, arv *d)
{
    arv *novo_elemento = (arv *)malloc(sizeof(arv));

    novo_elemento->info = c;
    novo_elemento->esq = e;
    novo_elemento->dir = d;

    return novo_elemento;
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
    return a;
}

void preOrdem(arv *a)
{
    if (!vazia(a))
    {
        printf("%c ", a->info);
        preOrdem(a->esq);
        preOrdem(a->dir);
    }
}

void posOrdem(arv *a)
{
    if (!vazia(a))
    {
        posOrdem(a->esq);
        posOrdem(a->dir);
        printf("%c ", a->info);
    }
}

void simetrica(arv *a)
{
    if (!vazia(a))
    {
        simetrica(a->esq);
        printf("%c ", a->info);
        simetrica(a->dir);
    }
}
