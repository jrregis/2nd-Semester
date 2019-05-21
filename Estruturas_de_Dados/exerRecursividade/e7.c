#include <stdio.h>

void calculaBin(int x)
{
    if (x / 2 != 0)
        calculaBin(x / 2);

    printf("%d", x % 2);
}

int main()
{
    int x;
    printf("DIGITE O NUMERO PARA CALCULAR SEU BINARIO: ");
    scanf("%d", &x);

    calculaBin(x);
    printf("\n");
}