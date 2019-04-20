#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lseVoid.h"
#include "team.h"
#include "player.h"
#include "coach.h"

bool equalPlayer(void *player, int id)
{
    return ((Player *)player)->id_player == id;
}

Node *removePlayer(Node *players, int id)
{
    return removeNode(players, id, &equalPlayer);
}

Player *searchPlayer(Node *player, int id)
{
    return (Player *)searching(player, id, &equalPlayer);
}

Player *createPlayer(char name[50], char position[50], int age, int number, int id_player)
{
    Player *p = (Player *)malloc(sizeof(Player));

    p->age = age;
    p->id_player = id_player;
    p->number = number;

    strcpy(p->name, name);
    strcpy(p->positon, position);
    return p;
}

void printPlayer(void *player)
{
    Player *p = (Player *)player;
    printf("\n");
    printf("ID: %d NOME: %s \nPOSICAO %s \nCAMISA: %d IDADE %d\n", p->id_player, p->name, p->positon, p->number, p->age);
    printf("\n");
}
void showPlayers(Node *players)
{
    show(players, &printPlayer);
}
