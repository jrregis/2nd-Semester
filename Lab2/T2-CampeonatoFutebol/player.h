#ifndef PLAYER_H
#define PLAYER_H
#include "lseVoid.h"

typedef struct
{
    char name[50], positon[50];
    int age, number, id_player;
    int card_y, card_r, goal, fault;
} Player;

Player *createPlayer(char name[50], char position[50], int age, int number, int id_player);            //ALOCA A INFORMAÇÃO DO TIPO JOGADOR E PREENCHE SEUS DADOS SEM GOLS
Player *createPlayerG(char name[50], char position[50], int age, int number, int id_player, int goal); //ALOCA A INFORMAÇÃO DO TIPO JOGADOR E PREENCHE SEUS DADOS COM GOLS
Player *searchPlayer(Node *players, int id);                                                           //BUSCA JOGADOR
Node *removePlayer(Node *players, int id);                                                             // EXCLUIR JOGADOR
bool equalPlayer(void *player, int id);                                                                //VERIFICA SE ID DO JOGADOR É IGUAL A DIGITADA
void printPlayer(void *palyer);
void showPlayers(Node *head);                                                      //MOSTRA OS JOGADORES
void readPlayer(Node *team, Node *players, Node *coach, Node *match, Node *round); //LÊ OS DOS JOGADORES
void showHeaderPlayer(Node *player);                                               //MOSTRA TIME TITULAR
void printHeaderPLayer(void *player);
void showDataPlayer(Node *player); //MOSTRA ESTATISTICAS DOS JOGADORES
void printDataPlayer(void *player);
void printRankPlayer(void *player);
void showRankPlayer(Node *player); //MOSTRA O RANK DO CAMPEONATA

#endif