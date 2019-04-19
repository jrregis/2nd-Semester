#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void printNode(node *l)
{
    node *p;
    for (p = l; p != NULL; p = p->next)
        printf("INFO: %d\n", p->info);
}

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

node *inverseNode(node *l)
{
    node *current = l;
    node *next = l->next;
    node *temp = l->next; //percorrer encadeamento

    while (next != NULL)
    {
        temp = temp->next;

        next->next = current;

        current = next;

        next = temp;
    }
    l->next = NULL;
    l = current;
    return l;
}