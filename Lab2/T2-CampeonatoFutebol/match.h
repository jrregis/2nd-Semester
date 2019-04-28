#ifndef MATCH_H
#define MATCH_H
#include "team.h"

typedef struct
{
    Team *t1, *t2;
    int goal_t1, goal_t2, id_round, id_match;
} Match;

Match *createMatch(Node *team_head);
void printMatch(void *match_head);
void showMatch(Node *head);
Match *searchMatch(Node *match, int id);
Node *removeMatch(Node *match, int id);
#endif