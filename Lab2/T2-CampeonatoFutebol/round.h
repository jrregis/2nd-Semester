#ifndef ROUND_H
#define ROUND_H
#include "match.h"
#include "lseVoid.h"

typedef struct
{
    int id_round;
    Node *match;
} Round;

Round *createRound(int id_round);           //ALOCA INFORMAÇÕES DO TIPO RODADA
void readRound(Node *round);                //LE A RODADA
Round *searchRound(Node *round, int id);    //PROCURA A RODADA
void registerMatch(Round *round, Match *m); //INSERE PARTIDA NA RODADA
void showRound(Node *head);                 //MOSTRA A RODADA COM SUAS PARTIDAS
void printRound(void *round);
Node *removeRound(Node *round, int id); //DELETA RODADA
#endif