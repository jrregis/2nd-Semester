#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lseVoid.h"
#include "team.h"

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
    if (emptyList(head))
        return head;
    Node *last = head;
    while (last->next != NULL)
        last = last->next;
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

    Node *new_node = (Node *)malloc(sizeof(Node));

    lastNode(head);
    head->next = new_node;

    new_node->info = element;
    new_node->next = NULL;

    return new_node;
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

void searching(Node *head, void *element, bool equal(void *, void *))
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        if (equal(tmp->info, element))
            return tmp->info;
        tmp = tmp->next;
    }
    return NULL;
}

Node *removeNode(Node *head, void *element, bool equal(void *, void *))
{
    Node *prev = NULL;
    Node *tmp = head;

    while (!emptyList(head) && !equal(tmp->info, element))
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
