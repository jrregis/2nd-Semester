#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
void imprime(Pilha *p);
int pilha_vazia(Pilha *p)
{
    return (p->n == 0);
}

Pilha *pilha_cria(void)
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->n = 0;
    printf("\nInicializou pilha com %d elementos\n", p->n);
    return p;
}

void pilha_push(Pilha *p, float v)
{
    printf("\n\nTentando inserir o valor %.2f na pilha que jah possui %d elementos (aceita no maximo % d elementos)\n ", v, p->n, N);

    if (p->n == N)
    {
        printf("\nCapacidade da pilha estourou.\n");
        imprime(p);
        exit(1);
    }
    p->vet[p->n] = v;
    p->n++;
}

float pilha_pop(Pilha *p)
{
    float v;

    if (pilha_vazia(p))
    {
        printf("Pilha vazia.\n");
        exit(1);
    }

    v = p->vet[p->n - 1];
    p->n--;
    return v;
}

void imprime(Pilha *p)
{
    printf("VALORES ARMAZENADOS NA PILHA: \n\n");
    for (int i = 0; i < N; i++)
    {
        printf("Posicao %d = %f\n", i, p->vet[i]);
    }
}