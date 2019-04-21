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
    if (t->players != NULL)
        printf("\nJOGADORES DO TIME");
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

void registerPlayer(Team *team, Player *player)
{
    team->players = insertEnd(team->players, player);
}

void unregisterPlayer(Team *team, int id)
{
    team->players = removePlayer(team->players, searchPlayer(team->players, id));
}

void insertingPlayerInTeam(Node *team_head, Node *player_head)
{
    Team *t;
    int id_team, id_player;

    printf("DIGITE A ID DO TIME: ");
    scanf("%d", &id_team);

    if (searchTeam(team_head, id_team) == NULL)
    {
        printf("NAO HA TIMES CADASTRADOS COM ESSA ID\n");
        exit(EXIT_SUCCESS);
    }

    printf("DIGITE A ID DO JOGADOR: ");
    scanf("%d", &id_player);

    if (searchPlayer(player_head, id_player) == NULL)
    {
        printf("NAO HA JOGADORES CADASTRADOS COM ESSA ID\n");
        exit(EXIT_SUCCESS);
    }

    t = searchTeam(team_head, id_team);
    registerPlayer(t, searchPlayer(player_head, id_player));
}

void removingPlayerOfTeam(Node *team_head)
{
    Team *t;
    int id_team, id_player;

    printf("DIGITE A ID DO TIME: ");
    scanf("%d", &id_team);

    if (searchTeam(team_head, id_team) == NULL)
    {
        printf("TIME NAO CADASTRADO\n");
        exit(EXIT_SUCCESS);
    }
    else
        t = searchTeam(team_head, id_team);

    printf("DIGITE A ID DO JOGADOR: ");
    scanf("%d", &id_player);

    if (searchPlayer(t->players, id_player) == NULL)
    {
        printf("JOGADOR NAO CADASTRADO NO TIME\n");
        exit(EXIT_SUCCESS);
    }
    else
        unregisterPlayer(t, id_player);
}
