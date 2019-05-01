#ifndef MATCH_H
#define MATCH_H
#include "team.h"

typedef struct
{
    char desc_throw[30];
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

void printThrowOfMatch(void *match_head);
void showThrowOfMatch(Node *head);
#endif