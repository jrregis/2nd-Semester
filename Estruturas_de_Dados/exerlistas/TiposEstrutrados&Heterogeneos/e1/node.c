#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>

Node *Insert(Node *l, int id, char *name)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
    {
        p->id = id;
        strcpy(p->name, name);
        p->next = NULL;
    }
    else
    {
        p->id = id;
        strcpy(p->name, name);
        p->next = l;
    }
    return p;
}

Node *Print(Node *l)
{
    Node *p;
    for (p = l; p != NULL; p = p->next)
    {
        printf("Nome: %s  Id: %d\n", p->name, p->id);
    }
}