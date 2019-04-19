#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include <string.h>
#define T 0
#define S 1
nodeHet *InsertT(nodeHet *l, int id, float salary, char *name)
{
    teacher *t;
    nodeHet *newNode;
    t = (teacher *)malloc(sizeof(teacher));
    t->id = id;
    strcpy(t->name, name);
    t->salary = salary;
    newNode = (nodeHet *)malloc(sizeof(nodeHet));
    newNode->type = T;
    newNode->info = t;
    if (newNode == NULL)
        newNode->next = NULL;
    else
        newNode->next = l;
    return newNode;
}
nodeHet *InsertS(nodeHet *l, int id, char *name)
{
    student *s;
    nodeHet *newNode;
    s = (student *)malloc(sizeof(student));
    s->id = id;
    strcpy(s->name, name);
    newNode = (nodeHet *)malloc(sizeof(nodeHet));
    newNode->type = S;
    newNode->info = s;
    if (newNode == NULL)
        newNode->next = NULL;
    else
        newNode->next = l;
    return newNode;
}
void Print(nodeHet *l)
{
    nodeHet *p;
    for (p = l; p != NULL; p = p->next)
    {
        if (p->type == S)
        {
            student *s = (student *)p->info;
            printf("Aluno\nNome: %s \tId: %d\n", s->name, s->id);
        }
        if (p->type == T)
        {
            teacher *t = (teacher *)p->info;
            printf("Professor\nNome: %s \tId: %d \t Salario: %.4f\n", t->name, t->id, t->salary);
        }
    }
}