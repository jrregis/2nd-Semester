#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    Pilha *p;
    p = pilha_cria();
    float topo;

    printf("\nInserindo na pilha 10, 20 e 30....\n");
    pilha_push(p, 10);
    pilha_push(p, 20);
    pilha_push(p, 30);

    imprime(p);
}