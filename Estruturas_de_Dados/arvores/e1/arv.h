#ifndef ARV_H
#define ARV_H

struct arv
{
    char info;
    struct arv *dir;
    struct arv *esq;
};

typedef struct arv arv;

arv *arv_criavazia(void);
arv *arv_cria(char c, arv *e, arv *d);
arv *arv_libera(arv *a);
int arv_vazia(arv *a);
void preOrdem(arv *a);
void posOrdem(arv *a);
void simetrica(arv *a);

#endif