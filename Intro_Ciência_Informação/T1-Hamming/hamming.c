#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hamming.h"

const int G[GL][GC] = {
    {1, 1, 0, 1},
    {1, 0, 1, 1},
    {1, 0, 0, 0},
    {0, 1, 1, 1},
    {0, 1, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 1}};

const int H[HL][HC] = {
    {1, 0, 1, 0, 1, 0, 1},
    {0, 1, 1, 0, 0, 1, 1},
    {0, 0, 0, 1, 1, 1, 1}};

int checkAndFixArray(int cod[], int test[])
{
    int e = 0;
    for (int i = 0; i < T_LEN; i++)
    {
        e += test[i] * pow(2, i);
    }

    if (e > 0)
    {
        printf("POSICAO DO ERRO: %d\n", e - 1);

        cod[e - 1] = 1 - cod[e - 1];
        return 0;
    }
    else
    {
        return 1;
    }
}

void getHammingParityArray(int cod[], int test[])
{
    for (int i = 0; i < HL; i++)
    {
        test[i] = 0;
        for (int j = 0; j < HC; j++)
        {
            test[i] += cod[j] * H[i][j];
        }
        test[i] = test[i] % 2;
    }
}

void clearScreen(void)
{
    system("clear");
}

void printArray(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

void convertIntToArray(int option, int value, int arr[])
{
    int r, oldValue = value;
    for (int i = 0; i < LEN; i++)
    {
        if (option)
        {
            r = value % 10;
            if (r != 1 && r != 0)
            {
                printf("VALOR BINARIO %d INVALIDO! TENTE NOVAMENTE!\n", oldValue);
                exit(0);
            }
            arr[LEN - i - 1] = r;
            value = value / 10;
        }
        else
        {
            arr[LEN - i - 1] = value % 2;
            value = value / 2;
        }
    }
}

void codifyHamming(int arr[], int cod[])
{
    for (int i = 0; i < GL; i++)
    {
        cod[i] = 0;
        for (int j = 0; j < GC; j++)
        {
            cod[i] += arr[j] * G[i][j];
        }
        cod[i] = cod[i] % 2;
    }

    printf("CODIGO INSERIDO: ");
    printArray(arr, LEN);

    printf("CODIGO DE HAMMING GERADO: ");
    printArray(cod, C_LEN);
}

void insertError(int cod[])
{
    int error, count = 1, pos;
    do
    {
        printf("INFORME A QUANTIDADE DE ERROS QUE DESEJA INSERIR: ");
        scanf("%d", &error);
    } while (error < 0 || error > 3);

    while (error > 0)
    {
        clearScreen();
        printf("CODIGO DE HAMMING GERADO: ");
        printArray(cod, C_LEN);

        printf("INDIQUE A POSICADO DO %ḍ° ERRO (0-6): ", count);
        scanf("%d", &pos);

        cod[pos] = 1 - cod[pos];

        count++;
        error--;
    }

    clearScreen();
    printf("CODIGO DE HAMMING FINAL: ");
    printArray(cod, C_LEN);
}