#ifndef PILHA_H
#define PILHA_H
#include <stdbool.h>

typedef struct lista
{
    float info;
    struct lista *prox;
} lista;

typedef struct pilha
{
    struct lista *prim;
} pilha;

void imprime(pilha *p);
void pilha_pop(pilha *p);
void pilha_push(pilha *p, float v);
pilha *pilha_cria(void);
bool pilha_vazia(pilha *p);
int num_obj(pilha *p);
float topo(pilha *p);
#endif