#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "lse.h"

void mainMenu(Node *head);
void menuSign(Node *head);
void menuInclude(Node *head);
void printCar(Node *head, char license_p[8]);
void menuShow(Node *head);
#endif
