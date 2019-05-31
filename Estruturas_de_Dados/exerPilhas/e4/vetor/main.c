#include <stdio.h>
#include "pilha.h"

int main()
{
    pilha *p = pilha_cria();

    pilha_push(p, 1);
    pilha_push(p, 2);
    pilha_push(p, 3);
    pilha_push(p, 4);
    pilha_push(p, 5);

    esvazie(p);
    printf("\n");
    imprime(p);
}