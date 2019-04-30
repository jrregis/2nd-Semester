#ifndef MATCH_H
#define MATCH_H
#include "team.h"

typedef struct
{
    char desc_throw;
    int min;

} Throw;

typedef struct
{
    Team *t1, *t2;
    Node *throw_s;
    int goal_t1, goal_t2, id_match;
} Match;

Match *createMatch(Node *team_head, Node *match);
void printMatch(void *match_head);
void showMatch(Node *head);
Match *searchMatch(Node *match, int id);
Node *removeMatch(Node *match, int id);
#endif