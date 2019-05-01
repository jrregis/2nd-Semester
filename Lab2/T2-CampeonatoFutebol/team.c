#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lseVoid.h"
#include "team.h"
#include "player.h"
#include "coach.h"
#include "menu.h"
#include "match.h"

void printDataTeam(void *team)
{
    Team *t = (Team *)team;
    printf("TIME: %s\n\tGOLS FEITOS: %d  -  GOLS SOFRIDOS: %d\n", t->name, t->goal_done, t->goal_conceded);
    printf("\tFALTAS: %d\n\tCARTOES AMARELOS: %d\n\tCARTOES VERMELHOS: %d\n", t->fault, t->card_y, t->card_r);
}

void showDataTeam(Node *team)
{
    show(team, &printDataTeam);
}
void printRank(void *team)
{
    Team *t = (Team *)team;
    printf("\nTIME : %s\nPONTOS: %d\n", t->name, t->points);
}

void showRank(Node *head)
{
    show(head, &printRank);
}

void incRank(Node *team)
{
    int len = lenList(team);
}

void printTeam(void *team)
{
    Team *t = (Team *)team;
    printf("\n");
    printf("%d - %s\n", t->id_team, t->name);
    printf("%s, %s\n", t->home, t->city);
    printf("%d/%d/%d\n", t->d, t->m, t->y);
    printf("GOLS FEITOS: %d\n", t->goal_done);
    printf("GOLS SOFRIDOS: %d\n", t->goal_conceded);
    printf("FALTAS COMETIDAS: %d\n", t->fault);
    printf("AMARELOS: %d\n", t->card_y);
    printf("VERMELHOS: %d\n", t->card_r);
    printf("PONTOS: %d\n", t->points);

    if (t->players != NULL)
        printf("\nJOGADORES DO TIME");
    showPlayers(t->players);
    if (t->selection != NULL)
        showPlayers(t->selection);
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

void readTeam(Node *teams, Node *player, Node *coach, Node *match, Node *round)
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
    system("clear");
    menuInclude(teams, player, coach, match, round);
}

void registerPlayer(Team *team, Player *player)
{
    team->quanty_players++;
    if (team->quanty_players <= 25)
        team->players = insertEnd(team->players, player);
}

void unregisterPlayer(Team *team, int id)
{
    if (searchPlayer(team->players, id))
        team->players = removePlayer(team->players, id);
    else
        printf("JOGADOR %d NÃO ESTA NESSE TIME\n", id);
}
