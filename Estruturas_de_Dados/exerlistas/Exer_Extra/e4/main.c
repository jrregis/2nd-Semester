#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main()
{
    node *l = NULL;
    l = insertElement(l, 10);
    l = insertElement(l, 20);
    l = insertElement(l, 30);
    l = insertElement(l, 150);
    printNode(l);
    l = inverseNode(l);
    printf("Inverso:\n");
    printNode(l);
}