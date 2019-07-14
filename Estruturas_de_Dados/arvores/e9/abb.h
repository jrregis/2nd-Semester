#ifndef ABB_H
#define ABB_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct abb
{
    int v;
    struct abb *dir;
    struct abb *esq;
} abb;

abb *cria_vazia(void);
abb *insere(abb *, int v);
bool eh_abb(abb *a);

#endif