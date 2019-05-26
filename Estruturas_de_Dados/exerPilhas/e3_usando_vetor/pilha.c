#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
void imprime(pilha *p);

int pilha_vazia(pilha *p)
{
    return (p->n == 0);
}

pilha *pilha_cria(void)
{
    pilha *p = (pilha *)malloc(sizeof(pilha));
    p->n = 0;
    return p;
}

void pilha_push(pilha *p, float v)
{
    if (p->n == 5)
    {
        printf("\nCapacidade da pilha estourou.\n");
        // imprime(p);
        exit(1);
    }
    p->vet[p->n] = v;
    p->n++;
}

void pilha_pop(pilha *p)
{
    float v;

    if (pilha_vazia(p))
    {
        printf("pilha vazia.\n");
        exit(1);
    }
    p->n--;
}

int num_obj(pilha *p)
{
    return p->n;
}

float topo(pilha *p)
{
    return p->vet[p->n - 1];
}