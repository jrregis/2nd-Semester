#include <stdio.h>

int potencia(int base, int expoente)
{
    if (expoente == 0)
        return 1;
    else
        return (base * potencia(base, expoente - 1));
}
int main()
{
    int base = 0, expoente = 0, resultado;

    printf("DIGITE A BASE: ");
    scanf("%d", &base);

    printf("DIGITE O EXPOENTE: ");
    scanf("%d", &expoente);

    resultado = potencia(base, expoente);
    printf("%d elevado a %d = %d\n", base, expoente, resultado);
}