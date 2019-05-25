#include <stdio.h>
#include "lse.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

Node *createList(void)
{
    return NULL;
}

bool emptyList(Node *head)
{
    return (head == NULL);
}

Node *insert_in_order(Node *head, Car c)
{
    int len;
    Node *new_node;
    Node *prev_node = createList();
    Node *aux = head;

    while (aux != NULL && strcmp(aux->info.license_p, c.license_p) < 0)
    {
        prev_node = aux;
        aux = aux->next;
    }

    new_node = (Node *)malloc(sizeof(Node));
    new_node->info = c;

    if (prev_node == NULL)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        new_node->next = prev_node->next;
        prev_node->next = new_node;
    }
    return head;
}

void show(Node *head)
{
    Node *aux = head;

    while (aux != NULL)
    {
        printf("%s\t-  %s  -  %d\n", aux->info.brand, aux->info.license_p, aux->info.year);
        aux = aux->next;
    }
}

Car *searchCar(Node *head, char license_p[8])
{
    Node *tmp = head;

    while (tmp != NULL)
    {
        if (strcmp(tmp->info.license_p, license_p) == 0)
            return (Car *)tmp;
        tmp = tmp->next;
    }
    return NULL;
}

Node *removeCar(Node *head, char license_p[8])
{
    Node *prev = createList();
    Node *tmp = head;

    while (!emptyList(head) && strcmp(tmp->info.license_p, license_p) != 0)
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

Car createCar(void)
{
    Car c;
    system("clear");
    printf("CADASTRO DE CARRO:\n");
    printf("DIGITE A PLACA NO FORMATO (XXXX111): ");
    scanf("%s", c.license_p);

    printf("DIGITE A MARCA: ");
    scanf("%s", c.brand);

    printf("DIGITE O ANO: ");
    scanf("%d", &c.year);

    return c;
}