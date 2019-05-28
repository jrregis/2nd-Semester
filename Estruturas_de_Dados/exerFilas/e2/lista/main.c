#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main()
{
    fila *f0 = fila_cria();
    fila *f1 = fila_cria();
    fila *f2 = fila_cria();

    fila_insere(f1, 2.1);
    fila_insere(f1, 4.5);
    fila_insere(f1, 1);

    fila_insere(f2, 7.2);
    fila_insere(f2, 3.1);
    fila_insere(f2, 9.8);

    combina_filas(f0, f1, f2);
    imprime(f0);

    printf("\n");
}