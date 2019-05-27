#include <stdio.h>
#include "fila.h"

int main()
{
    fila *f = fila_cria();

    fila_insere(f, 1);
    fila_insere(f, 2);
    fila_insere(f, 30);
    fila_insere(f, 100);
    imprime(f);
    printf("retirando\n");
    fila_retira(f);
    imprime(f);
}