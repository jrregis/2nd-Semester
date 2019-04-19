#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include <string.h>

int main()
{
    nodeHet *l;
    l = InsertS(l, 255, "TestStudent");
    l = InsertT(l, 1, 21.987, "TestTeacher");
    Print(l);
}