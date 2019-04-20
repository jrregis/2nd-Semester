#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lseVoid.h"
#include "team.h"
#include "player.h"
#include "coach.h"

bool equalTeam(void *team, int id)
{
    return ((Team *)team)->id_team == id;
}

Node *removeTeam(Node *teams, int id)
{
    return removeNode(teams, id, &equalTeam);
}

Team *searchTeam(Node *team, int id)
{
    return (Team *)searching(team, id, &equalTeam);
}

Team *createTeam(char name[50], char home[50], char city[50], short dd, short mm, int yy, int id_team)
{
    Node *new_node;

    Team *t = (Team *)malloc(sizeof(Team));
    strcpy(t->name, name);
    strcpy(t->home, home);
    strcpy(t->city, city);
    t->foundation.dd = dd;
    t->foundation.mm = mm;
    t->foundation.yy = yy;
    t->id_team = id_team;

    return t;
}

void showTeam(void *team)
{
    Team *t = (Team *)team;
    printf("\n");
    printf("%d - %s\n", t->id_team, t->name);
    printf("%s ,%s\n", t->home, t->city);
    printf("%d/%d/%d\n", t->foundation.dd, t->foundation.mm, t->foundation.yy);
    printf("\n");
    showPlayers(t->players);
    printf("\n");
}

void showTeamS(Node *head)
{
    show(head, &showTeam);
}
