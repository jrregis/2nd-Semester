#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lseVoid.h"
#include "team.h"
#include "player.h"
#include "coach.h"
#include "menu.h"

void printRankPlayer(void *player)
{
    Player *p = (Player *)player;
    printf("%d\t- %s \tGOLS: %d\n", p->id_player, p->name, p->goal);
}

void showRankPlayer(Node *player)
{
    show(player, &printRankPlayer);
}
void printDataPlayer(void *player)
{
    Player *p = (Player *)player;
    printf("%d - %s\n\tGOLS: %d\n\tCARTOES AMARELOS:    %d", p->id_player, p->name, p->goal, p->card_y);
    printf("\n\tCARTOES VERMELHOS : % d\n\tFALTAS COMETIDAS :   %d\n ", p->card_r, p->fault);
}

void showDataPlayer(Node *player)
{
    show(player, &printDataPlayer);
}

void printHeaderPLayer(void *player)
{
    Player *p = (Player *)player;
    printf("%s - %d\n", p->name, p->id_player);
}

void showHeaderPlayer(Node *player)
{
    show(player, &printHeaderPLayer);
}

void printPlayer(void *player)
{
    Player *p = (Player *)player;
    printf("\nID: %d NOME: %s \nPOSICAO %s\n", p->id_player, p->name, p->positon);
    printf("CAMISA: %d IDADE %d\n", p->number, p->age);
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

// PARA QUESTÕES DE TESTES, CRIA OS JOGADORES COM O CAMPO GOLS JÁ POPULADO
Player *createPlayerG(char name[50], char position[50], int age, int number, int id_player, int goal)
{
    Player *p = createPlayer(name, position, age, number, id_player);
    p->goal = goal;
}
void readPlayer(Node *team, Node *players, Node *coach, Node *match, Node *round)
{
    char name[50], position[50];
    int age, number, id;

    printf("DIGITE O NOME DO JOGADOR: ");
    scanf("%s", name);

    printf("DIGITE UMA DAS POSICOES ABAIXO:\n");
    printf("GL-ZG-LE-LD-MC-ATA: ");
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

    players = insertEnd(players, createPlayer(name, position, age, number, id));

    system("clear");
    menuInclude(team, players, coach, match, round);
}