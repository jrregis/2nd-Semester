#include <stdio.h>
#include <stdlib.h>
#include "node.h"
node *Create(void)
{
    return NULL;
}
node *insertElement(node *l, int element)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->info = element;
    if (l == NULL)
        newNode->next = NULL;
    else
        newNode->next = l;
    return newNode;
}

void print(node *l)
{
    node *p;
    for (p = l; p != NULL; p = p->next)
    {
        printf("Info: %d\n", p->info);
    }
}

node *searchElement(node *l, int element)
{
    node *p;
    for (p = l; p != NULL; p = p->next)
    {
        if (p->info == element)
            return p;
    }
    return NULL;
}
node *deleteElement(node *l, int element)
{
    node *previous = NULL;
    node *p = l;
    while (p != NULL && p->info != element)
    {
        previous = p;
        p = p->next;
    }
    if (p == NULL) //não existe o elemento na lista
        return l;
    if (previous == NULL) //elemento eh o primeiro da lista
        l = p->next;
    else // elemento esta no meio da list
        previous->next = p->next;
    free(p);
    deleteElement(l, element);
}
