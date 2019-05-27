#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int fila_vazia(fila *f)
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

    n->info = v;    //armazena info
    n->prox = NULL; //novo nó passa a ser o ultimo

    if (f->fim != NULL) //verifica se a lista nao estava vazia
        f->fim->prox = n;
    else //verifica se a lista estava vazia
        f->ini = n;
    f->fim = n; //fila aponta para o novo elemento
}

void fila_retira(fila *f)
{
    lista *t;
    if (fila_vazia(f))
    {
        printf("Fila vazia.\n");
        exit(1);
    }

    t = f->ini;
    f->ini = t->prox;

    if (f->ini == NULL)
        f->fim = NULL;

    free(t);
}

void imprime(fila *f)
{
    lista *l;
    for (l = f->ini; l != NULL; l = l->prox)
    {
        printf("%.2f\n", l->info);
    }
}