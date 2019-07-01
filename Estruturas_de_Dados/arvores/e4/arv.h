#ifndef ARV_H
#define ARV_H

typedef struct arv
{
    int info;
    struct arv *dir;
    struct arv *esq;
} arv;

arv *arv_criavazia(void);
arv *arv_cria(int v, arv *e, arv *d);
arv *arv_libera(arv *a);
int vazia(arv *a);
int num_folha(arv *a);

#endif