#include <stdio.h>
#include <stdlib.h>
#include "node.h"

node *insertElement(node *l, int element)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->info = element;
    if (l == NULL)
        new_node->next = NULL;
    else
        new_node->next = l;
    return new_node;
}

void printNode(node *l)
{
    node *p;
    for (p = l; p != NULL; p = p->next)
    {
        printf("Info: %d\n", p->info);
    }
}

node *separatingNode(node *l, int element)
{
    node *p, *new_node;

    for (p = l; p != NULL; p = p->next)
        if (p->info == element)
        {
            new_node = p->next;
            p->next = NULL;
            return new_node;
        }
    return NULL;
}