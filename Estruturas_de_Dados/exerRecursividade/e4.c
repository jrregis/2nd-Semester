#include <stdio.h>
#include <stdlib.h>
float calculaS(float n, float d)
{
    if (d > 50 && n > 99)
        return 0;

    else
        return (n / d + calculaS(n + 2, d + 1));
}

int main()
{
    float result = 0, n = 1, d = 1;

    result = calculaS(n, d);

    printf("Resultado %.2f\n", result);
}