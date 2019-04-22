#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    pilha *p;
    p = pilha_cria();

    printf("\nInserindo na pilha 10, 20 e 30....\n");

    pilha_push(p, 10);
    pilha_push(p, 20);
    pilha_push(p, 30);

    imprime(p);
}