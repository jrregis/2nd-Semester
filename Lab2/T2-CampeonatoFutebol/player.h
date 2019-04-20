#ifndef PLAYER_H
#define PLAYER_H
#include "lseVoid.h"

typedef struct
{
    char name[50], positon[50];
    int age, number, id_player, goal;
} Player;

Player *createPlayer(char name[50], char position[50], int age, int number, int id_player);
Player *searchPlayer(Node *players, int id);
Node *removePlayer(Node *players, int id);

void showPlayer(void *palyer);
void showPlayers(Node *head);

#endif