#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int fila_vazia(fila *f)
{
    return f->n == 0;
}

fila *fila_cria(void)
{
    fila *f = (fila *)malloc(sizeof(fila));
    f->n = 0;   /* inicializa fila como vazia */
    f->ini = 0; /* escolhe uma posição inicial */
    return f;
}

void fila_insere(fila *f, float v)
{
    int fim;

    if (f->n == 10)
    { /* fila cheia: capacidade esgotada */
        printf("Capacidade da fila estourou.\n");
        exit(1);
        /* aborta programa */
    }
    /* insere elemento na próxima posição livre */
    fim = (f->ini + f->n) % 10;
    f->vet[fim] = v;
    f->n++;
}

void fila_retira(fila *f)
{
    if (fila_vazia(f))
    {
        printf("Fila vazia.\n");
        exit(1);
    }
    /* retira elemento do início */
    f->ini = (f->ini + 1) % 10;
    f->n--;
}

void imprime(fila *f)
{
    for (int i = 0; i < f->n; i++)
    {
        printf("%f\n", f->vet[i]);
    }
}
