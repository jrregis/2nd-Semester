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

node *mergeNode(node *l, node *l2)
{
    node *p = l, *new_node;
    if (p == NULL)
        return l2;
    if (l2 == NULL)
        return p;
    do
    {
        new_node = p;
        p = p->next;
    } while (p != NULL);
    new_node->next = l2;
    return l;
}