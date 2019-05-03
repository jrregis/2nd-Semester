#ifndef COACH_H
#define COACH_H
#include "lseVoid.h"

typedef struct
{
    char name[50];
    int id_coach;
} Coach;

Coach *createCoach(char name[50], int id); //ALOCA A VARIAVEL DO TIPO TÉCNICO E PREENCHE A MESMA
Coach *searchCoach(Node *coachs, int id);  //BUSCA UM TÉCNICO NA LISTA DE TÉCNICOS
Node *removeCoach(Node *coachs, int id);   //REMOVE UM TÉCNICO DA LISTA DE TÉCNICOS
bool equalCoach(void *coach, int id);      //VERIFICA SE A ID DO TÉCNICO É IGUAL A DIGITA
void printCoach(void *coach);
void showCoachs(Node *coachs);                                                    //MOSTRA NA TELA OS TECNICOS
void readCoach(Node *team, Node *player, Node *coachs, Node *match, Node *round); //LE AS INFORMAÇÕES DO TÉCNICO

#endif