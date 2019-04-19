#include <stdio.h>
#include <stdlib.h>
#include "node.h"
int main()
{
    node *l;
    l = Create();
    //l = (node *)malloc(sizeof(node));

    l = insertElement(l, 1);
    l = insertElement(l, 200);
    l = insertElement(l, 2);
    l = insertElement(l, 1);
    print(l);
    l = deleteElement(l, 1);
    printf("LISTA MODIFICADA:\n");
    print(l);
}