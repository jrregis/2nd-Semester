#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "node.h"

int main()
{
    node *l = NULL;
    l = Insert(l, 100, "Joao");
    l = Insert(l, 200, "Maria");
    Show(l);
}