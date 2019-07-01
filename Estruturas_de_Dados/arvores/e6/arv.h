#ifndef ARV_H
#define ARV_
#include <stdbool.h>
#include <stdlib.h>

typedef struct arv
{
    struct arv *dir;
    struct arv *esq;
    int info;
} arv;

arv *arv_criavazia(void);
arv *arv_cria(int v, arv *e, arv *d);
arv *libera(arv *a);
int vazia(arv *a);
bool igual(arv *a, arv *b);

#endif