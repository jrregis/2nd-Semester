#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "lse.h"
#include "tree.h"
void exitProgram(Node *head, Node_tree *license, Node_tree *brand, Node_tree *year);
void menuSign(Node *head, Node_tree *license, Node_tree *brand, Node_tree *year);
void mainMenu(Node *head, Node_tree *license, Node_tree *brand, Node_tree *year);

void menuInclude(Node *head, Node_tree *license, Node_tree *brand, Node_tree *year)
{
    Car *c = createCar();
    if (searchCar(head, c->license_p) == NULL)
    {
        head = insert_in_order(head, c);

        license = insertByLicense(license, c);
        brand = insertByBrand(brand, c);
        year = insertByYear(year, c);
    }
    else
    {
        printf("JA POSSUI UM CARRO CADASTRADO NO SISTEMA COM ESSA PLACA!\n");
        printf("TENTE NOVAMENTE COM UMA PLACA DIFERENTE!\n");
        sleep(3);
    }

    mainMenu(head, license, brand, year);
}

void menuSearchInList(Node *head, Node_tree *license, Node_tree *brand, Node_tree *year)
{
    int op;
    char license_p[8];
    system("clear");
    printf("\t\tBUSCA PELA LISTA\n");
    printf("DIGITE A PLACA A SER BUSCADA: ");
    scanf("%s", license_p);

    for (int i = 0; i < strlen(license_p); i++)
        license_p[i] = toupper(license_p[i]);

    printCar(head, license_p);

    printf("\n\n[0]VOLTAR\n[1]SAIR ");
    scanf("%d", &op);
    switch (op)
    {
    case 0:
        mainMenu(head, license, brand, year);
        break;
    case 1:
        exitProgram(head, license, brand, year);
    }
}

void menuSearchInTree(Node *head, Node_tree *license, Node_tree *brand, Node_tree *year)
{
    system("clear");
    printf("\t\tBUSCA PELA ARVORE:\n");

    char license_p[8];
    printf("DIGITE A PLACA: ");
    scanf("%s", license_p);

    for (int i = 0; i < strlen(license_p); i++)
        license_p[i] = toupper(license_p[i]);

    Node_tree *see = search(license, license_p);

    if (see != NULL)
    {
        Car *car = see->c;
        printf("DADOS DO CARRO BUSCADO:\n");
        printf("PLACA:%s\nMARCA:%s\nANO:%d\n", car->license_p, car->brand, car->year);
    }
    else
        printf("CARRO NAO CADASTRADO\n");

    free(see);

    int op;
    printf("\n\n[0]VOLTAR\n[1]SAIR ");
    scanf("%d", &op);
    switch (op)
    {
    case 0:
        mainMenu(head, license, brand, year);
        break;
    case 1:
        exitProgram(head, license, brand, year);
    }
}

void menuDelete(Node *head, Node_tree *license, Node_tree *brand, Node_tree *year)
{
    int op;
    char license_p[8];
    Car *c;
    system("clear");
    printf("DIGITE A PLACA DO CARRO AS SER EXCLUIDO: ");
    scanf("%s", license_p);

    for (int i = 0; i < strlen(license_p); i++)
        license_p[i] = toupper(license_p[i]);

    if (searchCar(head, license_p) != NULL)
    {
        c = searchCar(head, license_p);

        license = removeNodeByLicense(license, c);
        brand = removeNodeByBrand(brand, c);
        year = removeNodeByYear(year, c);

        head = removeCar(head, license_p);
        printf("CARRO EXCLUIDO!\n");
    }

    else
        printf("CARRO NÃO CADASTRADO!\n");

    printf("\n\n[0]VOLTAR\n[1]SAIR ");
    scanf("%d", &op);
    switch (op)
    {
    case 0:
        mainMenu(head, license, brand, year);
        break;
    case 1:
        exitProgram(head, license, brand, year);
    }
}

void menuShowByList(Node *head, Node_tree *license, Node_tree *brand, Node_tree *year)
{
    int op;
    system("clear");
    printf("\t\tCARROS POR PLACA\nUSANDO A LISTA\n");
    printf("MARCA\t\t    PLACA      ANO\n");
    show(head);

    printf("\n\n[0]VOLTAR\n[1]SAIR ");
    scanf("%d", &op);
    switch (op)
    {
    case 0:
        mainMenu(head, license, brand, year);
        break;
    case 1:
        exitProgram(head, license, brand, year);
    }
}

void menuShowOrderBrand(Node *head, Node_tree *license, Node_tree *brand, Node_tree *year)
{
    system("clear");
    printf("\t\tCARROS POR MARCA\nUSANDO ARVORE\n");
    printf("MARCA\t\t    PLACA      ANO\n");

    showSimetricByBrand(brand);

    int op;
    printf("\n\n[0]VOLTAR\n[1]SAIR ");
    scanf("%d", &op);
    switch (op)
    {
    case 0:
        mainMenu(head, license, brand, year);
        break;
    case 1:
        exitProgram(head, license, brand, year);
    }
}

void menuShowOrderYear(Node *head, Node_tree *license, Node_tree *brand, Node_tree *year)
{
    system("clear");
    printf("\t\tCARROS PELO ANO\nUSANDO ARVORE\n");
    printf("MARCA\t\t    PLACA      ANO\n");

    showSimetricByYear(year);

    int op;
    printf("\n\n[0]VOLTAR\n[1]SAIR ");
    scanf("%d", &op);
    switch (op)
    {
    case 0:
        mainMenu(head, license, brand, year);
        break;
    case 1:
        exitProgram(head, license, brand, year);
    }
}

void menuSearch(Node *head, Node_tree *license, Node_tree *brand, Node_tree *year)
{
    int op;
    system("clear");
    printf("\t\tBUSCA DE VEICULOS CADASTRADOS\n");
    printf("0 - BUSCAR PELA LISTA\n1 - BUSCAR PELA ARVORE\n2 - VOLTAR\n");
    scanf("%d", &op);

    switch (op)
    {
    case 0:
        menuSearchInList(head, license, brand, year);
        break;
    case 1:
        menuSearchInTree(head, license, brand, year);
        break;
    case 2:
        mainMenu(head, license, brand, year);
        break;
    default:
        exitProgram(head, license, brand, year);
    }
}

void mainMenu(Node *head, Node_tree *license, Node_tree *brand, Node_tree *year)
{
    int op;
    system("clear");
    printf("\t\tSISTEMA DE CONTROLE DE CARROS\n");
    printf("0 - INCLUIR\n1 - EXCLUIR\n2 - BUSCAR\n3 - LISTAR CARROS PELA PLACA\n4 - LISTAR CARROS PELA MARCA\n5 - LISTAR CARROS PELO ANO\n6 - SAIR\n");
    scanf("%d", &op);

    switch (op)
    {
    case 0:
        menuInclude(head, license, brand, year);
        break;
    case 1:
        menuDelete(head, license, brand, year);
        break;
    case 2:
        menuSearch(head, license, brand, year);
        break;
    case 3:
        menuShowByList(head, license, brand, year);
        break;
    case 4:
        menuShowOrderBrand(head, license, brand, year);
        break;
    case 5:
        menuShowOrderYear(head, license, brand, year);
        break;
    default:
        exitProgram(head, license, brand, year);
        break;
    }
}

void exitProgram(Node *head, Node_tree *license, Node_tree *brand, Node_tree *year)
{
    license = destroyTree(license);
    brand = destroyTree(brand);
    year = destroyTree(year);
    head = freeList(head);
    exit(1);
}