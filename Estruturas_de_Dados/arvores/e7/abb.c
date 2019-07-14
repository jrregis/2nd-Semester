#include "abb.h"

abb *cria_vazia(void)
{
    return NULL;
}

int vazia(abb *a)
{
    return a == NULL;
}

abb *insere(abb *a, int value)
{
    //ARVORE VAZIA SÓ INSERE
    if (vazia(a))
    {
        a = (abb *)malloc(sizeof(abb));

        a->info = value;

        a->dir = a->esq = NULL;
    }

    //VALOR MENOR QUE O DO NÓ ATUAL, DEVE SER INSERIDO NA ESQUERDA
    else if (value < a->info)
        a->esq = insere(a->esq, value);

    //VALOR MAIOR OU IGUAL QUE O DO NÓ ATUAL, DEVE SER INSERIDO NA DIREITA
    else if (value >= a->info)
        a->dir = insere(a->dir, value);

    return a;
}

void *removeNo(abb *a, int value)
{
    if (a == NULL)
        return NULL;

    if (a->info > value)
        removeNo(a->esq, value);

    else if (a->info < value)
        removeNo(a->dir, value);

    else if (a->info == value)
    {
        if (a->esq == NULL && a->dir == NULL)
            free(a);

        if (a->esq != NULL && a->dir == NULL)
        {
            abb *temp = a;
            a = a->esq;
            free(temp);
        }

        if (a->esq == NULL && a->dir != NULL)
        {
            abb *temp = a;
            a = a->dir;
            free(temp);
        }

        if (a->esq != NULL && a->dir != NULL)
        {
            abb *temp = a->esq;

            while (temp->dir != NULL)
            {
                temp = temp->dir;
            }

            a->info = temp->info;
            temp->info = value;
            a->esq = removeNo(a->esq, value);
        }
    }
    return a;
}

// ORDEM SIMETRICA (SAE, RAIZ, SAD)
void imprime(abb *a)
{
    if (!vazia(a))
    {
        imprime(a->esq);
        printf("%d ", a->info);
        imprime(a->dir);
    }
}