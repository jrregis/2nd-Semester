#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    pilha *p = cria();
    pilha *p2 = cria();

    push(p, 1);
    push(p, 4.5);
    push(p, 2.1);

    push(p2, 9.8);
    push(p2, 3.1);
    push(p2, 7.2);

    concatena(p, p2);
}