#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

void printNode(node *l)
{
    node *p;
    for (p = l; p != NULL; p = p->next)
        printf("Info: %s\n", p->info);
}

node *insertNode(node *l, char *text)
{
    node *new_node = (node *)malloc(sizeof(node));
    strcpy(new_node->info, text);
    if (l == NULL)
        new_node->next = NULL;
    else
        new_node->next = l;
    return new_node;
}

int equalInfoNode(node *l, node *l2)
{
    int equal = 0;
    equal = strcmp(l->info, l2->info);
    return equal;
}