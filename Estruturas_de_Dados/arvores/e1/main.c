#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

int main()
{
    arv *i = arv_cria('i', arv_criavazia(), arv_criavazia());
    arv *j = arv_cria('j', arv_criavazia(), arv_criavazia());
    arv *g = arv_cria('g', i, arv_criavazia());
    arv *h = arv_cria('h', j, arv_criavazia());
    arv *e = arv_cria('e', g, arv_criavazia());
    arv *f = arv_cria('f', arv_criavazia(), h);
    arv *d = arv_cria('d', e, f);
    arv *c = arv_cria('c', d, arv_criavazia());
    arv *b = arv_cria('b', arv_criavazia(), c);
    arv *a = arv_cria('a', arv_criavazia(), b);

    printf("\nPre ordem: \n");
    preOrdem(a);
    printf("\nPos ordem: \n");
    posOrdem(a);
    printf("\nOrdem simetrica: \n");
    simetrica(a);

    a = arv_libera(a);

    return 1;
}