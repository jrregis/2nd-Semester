#ifndef TEAM_H
#define TEAM_H
#include "lseVoid.h"
#include "player.h"
typedef struct
{
    char name[50], home[50], city[50];
    int id_team, d, m, y;
    int points, fault, card_y, card_r, quanty_players, goal_done, goal_conceded;
    Node *players, *selection;
} Team;
Team *createTeam(char name[50], char home[50], char city[50], int d, int m, int y, int id_team);             //ALOCA INFORMAÇÕES DO TIPO RODADA SEM PONTOS
Team *createTeamP(char name[50], char home[50], char city[50], int d, int m, int y, int id_team, int point); //ALOCA INFORMAÇÕES DO TIPO RODADA COM PONTOS
Team *searchTeam(Node *teams, int id);                                                                       //BUSCA TIME
Node *removeTeam(Node *teams, int id);                                                                       //REMOVE TIME
void printDataTeam(void *team);
void printTeam(void *team);
void showDataTeam(Node *team); //MOSTRA ESTATISTICAS DOS TIMES
void printRank(void *team);
void showRank(Node *head);                                                       //MOSTRA RANK DOS TIMES
void showTeams(Node *head);                                                      //MOSTRA OS TIMES
void readTeam(Node *teams, Node *player, Node *coach, Node *match, Node *round); //LE ENTRADA DE TIME
void registerPlayer(Team *team, Player *player);                                 //INCLUI JOGADOR NO TIME
void unregisterPlayer(Team *team, int id);                                       //REMOVE JOGADOR DO TIME
#endif