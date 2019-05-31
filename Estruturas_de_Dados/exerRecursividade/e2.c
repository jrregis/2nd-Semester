#include <stdio.h>
#include <stdlib.h>
void imprimir(int min, int max)
{
    printf("%d\n", min + 1);

    if (min + 2 != max)
        imprimir(min + 1, max);
}

int main()
{
    int min = 0, max = 0;
    printf("Digite o valor minimo: ");
    scanf("%d", &min);

    printf("Digite o valor maximo: ");
    scanf("%d", &max);

    imprimir(min, max);
}