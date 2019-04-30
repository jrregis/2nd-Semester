#ifndef COACH_H
#define COACH_H
#include "lseVoid.h"

typedef struct
{
    char name[50];
    int id_coach;
} Coach;

Coach *createCoach(char name[50], int id);
Coach *searchCoach(Node *coachs, int id);
Node *removeCoach(Node *coachs, int id);
bool equalCoach(void *coach, int id);
void printCoach(void *coach);
void showCoachs(Node *coachs);
void readCoach(Node *team, Node *player, Node *coachs, Node *match, Node *round);

#endif