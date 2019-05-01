#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lseVoid.h"
#include "team.h"
#include "coach.h"
#include "player.h"

Node *createList(void)
{
    return NULL;
}

bool emptyList(Node *head)
{
    return (head == NULL);
}

Node *lastNode(Node *head)
{
    Node *last = NULL;
    last = head;
    if (emptyList(head))
        return head;

    while (last->next != NULL)
    {
        last = last->next;
    }
    return last;
}

Node *insertTop(Node *head, void *element)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->info = element;
    new_node->next = head;
    return new_node;
}

Node *insertEnd(Node *head, void *element)
{
    if (emptyList(head))
        return insertTop(head, element);

    Node *new_node, *p = NULL;
    p = lastNode(head);

    new_node = (Node *)malloc(sizeof(Node));

    p->next = new_node;

    new_node->info = element;
    new_node->next = NULL;

    return head;
}

void show(Node *head, void showElement(void *))
{
    if (!emptyList(head))
    {
        Node *tmp = head;
        while (!emptyList(tmp))
        {
            showElement(tmp->info);
            tmp = tmp->next;
        }
    }
}

void *searching(Node *head, int id, bool equal(void *, int))
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        if (equal(tmp->info, id))
            return tmp->info;
        tmp = tmp->next;
    }
    return NULL;
}

Node *removeNode(Node *head, int id, bool equal(void *, int))
{
    Node *prev = NULL;
    Node *tmp = head;

    while (!emptyList(head) && !equal(tmp->info, id))
    {
        prev = tmp;
        tmp = tmp->next;
    }

    if (emptyList(tmp))
        return head;

    if (prev == NULL)
        head = tmp->next;

    else
        prev->next = tmp->next;
    free(tmp);
    return head;
}

Node *freeList(Node *head)
{
    while (!emptyList(head))
    {
        Node *tmp = head->next;
        free(head);
        head = tmp;
    }
    return NULL;
}

int lenList(Node *head)
{
    int i = 0;
    Node *tmp = head;
    while (tmp != NULL)
    {
        i++;
        tmp = tmp->next;
    }
    return i;
}