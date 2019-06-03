#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "lse.h"
#include "tree.h"
void mainMenu(Node *head, Node_tree *license, Node_tree *brand, Node_tree *year);
void menuInclude(Node *head, Node_tree *license, Node_tree *brand, Node_tree *year);
void menuShow(Node *head, Node_tree *license, Node_tree *brand, Node_tree *year);
void menuSearchInList(Node *head, Node_tree *license, Node_tree *brand, Node_tree *year);
void menuSearchInTree(Node *head, Node_tree *license, Node_tree *brand, Node_tree *year);
void menuDelete(Node *head, Node_tree *license, Node_tree *brand, Node_tree *year);
void menuShowByList(Node *head, Node_tree *license, Node_tree *brand, Node_tree *year);
void menuShowOrderBrand(Node *head, Node_tree *license, Node_tree *brand, Node_tree *year);
void menuShowOrderYear(Node *head, Node_tree *license, Node_tree *brand, Node_tree *year);
void menuSearch(Node *head, Node_tree *license, Node_tree *brand, Node_tree *year);
void exitProgram(Node *head, Node_tree *license, Node_tree *brand, Node_tree *year);
char *upperCase(char *license);
char *readLicensePlate(char license_p[8]);
void menuBack(Node *head, Node_tree *license, Node_tree *brand, Node_tree *year);

#endif