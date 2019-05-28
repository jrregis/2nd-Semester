#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(void)
{
    Fila *f1 = fila_cria();
    fila_insere(f1, 2);
    fila_insere(f1, 4);
    fila_insere(f1, 6);
    fila_insere(f1, 8);
    fila_insere(f1, 10);

    Fila *f2 = fila_cria();
    fila_insere(f2, 1);
    fila_insere(f2, 3);
    fila_insere(f2, 5);
    fila_insere(f2, 7);
    fila_insere(f2, 9);
    fila_insere(f2, 11);
    fila_insere(f2, 12);
    fila_insere(f2, 14);
    fila_insere(f2, 18);
    fila_insere(f2, 20);

     Fila *f3 = fila_ordernar(f1, f2);
    fila_imprime(f3);
    printf("\n");

    fila_libera(f1);
    fila_libera(f2);
    fila_libera(f3);

    return 0;
}