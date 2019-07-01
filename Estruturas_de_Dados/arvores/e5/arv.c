#include "arv.h"

arv *arv_criavazia(void)
{
    return NULL;
}

arv *arv_cria(int v, arv *e, arv *d)
{
    arv *nodo = (arv *)malloc(sizeof(arv));

    nodo->info = v;
    nodo->dir = d;
    nodo->esq = e;

    return nodo;
}

int vazia(arv *a)
{
    return a == NULL;
}

arv *arv_libera(arv *a)
{
    if (!vazia(a))
    {
        arv_libera(a->dir);
        arv_libera(a->esq);
        free(a);
    }
    return NULL;
}

int num_filho(arv *a)
{
    if (vazia(a))
        return 0;

    if (!vazia(a->dir) && vazia(a->esq) || vazia(a->dir) && !vazia(a->esq))
        return 1 + num_filho(a->dir) + num_filho(a->esq);

    return num_filho(a->dir) + num_filho(a->esq);
}