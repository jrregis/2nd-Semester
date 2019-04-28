#ifndef PLAYER_H
#define PLAYER_H
#include "lseVoid.h"

typedef struct
{
    char name[50], positon[50];
    int age, number, id_player;
    int card_y, card_r, goal, fault;
} Player;

Player *createPlayer(char name[50], char position[50], int age, int number, int id_player);
Player *searchPlayer(Node *players, int id);
Node *removePlayer(Node *players, int id);
bool equalPlayer(void *player, int id);
void printPlayer(void *palyer);
void showPlayers(Node *head);
void readPlayer(Node *team, Node *players, Node *coach);

#endif