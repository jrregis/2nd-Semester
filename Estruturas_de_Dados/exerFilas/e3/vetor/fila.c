#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila *fila_cria(void)
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->n = 0;
    f->ini = 0;

    return f;
}

int fila_vazia(Fila *f)
{
    return (f->n == 0);
}

float fila_frente(Fila *f)
{
    return f->vet[f->ini];
}

void fila_imprime(Fila *f)
{
    for (int i = 0; i < f->n; i++)
        printf("\t %.2f", f->vet[(f->ini + i) % N]);
}

void fila_libera(Fila *f)
{
    free(f);
}

void fila_insere(Fila *f, float v)
{
    if (f->n == N)
    {
        printf("Capacidade da fila estourou!\n");
        exit(1);
    }

    int fim = (f->ini + f->n) % N;
    f->vet[fim] = v;
    f->n++;
}

float fila_remove(Fila *f)
{
    if (f->n == 0)
    {
        printf("Fila vazia!\n");
        exit(1);
    }

    float v = f->vet[f->ini];
    f->ini = (f->ini + 1) % N;
    f->n--;

    return v;
}

Fila *fila_ordernar(Fila *f1, Fila *f2)
{
    Fila *f3 = fila_cria();

    while (!fila_vazia(f1) && !fila_vazia(f2))
    {
        if (fila_frente(f1) < fila_frente(f2))
            fila_insere(f3, fila_remove(f1));

        else
            fila_insere(f3, fila_remove(f2));
    }

    if (fila_vazia(f1))
        while (!fila_vazia(f2))
            fila_insere(f3, fila_remove(f2));

    else if (fila_vazia(f2))
        while (!fila_vazia(f1))
            fila_insere(f3, fila_remove(f1));

    return f3;
}