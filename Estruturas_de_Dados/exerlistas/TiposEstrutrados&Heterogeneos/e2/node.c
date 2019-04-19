#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "node.h"

node *Insert(node *l, int id, char *name)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        newNode->info.id = id;
        strcpy(newNode->info.name, name);
        newNode->next = NULL;
    }
    else
    {
        newNode->info.id = id;
        strcpy(newNode->info.name, name);
        newNode->next = l;
    }
    return newNode;
}

void Show(node *l)
{
    node *p;
    for (p = l; p != NULL; p = p->next)
    {
        printf("Nome: %s\nId: %d\n", p->info.name, p->info.id);
    }
}