#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
Node *Create(void)
{
    return NULL;
}
Node *InputFirstP(Node *l, int info)
{
    Node *element = (Node *)malloc(sizeof(Node));
    element->info = info;
    element->prox = l;
    return element;
}
Node *InputEnd(Node *l, int info)
{
    Node *p, *new;
    p = LastElement(l);
    new = (Node *)malloc(sizeof(Node));
    p->prox = new;
    new->info = info;

    new->prox = NULL;
    return (l);
}
Node *Show(Node *l)
{
    Node *element;
    for (element = l; element != NULL; element = element->prox)
        printf("Info= %d\n", element->info);
}
Node *LastElement(Node *l)
{
    Node *last = l;
    if (last != NULL)
    {
        while (last->prox != NULL)
        {
            last = last->prox;
        }
    }
    return last;
}
Node *ChangeSign(Node *l)
{
    Node *element;
    for (element = l; element != NULL; element = element->prox)
    {
        element->info = element->info * (-1);
    }
    return l;
}
void Average(Node *l)
{
    float average = 0;
    int elements = 0;
    Node *p;
    for (p = l; p != NULL; p = p->prox)
    {
        average += p->info;
        elements++;
    }
    printf("A media dos elementos da lista eh: %.2f\n", average / elements);
}
Node *DeletePrev(Node *l, int n)
{
    Node *prev = NULL, *p;
    while (p != NULL && p->info != v)
    {
        prev = p;
        p = p->prox;
    }
    if (p == NULL)
        return l;
    if (prev == NULL)
        return l;
    else
    {
    }
}