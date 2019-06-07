#include <stdio.h>
#include "lse.h"
#include "menu.h"
#include "tree.h"
#include <string.h>

int main()
{
    Node *list = createList();
    Node_tree *by_license = NULL;
    Node_tree *by_year = NULL;
    Node_tree *by_brand = NULL;

    Car *c1 = (Car *)malloc(sizeof(Car));
    Car *c2 = (Car *)malloc(sizeof(Car));
    Car *c3 = (Car *)malloc(sizeof(Car));
    Car *c4 = (Car *)malloc(sizeof(Car));
    Car *c5 = (Car *)malloc(sizeof(Car));
    Car *c6 = (Car *)malloc(sizeof(Car));
    Car *c7 = (Car *)malloc(sizeof(Car));
    Car *c8 = (Car *)malloc(sizeof(Car));
    Car *c9 = (Car *)malloc(sizeof(Car));
    Car *c10 = (Car *)malloc(sizeof(Car));

    c1->year = 1998;
    c2->year = 1997;
    c3->year = 1909;
    c4->year = 1900;
    c5->year = 2010;
    c6->year = 2019;
    c7->year = 2018;
    c8->year = 1500;
    c9->year = 2015;
    c10->year = 2001;

    strcpy(c1->brand, "FERRARI");
    strcpy(c2->brand, "VOLKSWAGEN");
    strcpy(c3->brand, "FORD");
    strcpy(c4->brand, "NISSAN");
    strcpy(c5->brand, "FERRARI");
    strcpy(c6->brand, "FIAT");
    strcpy(c7->brand, "HONDA");
    strcpy(c8->brand, "HYUNDAI");
    strcpy(c9->brand, "CHEVROLET");
    strcpy(c10->brand, "KIA");

    strcpy(c1->license_p, "MHM0472");
    strcpy(c2->license_p, "KFZ0319");
    strcpy(c3->license_p, "JKV1797");
    strcpy(c4->license_p, "BBH8741");
    strcpy(c5->license_p, "AEG5525");
    strcpy(c6->license_p, "PIW6624");
    strcpy(c7->license_p, "KEN5211");
    strcpy(c8->license_p, "LZO7001");
    strcpy(c9->license_p, "ZAO4233");
    strcpy(c10->license_p, "QMP3363");

    //CARROS INSERIDOS NA LISTA PARA TESTAR MAIS RAPIDO AS FUNÇÕES A PARTIR DOS MENUS
    list = insert_in_order(list, c1);
    list = insert_in_order(list, c2);
    list = insert_in_order(list, c3);
    list = insert_in_order(list, c4);
    list = insert_in_order(list, c5);
    list = insert_in_order(list, c6);
    list = insert_in_order(list, c7);
    list = insert_in_order(list, c8);
    list = insert_in_order(list, c9);
    list = insert_in_order(list, c10);

    //CARROS INSERIDOS NAS 3 ARVORES A PARTIR DA LISTA PARA TESTAR MAIS RAPIDO AS FUNÇÕES
    Node *aux = list;
    while (aux != NULL)
    {
        by_license = insertByLicense(by_license, searchCar(aux, aux->info->license_p));
        aux = aux->next;
    }

    aux = list;
    while (aux != NULL)
    {
        by_brand = insertByBrand(by_brand, searchCar(aux, aux->info->license_p));
        aux = aux->next;
    }

    aux = list;
    while (aux != NULL)
    {
        by_year = insertByYear(by_year, searchCar(aux, aux->info->license_p));
        aux = aux->next;
    }

    free(aux);
    /////////////////////OPÇÃO DE NAVEGAÇÃO POR MENU
    mainMenu(list, by_license, by_brand, by_year);

    //TESTES RÁPIDOS DAS FUNÇÕES
    //MOSTRANDO AS ORDENCOES DA LISTA PELA PLACA
    // E DAS ARVORES PELA MARCA E ANO RESPECTIVAMENTE
    /* printf("LISTA ORDENADA PELA PLACA\n");
    show(list);
    printf("PERCURSO DA ARVORE ORDENADO PELA MARCA:\n");
    showSimetricByBrand(by_brand);
    printf("PERCURSO DA ARVORE ORDENADO PELO ANO:\n");
    showSimetricByYear(by_year);

    ////EXCLUINDO ALGUNS CARROS
    list = removeCar(list, "MHM0472");
    by_license = removeNodeByLicense(by_license, c1);
    by_brand = removeNodeByBrand(by_brand, c1);
    by_year = removeNodeByYear(by_year, c1);

    list = removeCar(list, "MZO7001");
    by_license = removeNodeByLicense(by_license, c8);
    by_brand = removeNodeByBrand(by_brand, c8);
    by_year = removeNodeByYear(by_year, c8);

    list = removeCar(list, "JKV1797");
    by_license = removeNodeByLicense(by_license, c3);
    by_brand = removeNodeByBrand(by_brand, c3);
    by_year = removeNodeByYear(by_year, c3);

    list = removeCar(list, "AEG5525");
    by_license = removeNodeByLicense(by_license, c5);
    by_brand = removeNodeByBrand(by_brand, c5);
    by_year = removeNodeByYear(by_year, c5);

    //MOSTRANDO AS ORDENCOES DA LISTA PELA PLACA
    // E DAS ARVORES PELA MARCA E ANO RESPECTIVAMENTE
    printf("LISTA ORDENADA PELA PLACA APOS EXCLUSAO:\n");
    show(list);
    printf("PERCURSO DA ARVORE ORDENADO PELA MARCA APOS EXCLUSAO:\n");
    showSimetricByBrand(by_brand);
    printf("PERCURSO DA ARVORE ORDENADO PELO ANO APOS EXCLUSAO:\n");
    showSimetricByYear(by_year);

    by_license = destroyTree(by_license);
    by_brand = destroyTree(by_brand);
    by_year = destroyTree(by_year);
    list = freeList(list);*/
}