#include <stdio.h>
#include "pilha.h"

int main()
{
    int num;
    float obj;
    pilha *p = pilha_cria();

    pilha_push(p, 1);
    pilha_push(p, 2);
    pilha_push(p, 13);
    pilha_push(p, 200);

    num = num_obj(p);
    printf("ELEMENTOS = %d\n", num);

    obj = topo(p);
    printf("TOPO = %f\n", obj);
}