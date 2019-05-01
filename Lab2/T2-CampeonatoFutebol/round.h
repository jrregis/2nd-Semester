#ifndef ROUND_H
#define ROUND_H
#include "match.h"
#include "lseVoid.h"

typedef struct
{
    int id_round;
    Node *match;
} Round;

Round *createRound(int id_round);
void readRound(Node *round);
Round *searchRound(Node *round, int id);
void registerMatch(Round *round, Match *m);
void showRound(Node *head);
void printRound(void *round);
Node *removeRound(Node *round, int id);
#endif