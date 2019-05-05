#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lseVoid.h"
#include "match.h"
#include "round.h"

bool equalRound(void *round, int id)
{
    return ((Round *)round)->id_round == id;
}

Round *createRound(int id_round)
{
    Round *r = (Round *)malloc(sizeof(Round));
    r->id_round = id_round;
    return r;
}
void readRound(Node *round)
{
    int id_round;

    printf("DIGITE O ID DA RODADA:\n");
    do
    {
        scanf("%d", &id_round);
    } while (searchRound(round, id_round) != NULL);

    round = insertEnd(round, createRound(id_round));
}

Round *searchRound(Node *round, int id)
{
    return (Round *)searching(round, id, &equalRound);
}

Node *removeRound(Node *round, int id)
{
    return removeNode(round, id, &equalRound);
}
void printRound(void *round)
{
    Round *r = (Round *)round;

    printf("RODADA NR: %d \n", r->id_round);
    printf("PARTIDAS DA RODADA:\n");
    if (r->match == NULL)
        printf("RODADA SEM PARTIDAS\n");
    else
        showMatch(r->match);
}

void showRound(Node *head)
{
    show(head, &printRound);
}

void registerMatch(Round *round, Match *m)
{
    round->match = insertEnd(round->match, m);
}