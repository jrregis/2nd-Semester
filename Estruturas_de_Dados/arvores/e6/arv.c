#include "arv.h"

arv *arv_criavazia(void)
{
    return NULL;
}

arv *arv_cria(int v, arv *e, arv *d)
{
    arv *b = (arv *)malloc(sizeof(arv));

    b->info = v;
    b->dir = d;
    b->esq = e;

    return b;
}

int vazia(arv *a)
{
    return a == NULL;
}

arv *libera(arv *a)
{
    if (!vazia(a))
    {
        libera(a->dir);
        libera(a->esq);
        free(a);
    }
    return NULL;
}

bool igual(arv *a, arv *b)
{
    if (vazia(a) && vazia(b))
        return true;

    if ((!vazia(a) && vazia(b)) || (vazia(a) && !vazia(b)))
        return false;

    if (a->info != b->info)
        return false;

    if (!(igual(a->esq, b->esq)) && (igual(a->dir, b->dir)))
        return false;

    return true;
}