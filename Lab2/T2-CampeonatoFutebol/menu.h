#ifndef MENU_H
#define MENU_H
#include "lseVoid.h"
#include "match.h"

void mainMenu(Node *team, Node *player, Node *coach, Node *match, Node *round);

void menuSignUp(Node *team, Node *player, Node *coach, Node *match, Node *round);
void menuInclude(Node *team, Node *player, Node *coach, Node *match, Node *round);
void menuDelete(Node *team, Node *player, Node *coach, Node *match, Node *round);
void menuSearch(Node *team, Node *player, Node *coach, Node *match, Node *round);

void menuToTell(Node *team, Node *player, Node *coach, Node *match, Node *round);
void menuThrow(Match *m, Node *team, Node *player, Node *coach, Node *match, Node *round);
void menuNarration(Match *m, Node *team, Node *player, Node *coach, Node *match, Node *round);

void markGoal(Match *m, Node *team, Node *player, Node *coach, Node *match, Node *round);
void markFault(Match *m, Node *team, Node *player, Node *coach, Node *match, Node *round);
void replacePlayer(Match *m, Node *team, Node *player, Node *coach, Node *match, Node *round);
void playerOut(Match *m, Node *team, Node *player, Node *coach, Node *match, Node *round);
#endif