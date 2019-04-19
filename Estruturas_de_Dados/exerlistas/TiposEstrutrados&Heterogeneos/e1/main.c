#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include "node.h"

int main()
{
    Node *l = NULL;
    int op;
    int id = 0;
    char name[50];
    printf("Digite seu id: ");
    scanf("%d", &id);
    printf("Digite seu nome: ");
    scanf("%s", name);
    l = Insert(l, id, name);
    l = Insert(l, 3, "jao");
    printf("Imprimindo Lista..\n");
    Print(l);
}