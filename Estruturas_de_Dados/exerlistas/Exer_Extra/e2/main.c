#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main()
{
    node *l = NULL, *l2 = NULL;
    l = insertElement(l, 50);
    l = insertElement(l, 550);
    l = insertElement(l, 300);
    l = insertElement(l, 100);
    l = insertElement(l, 10);
    //printNode(l);
    l2 = separatingNode(l, 100);
    printNode(l);
    printf("Nova lista:\n");
    printNode(l2);
}