#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lseVoid.h"
#include "team.h"
#include "player.h"
#include "coach.h"

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