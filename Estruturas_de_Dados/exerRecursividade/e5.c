#include <stdio.h>
#include <stdlib.h>
float calculaSoma(int x, int y)
{
    if (y == 0)
        return x;
    else
        return calculaSoma(x + 1, y - 1);
}

int main()
{
    int result, x, y;

    printf("DIGITE OS VALORES A SEREM SOMADOS:\n");
    scanf("%d %d", &x, &y);

    result = calculaSoma(x, y);

    printf("Resultado %d\n", result);
}