#include <stdio.h>
#include <stdlib.h>
#include "node.h"

node2 *insertNode(node2 *head, int element)
{
    node2 *new_node = (node2 *)malloc(sizeof(node2));
    new_node->info = element;

    return new_node;
}

void printNode(node2 *head)
{
    node2 *p;
    if (head == NULL)
        printf("Lista vazia\n");
    for (p = head; p != NULL; p != head)
        printf("INFO: %d \n", p->info);
}