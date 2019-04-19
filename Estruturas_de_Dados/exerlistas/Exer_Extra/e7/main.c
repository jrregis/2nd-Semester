#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main()
{
    node2 *head = NULL;
    head = insertNode(head, 40);
    head = insertNode(head, 10);
    head = insertNode(head, 20);
    head = insertNode(head, 30);
    printNode(head);
}