#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main()
{
    node *l = NULL, *l2 = NULL;
    int equal = 0;
    l = insertNode(l, "test");
    l2 = insertNode(l2, "test");
    printNode(l);
    printNode(l2);
    equal = equalInfoNode(l, l2);
    if (equal == 0)
        printf("Info das duas listas sao iguais\n");
    if (equal < 0)
        printf("Info da lista 1 eh menor que da lista 2\n");
    if (equal > 0)
        printf("Info da lista 1 eh maior que da lista 2\n");
}