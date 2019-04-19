#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include <string.h>

int main()
{
    node *l = NULL;

    l = Insert(l, 256, "Test");
    Show(l);
}