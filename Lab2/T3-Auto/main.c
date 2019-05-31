#include <stdio.h>
#include "lse.h"
#include "menu.h"
#include "tree.h"
#include <string.h>

int main()
{
    Node *test = createList();

    Car *c1 = (Car *)malloc(sizeof(Car));
    Car *c2 = (Car *)malloc(sizeof(Car));
    Car *c3 = (Car *)malloc(sizeof(Car));
    Car *c4 = (Car *)malloc(sizeof(Car));

    c1->year = 1998;
    c2->year = 1997;
    c3->year = 1999;
    c4->year = 1900;
    strcpy(c1->brand, "FORD");
    strcpy(c2->brand, "WOLKS");
    strcpy(c3->brand, "FIAT");
    strcpy(c4->brand, "FERRARI");
    strcpy(c1->license_p, "abcd123");
    strcpy(c2->license_p, "abcd223");
    strcpy(c3->license_p, "aacd123");
    strcpy(c4->license_p, "abcc113");
    //CARROS INSERIDOS PARA TESTAR MAIS RAPIDO AS FUNÇÕES A PARTIR DOS MENUS
    test = insert_in_order(test, c1);
    test = insert_in_order(test, c2);
    test = insert_in_order(test, c3);
    test = insert_in_order(test, c4);

    mainMenu(test);
}