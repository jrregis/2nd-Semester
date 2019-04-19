#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include <string.h>

node *Insert(node *l, int id, char *name)
{
    node *newNode = (node *)malloc(sizeof(node));
    student *std = (student *)malloc(sizeof(student));
    std->id = id;
    strcpy(std->name, name);
    if (newNode == NULL)
    {
        newNode->info = std;
        newNode->next = NULL;
    }
    else
    {
        newNode->info = std;
        newNode->next = l;
    }
    return newNode;
}

void Show(node *l)
{
    node *p;
    for (p = l; p != NULL; p = p->next)
    {
        printf("Nome: %s\n Id: %d\n", p->info->name, p->info->id);
    }
}