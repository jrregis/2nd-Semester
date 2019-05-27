#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main()
{
    fila *f = fila_cria();

    fila_insere(f, 1);
    fila_insere(f, 2);
    fila_insere(f, 3);
    fila_insere(f, 4);
    fila_insere(f, 5);
    fila_insere(f, 6);

    imprime(f);
}