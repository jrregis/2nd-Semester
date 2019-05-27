#include <stdlib.h>
#include "fila.h"
#include <stdio.h>
Fila *fila_cria(void)
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->n = 0;   /* inicializa fila como vazia */
    f->ini = 0; /* escolhe uma posição inicial */
    return f;
}
void fila_insere(Fila *f, float v)
{
    int fim;
    if (f->n == N)
    { /* fila cheia: capacidade esgotada */
        printf("\n\t*** Capacidade da fila estourou.\n");
        exit(1); /* aborta programa */
    }
    /* insere elemento na próxima posição livre */
    fim = (f->ini + f->n) % N;
    f->vet[fim] = v;
    f->n++;
    printf("\n\n\tElemento %.2f foi inserido na posicao %d. Fila possui agora %d elementos\n", v, fim, f->n);
    printf("\tFILA: ");
    imprime_fila(f);
}
int fila_vazia(Fila *f)
{
    return (f->n == 0);
}
float fila_retira(Fila *f)
{
    float v;
    if (fila_vazia(f))
    {
        printf("\n\n*** Fila vazia.\n");
        exit(1); /* aborta programa */
    }
    /* retira elemento do início */
    v = f->vet[f->ini];
    printf("\n\n\tElemento %.2f foi retirado da posicao %d.", v, f->ini);
    f->ini = (f->ini + 1) % N;
    f->n--;
    printf("Fila possui agora %d elementos\n", f->n);
    printf("\tFILA: ");
    imprime_fila(f);
    return v;
}
void imprime_fila(Fila *f)
{
    int fim = (f->ini + f->n) % N; //calcula onde estah o fim
    if (fim >= f->ini)             //fim > inicio
        for (int i = f->ini; i < fim; i++)
            printf("\t[%d]: %.2f", i, f->vet[i]);
    else //fim < inicio
    {
        for (int i = f->ini; i < N; i++) //imprime do inicio da fila ateh o fim do vetor (N-1)
            printf("\t%.2f", f->vet[i]);
        for (int i = 0; i < fim; i++) //imprime do inicio do vetor (0) teh o fim da fila
            printf("\t%.2f", f->vet[i]);
    }
    printf("\n");
}
void imprime_fila2(Fila *f)
{
    int i;
    for (i = 0; i < f->n; i++)
        printf("\t%.2f", f->vet[(f->ini + i) % N]);
}
void fila_libera(Fila *f)
{
    free(f);
}

void combina_filas(Fila *f_res, Fila *f1, Fila *f2)
{
    float elemento;
    while (!fila_vazia(f1) && !fila_vazia(f2))
    {
        elemento = fila_retira(f1);
        fila_insere(f_res, elemento);
        elemento = fila_retira(f2);
        fila_insere(f_res, elemento);
    }
    if (fila_vazia(f1))         //fila 1 estah vazia
        while (!fila_vazia(f2)) //copia o resto da f2
        {
            elemento = fila_retira(f2);
            fila_insere(f_res, elemento);
        }
    else                        //fila 2 estah vazia
        while (!fila_vazia(f1)) //copia o resto da f1
        {
            elemento = fila_retira(f1);
            fila_insere(f_res, elemento);
        }
}