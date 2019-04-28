#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lseVoid.h"
#include "team.h"
#include "player.h"
#include "coach.h"
#include "match.h"

Match *createMatch(Node *team_head)
{
    Match *m = (Match *)malloc(sizeof(Match));

    int id_t1, id_t2;

    printf("DIGITE AS ID DOS TIMES\n");
    do
    {
        printf("TIME 1: ");
        scanf("%d", &id_t1);
    } while (searchTeam(team_head, id_t1) == NULL);

    m->t1 = searchTeam(team_head, id_t1);

    do
    {
        printf("TIME 2: ");
        scanf("%d", &id_t2);
    } while (searchTeam(team_head, id_t2) == NULL);

    m->t2 = searchTeam(team_head, id_t2);

    printf("DIGITE O ID DA PARTIDA \n");
    scanf("%d", &m->id_match);
    printf("DIGITE O ID DA RODADA \n");
    scanf("%d", &m->id_round);

    return m;
}

void printMatch(void *match_head)
{
    Match *m = (Match *)match_head;

    printf("\n");
    printf("RODADA: %d \n", m->id_round);
    printf("PARTIDA: %d \n", m->id_match);
    printf("%s vs %s \n", m->t1->name, m->t2->name);
}

void showMatch(Node *head)
{
    show(head, &printMatch);
}

bool equalMatch(void *match, int id)
{
    return ((Match *)match)->id_match == id;
}

Match *searchMatch(Node *match, int id)
{
    return (Match *)searching(match, id, &equalMatch);
}

Node *removeMatch(Node *match, int id)
{
    return removeNode(match, id, &equalMatch);
}