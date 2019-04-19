#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include "node.h"

int main()
{
    int op = 0;
    Node2 *l;
    l = Create();
    l = InsertIni(l, 500);
    l = InsertIni(l, 5);
    //l = InsertIni(l, 50);
    //l = InsertIni(l, 100);
    l = InsertIni(l, 200);
    Show(l);
    printf("Exercicios\n1-e1 2-e2\n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        l = InsertEnd(l, 99);
        l = InsertEnd(l, 81);
        Show(l);
        break;
    case 2:
        l = DeletePrev(l, 5);
        Show(l);
    }
}
