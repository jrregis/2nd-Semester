#include <stdio.h>

int pesquisaBinaria(int vet[], int chave, int inf, int sup)
{
    while (inf <= sup)
    {
        int meio = (inf + sup) / 2;

        if (vet[meio] == chave)
        {
            return meio;
        }

        else if (vet[meio] < chave)
        {
            return pesquisaBinaria(vet, chave, meio + 1, sup);
        }

        else
            return pesquisaBinaria(vet, chave, inf, meio - 1);
    }
    return -1;
}

int main()
{
    int chave, achou;
    int vet[] = {5, 10, 18, 21, 24, 30, 35, 40, 51, 60};

    printf("DIGITE O ELEMENTO A SER BUSCADO: ");
    scanf("%d", &chave);

    achou = pesquisaBinaria(vet, chave, 0, 9);
    printf("POSICAO: %d\n", achou);
}