#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    pilha *p = pilha_cria();

    pilha_push(p, 1);
    pilha_push(p, 2);
    pilha_push(p, 3);

    // imprime(p);

    pilha_esvazia(p);
    imprime(p);
}