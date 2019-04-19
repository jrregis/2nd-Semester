#ifndef PLAYER_H
#define PLAYER_H
#include "lseVoid.h"

typedef struct
{
    char name[50], positon[50];
    int age, number, id_player;
} Player;

Player *createPlayer(char name[50], char position[50], int age, int number, int id_player);
Player *searchPlayer(Node *players, int id_player);
Player *removePlayer(Node *players, int id_player);

#endif