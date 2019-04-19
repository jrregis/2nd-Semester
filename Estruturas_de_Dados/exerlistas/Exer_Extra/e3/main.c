#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main()
{
    node *l = NULL, *l2 = NULL;
    l = insertElement(l, 10);
    l = insertElement(l, 20);

    l2 = insertElement(l2, 11);
    l2 = insertElement(l2, 22);

    printNode(l);
    printNode(l2);

    l = mergeNode(l, l2);
    printf("Uniao:\n");
    printNode(l);
}