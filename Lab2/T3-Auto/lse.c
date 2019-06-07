#include <stdio.h>
#include "lse.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

Node *createList(void)
{
    return NULL;
}

bool emptyList(Node *head)
{
    return (head == NULL);
}

Node *insert_in_order(Node *head, Car *c)
{
    Node *new_node;
    Node *prev_node = createList();
    Node *aux = head;

    while (aux != NULL && strcmp(aux->info->license_p, c->license_p) < 0)
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
    Car *c;

    while (aux != NULL)
    {
        c = aux->info;

        if (strlen(c->brand) <= 7)
            printf("%s\t\t-  %s  -  %d\n\n", c->brand, c->license_p, c->year);
        else
            printf("%s\t-  %s  -  %d\n\n", c->brand, c->license_p, c->year);
        aux = aux->next;
    }
}

Car *searchCar(Node *head, char license_p[8])
{
    Node *tmp = head;

    while (tmp != NULL)
    {
        if (strcmp(tmp->info->license_p, license_p) == 0)
            return (Car *)tmp->info;
        tmp = tmp->next;
    }
    return NULL;
}

Node *removeCar(Node *head, char license_p[8])
{
    Node *prev = createList();
    Node *tmp = head;

    while (!emptyList(head) && strcmp(tmp->info->license_p, license_p) != 0)
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

Car *createCar(void)
{
    Car *c = (Car *)malloc(sizeof(Car));

    system("clear");
    printf("CADASTRO DE CARRO:\n");
    printf("DIGITE A PLACA NO FORMATO (XXXX111): ");
    scanf("%s", c->license_p);

    upperCase(c->license_p);

    printf("DIGITE A MARCA: ");
    scanf("%s", c->brand);

    upperCase(c->brand);

    printf("DIGITE O ANO: ");
    scanf("%d", &c->year);

    return c;
}

void printCar(Node *head, char license_p[8])
{
    Car *c = (Car *)malloc(sizeof(Car));

    if (searchCar(head, license_p) != NULL)
    {
        c = searchCar(head, license_p);

        printf("DADOS DO CARRO BUSCADO:\n");
        printf("PLACA: %s\nMARCA: %s\nANO:%d\n", c->license_p, c->brand, c->year);
    }
    else
        printf("CARRO NÃO CADASTRADO!\n");
}

void upperCase(char *license)
{
    for (int i = 0; i < strlen(license); i++)
        license[i] = toupper(license[i]);
}