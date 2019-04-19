#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

void printNode(node *l)
{
    node *p;
    for (p = l; p != NULL; p = p->next)
    {
        printf("Info: %s\n", p->info);
    }
}

node *insertElement(node *l, char *text)
{
    node *new_node = (node *)malloc(sizeof(node));
    strcpy(new_node->info, text);
    if (l == NULL)
        new_node->next = NULL;
    else
        new_node->next = l;
    return new_node;
}

node *copyNode(node *l)
{
    node *new_node = (node *)malloc(sizeof(node));
    if (l == NULL)
        new_node = NULL;
    else
    {
        strcpy(new_node->info, l->info);
        new_node->next = l->next;
    }

    return new_node;
}