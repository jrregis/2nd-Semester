#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int pilha_vazia(pilha *p)
{
    return (p->num_elements == 0);
}

pilha *pilha_cria(void)
{
    pilha *p = (pilha *)malloc(sizeof(pilha));
    p->num_elements = 0;
    return p;
}

void pilha_push(pilha *p, float v)
{
    if (p->num_elements == 5)
    {
        printf("PILHA CHEIA\n");
        exit(1);
    }

    p->vet[p->num_elements] = v;
    p->num_elements++;
}

void pilha_pop(pilha *p)
{
    if (pilha_vazia(p))
    {
        printf("PILHA VAZIA\n");
        exit(1);
    }
    p->num_elements--;
}

void imprime(pilha *p)
{
    if (p->num_elements > 0)
    {
        for (int i = 0; i < p->num_elements; i++)
        {
            printf("%f\n", p->vet[i]);
        }
    }
    else
        printf("PILHA VAZIA\n");
}

void pilha_esvazia(pilha *p)
{
    p->num_elements = 0;
}