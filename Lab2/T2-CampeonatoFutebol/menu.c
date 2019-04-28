#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "lseVoid.h"
#include "team.h"
#include "player.h"
#include "coach.h"
#include "match.h"
#include "menu.h"

void menuSearch(Node *team, Node *player, Node *coach)
{
    int op, id_team, id_player, id_coach;
    Team *t;
    Player *p;
    Coach *c;

    system("clear");
    printf("\t\tBUSCAR\n");
    printf("0 - TIME\n1 - JOGADOR\n2 - TECNICO\n3 - VOLTAR\n");
    scanf("%d", &op);

    switch (op)
    {
    case 0:
        printf("DIGITE A ID DO TIME A SER BUSCADO: ");
        scanf("%d", &id_team);
        t = searchTeam(team, id_team);
        if (t != NULL)
        {
            printTeam(t);
            printf("VOLTANDO AO MENU ANTERIOR...\n");
            sleep(5);
            menuSignUp(team, player, coach);
        }
        else
        {
            printf("TIME NAO CADASTRADO\n");
            printf("VOLTANDO AO MENU ANTERIOR...\n");
            sleep(2);
            menuSignUp(team, player, coach);
        }
        break;
    case 1:
        printf("DIGITE A ID DO JOGADOR A SER BUSCADO: ");
        scanf("%d", &id_player);
        p = searchPlayer(player, id_player);
        if (p != NULL)
        {
            printPlayer(p);
            printf("\n\nVOLTANDO AO MENU ANTERIOR...\n");
            sleep(5);
            menuSignUp(team, player, coach);
        }
        else
        {
            printf("JOGADOR NAO CADASTRADO\n");
            printf("VOLTANDO AO MENU ANTERIOR...\n");
            sleep(2);
            menuSignUp(team, player, coach);
        }
        break;
    case 2:
        printf("DIGITE A ID DO TECNICO A SER BUSCADO: ");
        scanf("%d", &id_coach);
        c = searchCoach(coach, id_coach);
        if (c != NULL)
        {
            printCoach(c);
            printf("VOLTANDO AO MENU ANTERIOR...\n");
            sleep(5);
            menuSignUp(team, player, coach);
        }
        else
        {
            printf("TECNICO NAO CADASTRADO\n");
            printf("VOLTANDO AO MENU ANTERIOR...\n");
            sleep(2);
            menuSignUp(team, player, coach);
        }
        break;
    case 3:
        menuSignUp(team, player, coach);

    default:
        break;
    }
}
void menuDelete(Node *team, Node *player, Node *coach)
{
    int op, id_team, id_player, id_coach;
    system("clear");
    printf("\t\tEXCLUIR\n");
    printf("0 - TIME\n1 - JOGADOR\n2 - TECNICO\n3 - VOLTAR\n");
    scanf("%d", &op);

    switch (op)
    {
    case 0:
        do
        {
            printf("DIGITE A ID DO TIME A SER EXCLUIDO: ");
            scanf("%d", &id_team);
        } while (searchTeam(team, id_team) == NULL);

        team = removeTeam(team, id_team);

        break;
    case 1:
        do
        {
            printf("DIGITE A ID DO JOGADOR A SER EXCLUIDO: ");
            scanf("%d", &id_player);
        } while (searchPlayer(player, id_player) == NULL);

        player = removePlayer(player, id_player);

        break;
    case 2:
        do
        {
            printf("DIGITE A ID DO TECNICO A SER EXCLUIDO: ");
            scanf("%d", &id_coach);
        } while (searchCoach(coach, id_coach) == NULL);

        coach = removeCoach(coach, id_coach);

        break;
    case 3:
        menuSignUp(team, player, coach);

    default:
        break;
    }
}
void menuInclude(Node *team, Node *player, Node *coach)
{
    int op;
    system("clear");
    printf("\t\tINCLUIR\n");
    printf("0 - TIME\n1 - JOGADOR\n2 - TECNICO\n3 - VOLTAR\n");
    scanf("%d", &op);

    switch (op)
    {
    case 0:
        readTeam(team, player, coach);
        break;
    case 1:
        readPlayer(team, player, coach);
        break;
    case 2:
        readCoach(team, player, coach);
        break;
    case 3:
        menuSignUp(team, player, coach);

    default:
        break;
    }
}
void menuSignUp(Node *team, Node *player, Node *coach)
{
    int op;
    system("clear");
    printf("\t\tCADATROS\n");
    printf("0 - INCLUIR\n1 - EXCLUIR\n2 - BUSCAR\n3 - VOLTAR\n");
    scanf("%d", &op);

    switch (op)
    {
    case 0:
        menuInclude(team, player, coach);
        break;
    case 1:
        menuDelete(team, player, coach);
        break;
    case 2:
        menuSearch(team, player, coach);
        break;
    case 3:
        mainMenu(team, player, coach);
        break;
    default:
        exit(1);
        break;
    }
}
void mainMenu(Node *team, Node *player, Node *coach)
{
    int op;
    printf("\t\tCAMPEONATO RAIZ DE FUTEBOL\n");
    printf("0 - CADASTROS\n1 - NARRAR\n2 - RELATORIOS\n3 - Testes\n");
    scanf("%d", &op);

    switch (op)
    {
    case 0:
        menuSignUp(team, player, coach);
        break;
    case 1:
        exit(1);
        // menuToTell();
        break;
    case 2:
        exit(1);
        // menuReport();
        break;
    case 3:
        showTeams(team);
        showPlayers(player);
        showCoachs(coach);
        break;

    default:
        exit(1);
        break;
    }
}