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
    printf("\nInicializou pilha com %d elementos\n", p->n);
    return p;
}

void pilha_push(pilha *p, float v)
{
    // printf("\n\nTentando inserir o valor %.2f na pilha que jah possui %d elementos (aceita no maximo % d elementos)\n ", v, p->n, 5);

    if (p->n == 5)
    {
        printf("\nCapacidade da pilha estourou.\n");
        exit(1);
    }
    p->vet[p->n] = v;
    p->n++;
}

float pilha_pop(pilha *p)
{
    float v;

    if (pilha_vazia(p))
    {
        printf("pilha vazia.\n");
        exit(1);
    }

    v = p->vet[p->n - 1];
    p->n--;
    return v;
}

int num_obj(pilha *p)
{
    return p->n;
}

float topo(pilha *p)
{
    return p->vet[p->n - 1];
}