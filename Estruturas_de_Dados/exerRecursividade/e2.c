#include <stdio.h>
#include <stdlib.h>
void imprimir(int min, int max)
{
    int n = min + 1;

    if (n < max)
        printf("%d\n", n);
    else
        exit(1);

    imprimir(n, max);
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