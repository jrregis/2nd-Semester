#ifndef MATCH_H
#define MATCH_H
#include "team.h"
typedef struct
{
    char desc_throw[30];
    int min;

} Throw;
typedef struct
{
    Team *t1, *t2;
    Node *throw_s;
    int goal_t1, goal_t2, id_match;
} Match;
Match *createMatch(Node *team_head, Node *match); //ALOCA A INFORMAÇÃO DO TIPO PARTIDA E PRENCHE ALGUNS DADOS(TIMES E ID)
void printMatch(void *match_head);
void showMatch(Node *head);              //MOSTRA A PARTIDA
Match *searchMatch(Node *match, int id); //BUSCA A PARTIDA
Node *removeMatch(Node *match, int id);  //REMOVE A PARTIDA
void printThrowOfMatch(void *match_head);
void showThrowOfMatch(Node *head); //MOSTRA OS LANCES SALVOS NA LISTA DE LANCES DENTRO DA PARTIDA
#endif