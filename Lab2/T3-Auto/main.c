#include <stdio.h>
#include "lse.h"
#include "menu.h"
#include <string.h>

int main()
{
    Node *test = createList();
    Node *test2 = createList();

    Car c1, c2, c3, c4;
    c1.year = 1998;
    c2.year = 1997;
    c3.year = 1999;
    c4.year = 2000;
    strcpy(c1.brand, "FORD");
    strcpy(c2.brand, "WOLKS");
    strcpy(c3.brand, "FIAT");
    strcpy(c4.brand, "FERRARI");
    strcpy(c1.license_p, "abcd123");
    strcpy(c2.license_p, "abcd223");
    strcpy(c3.license_p, "aacd123");
    strcpy(c4.license_p, "abcc113");
    test = insert_in_order(test, c1);
    test = insert_in_order(test, c2);
    test = insert_in_order(test, c3);
    test = insert_in_order(test, c4);
    /*test = insert_in_order(test, createCar());
    test2 = insert_in_order(test2, *searchCar(test, "abcd123"));
    show(test2);
    printf("PRINTANDO CARROS:\n");
    show(test);
    test = removeCar(test, "aacd123");
    printf("removido:\n");
    show(test);
    printf("Liberando teste\n");
    test = freeList(test);
    show(test);*/

    mainMenu(test);
}