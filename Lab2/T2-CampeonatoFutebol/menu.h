#ifndef MENU_H
#define MENU_H
#include "lseVoid.h"
#include "match.h"

void mainMenu(Node *team, Node *player, Node *coach);

void menuSignUp(Node *team, Node *player, Node *coach);
void menuInclude(Node *team, Node *player, Node *coach);
void menuDelete(Node *team, Node *player, Node *coach);
void menuSearch(Node *team, Node *player, Node *coach);

void menuToTell(Node *team, Node *player, Node *coach);
void menuThrow(Match *m, Node *team, Node *player, Node *coach);
void menuNarration(Match *m, Node *team, Node *player, Node *coach);

void markGoal(Match *m, Node *team, Node *player, Node *coach);
void markFault(Match *m, Node *team, Node *player, Node *coach);
void replacePlayer(Match *m, Node *team, Node *player, Node *coach);
void playerOut(Match *m, Node *team, Node *player, Node *coach);
#endif