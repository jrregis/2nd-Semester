#include <stdio.h>

int produto(int p)
{
    if (p == 0)
        return 1;
    else
        return p * produto(p - 1);
}

int main()
{
    int n;
    printf("Digite o numero a saber o fatorial: ");
    scanf("%d", &n);
    n = produto(n);
    printf("\n%d\n", n);
}