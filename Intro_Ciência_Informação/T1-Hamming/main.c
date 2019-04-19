#include <stdio.h>
#include <stdlib.h>
#include "hamming.h"

int getOpt(void)
{
    int opt = 0;
    printf("CODIGO DE HAMMING\n\n");
    printf("0 - Inserir Decimal (0-15)\n1 - Inserir Binario (max. 4bits)\n");
    printf("LEITURA: ");
    scanf("%d", &opt);
    return opt;
}

int getValue(int opt)
{
    int value, max;
    char *option;

    option = opt ? "BINARIO (0000-1111)" : "DECIMAL (0-15)";
    max = opt ? 1111 : 15;

    do
    {
        printf("Insira o valor %s: ", option);
        scanf("%d", &value);
        clearScreen();
    } while (value < 0 || value > max);

    return value;
}

int main()
{
    int opt, value, success;
    int arr[LEN], cod[C_LEN], test[T_LEN];

    opt = getOpt();
    value = getValue(opt);

    clearScreen();
    convertIntToArray(opt, value, arr);
    codifyHamming(arr, cod);
    insertError(cod);
    getHammingParityArray(cod, test);

    clearScreen();

    printf("CODIGO DE HAMMING FINAL: ");
    printArray(cod, C_LEN);

    printf("CODIGO DE PARIDADE: ");
    printArray(test, T_LEN);

    success = checkAndFixArray(cod, test);

    if (!success)
    {
        printf("HOUVE ERRO NA TRANSMISSAO!\n");
        getHammingParityArray(cod, test);
        success = checkAndFixArray(cod, test);

        if (success)
        {
            printf("ERROS CORRIGIDOS!\n");
        }
        else
        {
            printf("ERROS NÃO CORRIGIDOS!\n");
        }
    }
    else
    {
        printf("NAO HOUVE ERRO NA TRANSMISSAO!\n");
    }

    printf("CODIGO FINAL: ");
    printArray(cod, C_LEN);

    /*for (int i = 0; i < LEN; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
    */
}