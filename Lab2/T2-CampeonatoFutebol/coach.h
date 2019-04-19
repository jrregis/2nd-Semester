#ifndef COACH_H
#define COACH_H
#include "lseVoid.h"

typedef struct
{
    char name[50];
    int id_coach;
} Coach;

Coach *createCoach(char name[50], int id_coach);
Coach *searchCoach(Node *coachs, int id_coach);
Coach *removeCoach(Node *coachs, int id_coach);

#endif