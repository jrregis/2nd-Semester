#ifndef TEAM_H
#define TEAM_H
#include "lseVoid.h"

typedef struct
{
    char name[50], home[50], city[50];
    int id_team, points, d, m, y;
    Node *players;
} Team;

Team *createTeam(char name[50], char home[50], char city[50], int d, int m, int y, int id_team);
Team *searchTeam(Node *teams, int id);
Node *removeTeam(Node *teams, int id);
void printTeam(void *team);
void showTeams(Node *head);
void readTeam(Node *teams);

#endif