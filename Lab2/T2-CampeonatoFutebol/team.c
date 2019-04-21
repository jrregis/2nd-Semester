#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lseVoid.h"
#include "team.h"
#include "player.h"
#include "coach.h"

void printTeam(void *team)
{
    Team *t = (Team *)team;
    printf("\n");
    printf("%d - %s\n", t->id_team, t->name);
    printf("%s, %s\n", t->home, t->city);
    printf("%d/%d/%d\n", t->d, t->m, t->y);
    printf("\n");
    showPlayers(t->players);
    printf("\n");
}

void showTeams(Node *head)
{
    show(head, &printTeam);
}

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

Team *createTeam(char name[50], char home[50], char city[50], int d, int m, int y, int id_team)
{
    Node *new_node;

    Team *t = (Team *)malloc(sizeof(Team));
    strcpy(t->name, name);
    strcpy(t->home, home);
    strcpy(t->city, city);
    t->d = d;
    t->m = m;
    t->y = y;
    t->id_team = id_team;

    return t;
}

void readTeam(Node *teams)
{
    char name[50], home[50], city[50];
    int d, m, y, id;

    printf("DIGITE O NOME DO TIME: ");
    scanf("%s", name);

    printf("DIGITE O NOME DO ESTADIO: ");
    scanf("%s", home);

    printf("DIGITE O NOME DA CIDADE DO TIME: ");
    scanf("%s", city);

    printf("DIGITE O DIA DA FUNDAÇÃO DO TIME(DD/MM/YYYY): ");
    scanf("%d/%d/%d", &d, &m, &y);

    printf("DIGITE A ID DO TIME: ");
    do
    {
        if (searchTeam(teams, id) != NULL)
            printf("ID JA CADASTRADA DIGITE OUTRA: ");
        scanf("%d", &id);
    } while (searchTeam(teams, id) != NULL);

    insertEnd(teams, createTeam(name, home, city, d, m, y, id));
}
