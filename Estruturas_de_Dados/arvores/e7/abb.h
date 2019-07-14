#ifndef ABB_H
#define ABB_H
#include <stdio.h>
#include <stdlib.h>

typedef struct abb
{
    int info;
    struct abb *dir;
    struct abb *esq;
} abb;

abb *cria_vazia(void);
abb *insere(abb *a, int value);
void *removeNo(abb *a, int value);
void imprime(abb *a);

#endif