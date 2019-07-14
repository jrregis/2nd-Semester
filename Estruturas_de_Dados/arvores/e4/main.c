#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

int main()
{
    arv *j = arv_cria(10, arv_criavazia(), arv_criavazia());
    arv *i = arv_cria(9, arv_criavazia(), arv_criavazia());
    arv *h = arv_cria(8, arv_criavazia(), arv_criavazia());
    arv *g = arv_cria(7, arv_criavazia(), arv_criavazia());
    arv *f = arv_cria(6, g, h);
    arv *e = arv_cria(5, i, j);
    arv *d = arv_cria(4, e, f);
    // arv *c = arv_cria(3, d, arv_criavazia());
    // arv *b = arv_cria(2, arv_criavazia(), c);
    // arv *a = arv_cria(1, arv_criavazia(), b);

    int folhas = 0;
    folhas = num_folha(d);
    printf("%d \n", folhas);
    d = arv_libera(d);
    return 1;
}