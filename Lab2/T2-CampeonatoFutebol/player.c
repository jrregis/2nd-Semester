#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lseVoid.h"
#include "team.h"
#include "player.h"
#include "coach.h"
#include "menu.h"

void printPlayer(void *player)
{
    Player *p = (Player *)player;
    printf("\nID: %d NOME: %s \nPOSICAO %s \nCAMISA: %d IDADE %d\nGOLS: %d\nFALTAS: %d\nAMARELOS: %d\nVERMELHOS: %d\n", p->id_player, p->name, p->positon, p->number, p->age, p->goal, p->fault, p->card_y, p->card_r);
}
void showPlayers(Node *players)
{
    show(players, &printPlayer);
}

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
void readPlayer(Node *team, Node *players, Node *coach)
{
    char name[50], position[50];
    int age, number, id;

    printf("DIGITE O NOME DO JOGADOR: ");
    scanf("%s", name);

    printf("DIGITE A POSIÇÃO: ");
    scanf("%s", position);

    printf("DIGITE O NUMERO DO JOGADOR: ");
    scanf("%d", &number);

    printf("DIGITE A IDADE DO JOGADOR: ");
    scanf("%d", &age);

    do
    {
        printf("DIGITE A ID DO JOGADOR: ");
        scanf("%d", &id);
    } while (searchPlayer(players, id) != NULL);

    insertEnd(players, createPlayer(name, position, age, number, id));

    system("clear");
    menuInclude(team, players, coach);
}