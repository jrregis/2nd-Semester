#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main()
{
    node *l = NULL, *copy = NULL;
    l = insertElement(l, "test 0");
    l = insertElement(l, "test 1");
    l = insertElement(l, "test 2");
    printf("ORIGINAL %p\n", l);
    printNode(l);
    copy = copyNode(l);
    printf("COPIA    %p\n", copy);
    printNode(copy);
}