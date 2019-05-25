#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "lse.h"
void menuSign(Node *head);
void printCar(Node *head, char license_p[8]);

void mainMenu(Node *head)
{
    int op, op1, i = 0;

    system("clear");
    printf("\t\tCARROS\n");
    printf("0 - CADASTROS\n");
    scanf("%d", &op);
    switch (op)
    {
    case 0:
        menuSign(head);
        break;
    }
}

void menuInclude(Node *head)
{
    head = insert_in_order(head, createCar());
    mainMenu(head);
}

void menuSearch(Node *head)
{
    int op;
    char license_p[8];
    system("clear");
    printf("DIGITE A PLACA A SER BUSCADA: ");
    scanf("%s", license_p);

    printCar(head, license_p);

    printf("\n\n[0]VOLTAR\n[1]SAIR ");
    scanf("%d", &op);
    switch (op)
    {
    case 0:
        menuSign(head);
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
        menuSign(head);
        break;
    case 1:
        exit(1);
    }
}
void menuSign(Node *head)
{
    int op;
    system("clear");
    printf("\t\tCADASTROS\n");
    printf("0 - INCLUIR\n1 - EXCLUIR\n2 - BUSCAR\n3 - VOLTAR\n");
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
        // mainMenu(head);
        break;
    default:
        exit(1);
        break;
    }
}

void printCar(Node *head, char license_p[8])
{
    Car *c;
    if (searchCar(head, license_p) != NULL)
    {
        c = searchCar(head, license_p);

        printf("DADOS DO CARRO BUSCADO:\n");
        printf("PLACA: %s\nMARCA: %s\nANO:%d\n", c->license_p, c->brand, c->year);
    }
    else
        printf("CARRO NÃO CADASTRADO!\n");
}