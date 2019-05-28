#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int vazia(fila *f)
{
    return (f->ini == NULL);
}

fila *fila_cria(void)
{
    fila *f = (fila *)malloc(sizeof(fila));

    f->ini = f->fim = NULL;

    return f;
}

void fila_insere(fila *f, float v)
{
    lista *n = (lista *)malloc(sizeof(lista));

    n->info = v;
    n->prox = NULL;

    if (f->fim != NULL)
        f->fim->prox = n;

    else
        f->ini = n;
    f->fim = n;
}

float fila_retira(fila *f)
{
    lista *t;
    float v;

    if (vazia(f))
    {
        printf("Fila vazia.\n");
        exit(1);
    }

    t = f->ini;
    v = t->info;
    f->ini = t->prox;

    if (f->ini == NULL)
        f->fim = NULL;

    free(t);
    return v;
}

void imprime(fila *f)
{
    lista *l;
    for (l = f->ini; l != NULL; l = l->prox)
        printf("%.2f ", l->info);
}

void combina_filas(fila *f0, fila *f1, fila *f2)
{
    while (!vazia(f1) && !vazia(f2))
    {
        fila_insere(f0, fila_retira(f1));
        fila_insere(f0, fila_retira(f2));
    }

    if (vazia(f1))
    {
        while (!vazia(f2))
            fila_insere(f0, fila_retira(f2));
    }

    else
    {
        while (!vazia(f1))
            fila_insere(f0, fila_retira(f2));
    }
}