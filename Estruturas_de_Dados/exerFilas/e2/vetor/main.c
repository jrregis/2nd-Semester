#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
int main()
{
    Fila *f1;
    f1 = fila_cria();
    printf("\n\nFILA 1: ");
    fila_insere(f1, 2.1);
    fila_insere(f1, 4.5);
    fila_insere(f1, 1.0);
    Fila *f2;
    printf("\n\nFILA 2: ");
    f2 = fila_cria();
    fila_insere(f2, 7.2);
    fila_insere(f2, 3.1);
    fila_insere(f2, 9.8);
    Fila *f_res;
    f_res = fila_cria();
    printf("\n\nMONTANDO F_RES: ");
    combina_filas(f_res, f1, f2);
    printf("\n\nFILA 1: ");
    imprime_fila(f1);
    printf("\n\nFILA 2: ");
    imprime_fila(f2);
    printf("\n\nFILA F_RES: ");
    imprime_fila(f_res);
    fila_libera(f1);
    fila_libera(f2);
    fila_libera(f_res);
    return 1;
}