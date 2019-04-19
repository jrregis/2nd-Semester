#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

Node2 *Create(void)
{
    return NULL;
}
Node2 *Show(Node2 *l)
{
    Node2 *element;
    for (element = l; element != NULL; element = element->next)
        printf("Info= %d\n", element->info);
}
Node2 *LastElement(Node2 *l)
{
    Node2 *last = l;
    if (last != NULL)
    {
        while (last->next != NULL)
        {
            last = last->next;
        }
    }
    return last;
}
Node2 *InsertIni(Node2 *l, int n)
{
    Node2 *new = (Node2 *)malloc(sizeof(Node2));
    new->info = n;
    new->next = l;
    new->prev = NULL;
    if (l != NULL)
        l->prev = new;
    return new;
}
Node2 *InsertEnd(Node2 *l, int n)
{
    Node2 *last, *new;
    new = (Node2 *)malloc(sizeof(Node2));
    new->info = n;
    new->next = NULL;
    last = LastElement(l);
    if (last == NULL)
        return new;
    else
        last->next = new;
    new->prev = last;
    return (l);
}
Node2 *Search(Node2 *l, int n)
{
    Node2 *p;
    for (p = l; p != NULL; p = p->next)
    {
        if (p->info == n)
            return p;
    }
    return NULL;
}
Node2 *Delete(Node2 *l, int n)
{
    Node2 *p = Search(l, n);
    if (p == NULL)
        return l;
    if (l == p)
        l = p->next;
    else
        p->prev->next = p->next;
    if (p->next != NULL)
        p->next->prev = p->prev;
    free(p);
    return l;
}
Node2 *DeletePrev(Node2 *l, int n)
{
    Node2 *p = l;
    if (p == NULL) //lista vazia
        return l;
    else
    {
        if (p->info == n)
        {
            printf("Primeiro elemento da lista\n");
            return l;
        }
        while (p != NULL)
        {
            if (p->next != NULL)
                if (p->next->info == n)
                {
                    l = Delete(l, p->info);
                }
            p = p->next;
        }
        return l;
    }
}