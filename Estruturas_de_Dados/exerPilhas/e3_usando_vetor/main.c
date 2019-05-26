#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    pilha *p;
    int obj = 0;
    float top;
    p = pilha_cria();

    pilha_push(p, 1);
    pilha_push(p, 2);
    pilha_push(p, 3);
    pilha_push(p, 4);
    pilha_pop(p);
    pilha_push(p, 100);

    obj = num_obj(p);
    printf("Obejetos na pilha: %d \n", obj);

    top = topo(p);
    printf("Obejeto no topo da pilha: %.2f \n", top);
}