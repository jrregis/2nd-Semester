#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include "lista.h"

int main()
{
    int op = 0;
    Node *l, *sign, *new;
    l = Create();
    l = InputFirstP(l, -5);
    l = InputFirstP(l, 10);
    l = InputFirstP(l, 20);
    l = InputFirstP(l, -10);
    l = InputFirstP(l, 5);
    Show(l);
    printf("Exercicios\n1-e1 2-e2 3-e3 4-e4\n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        sign = ChangeSign(l);
        printf("Changing sign\n");
        Show(sign);
        break;
    case 2:
        new = InputEnd(l, 10);
        Show(l);
        break;
    case 3:
        Average(l);
    default:
        break;
    }
}