#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lseVoid.h"
#include "team.h"
#include "player.h"
#include "coach.h"
#include "menu.h"

void printCoach(void *coach)
{
    Coach *c = (Coach *)coach;
    printf("\n");
    printf("%d - %s\n", c->id_coach, c->name);
    printf("\n");
}

void showCoachs(Node *coachs)
{
    show(coachs, &printCoach);
}

bool equalCoach(void *coach, int id)
{
    return ((Coach *)coach)->id_coach == id;
}

Node *removeCoach(Node *coachs, int id)
{
    return removeNode(coachs, id, &equalCoach);
}

Coach *searchCoach(Node *coach, int id)
{
    return (Coach *)searching(coach, id, &equalCoach);
}

Coach *createCoach(char name[50], int id_coach)
{
    Coach *c = (Coach *)malloc(sizeof(Coach));

    c->id_coach = id_coach;
    strcpy(c->name, name);

    return c;
}

void readCoach(Node *team, Node *player, Node *coachs, Node *match, Node *round)
{
    char name[50];
    int id;

    printf("DIGITE O NOME DO TECNICO: ");
    scanf("%s", name);

    printf("DIGITE O ID DO TECNICO: ");
    do
    {
        if (searchCoach(coachs, id) != NULL)
            printf("ID JA CADASTRADO, DIGITE OUTRO: ");
        scanf("%d", &id);
    } while (searchCoach(coachs, id) != NULL);

    insertEnd(coachs, createCoach(name, id));

    system("clear");
    menuInclude(team, player, coachs, match, round);
}