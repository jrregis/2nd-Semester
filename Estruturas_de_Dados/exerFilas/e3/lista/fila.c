#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila *fila_cria(void)
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;

    return f;
}

float fila_frente(Fila *f)
{
    return f->ini->v;
}

int fila_vazia(Fila *f)
{
    return (f->ini == NULL);
}

void fila_imprime(Fila *f)
{
    Lista *p = f->ini;
    while (p != NULL)
    {
        printf("\t%.2f", p->v);
        p = p->prox;
    }
}

void fila_insere(Fila *f, float v)
{
    Lista *new = (Lista *)malloc(sizeof(Lista));
    new->v = v;
    new->prox = NULL;

    if (f->ini == NULL)
        f->ini = new;
    else
        f->fim->prox = new;

    f->fim = new;
}

float fila_remove(Fila *f)
{
    Lista *aux;
    float v;

    if (f->ini == NULL)
    {
        printf("Lista vazia!\n");
        exit(1);
    }

    aux = f->ini;
    v = f->ini->v;
    f->ini = aux->prox;

    if (f->ini == NULL)
        f->fim = NULL;

    free(aux);

    return v;
}

void fila_libera(Fila *f)
{
    while (f->ini != NULL)
    {
        fila_remove(f);
    }
    free(f);
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

    else
        while (!fila_vazia(f1))
            fila_insere(f3, fila_remove(f1));

    return f3;
}