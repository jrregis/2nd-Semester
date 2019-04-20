#ifndef TEAM_H
#define TEAM_H
#include "lseVoid.h"

typedef struct
{
    short dd, mm;
    int yy;
} Date;

typedef struct
{
    char name[50], home[50], city[50];
    Date foundation;
    int id_team, points;
    Node *players;
} Team;

Team *createTeam(char name[50], char home[50], char city[50], short dd, short mm, int yy, int id_team);
Team *searchTeam(Node *teams, int id);
Team *removeTeam(Node *teams, int id_team);
void showTeam(void *team);
void showTeamS(Node *head);

#endif