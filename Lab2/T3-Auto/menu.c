#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "lse.h"
#include "tree.h"

void menuSign(Node *head);
void printCar(Node *head, char license_p[8]);
void mainMenu(Node *head);

void menuInclude(Node *head)
{
    head = insert_in_order(head, createCar());
    mainMenu(head);
}

void menuSearchInList(Node *head)
{
    int op;
    char license_p[8];
    system("clear");
    printf("\t\tBUSCA PELA LISTA\n");
    printf("DIGITE A PLACA A SER BUSCADA: ");
    scanf("%s", license_p);

    printCar(head, license_p);

    printf("\n\n[0]VOLTAR\n[1]SAIR ");
    scanf("%d", &op);
    switch (op)
    {
    case 0:
        mainMenu(head);
        break;
    case 1:
        exit(1);
    }
}

void menuSearchInTree(Node *head)
{
    system("clear");
    printf("\t\tBUSCA PELA ARVORE:\n");

    Node_tree *tree = NULL;
    Node *aux = head;
    while (aux != NULL)
    {
        tree = insertByLicense(tree, searchCar(aux, aux->info->license_p));
        aux = aux->next;
    }

    char license[8];
    printf("DIGITE A PLACA: ");
    scanf("%s", license);

    Node_tree *see = search(tree, license);

    if (see != NULL)
    {
        Car *car = see->c;
        printf("DADOS DO CARRO BUSCADO:\n");
        printf("PLACA:%s\nMARCA:%s\nANO:%d\n", car->license_p, car->brand, car->year);
    }
    else
        printf("CARRO NAO CADASTRADO\n");

    tree = destroyTree(tree);
    free(see);

    int op;
    printf("\n\n[0]VOLTAR\n[1]SAIR ");
    scanf("%d", &op);
    switch (op)
    {
    case 0:
        mainMenu(head);
        break;
    case 1:
        exit(1);
    }
}

void menuDelete(Node *head)
{
    int op;
    char license_p[8];
    system("clear");
    printf("DIGITE A PLACA DO CARRO AS SER EXCLUIDO: ");
    scanf("%s", license_p);

    if (searchCar(head, license_p) != NULL)
    {
        removeCar(head, license_p);
        printf("CARRO EXCLUIDO!\n");
    }

    else
        printf("CARRO NÃO CADASTRADO!\n");

    printf("\n\n[0]VOLTAR\n[1]SAIR ");
    scanf("%d", &op);
    switch (op)
    {
    case 0:
        mainMenu(head);
        break;
    case 1:
        exit(1);
    }
}

void menuShow(Node *head)
{
    int op;
    system("clear");
    printf("CARROS CADASTRADOS NO SISTEMA POR PLACA\n");
    printf("MARCA\t    PLACA      ANO\n");
    show(head);

    printf("\n\n[0]VOLTAR\n[1]SAIR ");
    scanf("%d", &op);
    switch (op)
    {
    case 0:
        mainMenu(head);
        break;
    case 1:
        exit(1);
    }
}

void menuSearch(Node *head)
{
    int op;
    system("clear");
    printf("\t\tBUSCA DE VEICULOS CADASTRADOS\n");
    printf("0 - BUSCAR PELA LISTA\n1 - BUSCAR PELA ARVORE\n2 - VOLTAR\n");
    scanf("%d", &op);

    switch (op)
    {
    case 0:
        menuSearchInList(head);
        break;
    case 1:
        menuSearchInTree(head);
        break;
    case 2:
        mainMenu(head);
        break;
    default:
        exit(1);
    }
}

void mainMenu(Node *head)
{
    int op;
    system("clear");
    printf("\t\tSISTEMA DE CONTROLE DE CARROS\n");
    printf("0 - INCLUIR\n1 - EXCLUIR\n2 - BUSCAR\n3 - LISTAR CARROS PELA LISTA\n4 - SAIR\n");
    scanf("%d", &op);

    switch (op)
    {
    case 0:
        menuInclude(head);
        break;
    case 1:
        menuDelete(head);
        break;
    case 2:
        menuSearch(head);
        break;
    case 3:
        menuShow(head);
        break;
    case 4:
        mainMenu(head);
        break;
    default:
        exit(1);
        break;
    }
}