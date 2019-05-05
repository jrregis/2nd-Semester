#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lseVoid.h"
#include "team.h"
#include "player.h"
#include "coach.h"
#include "match.h"

Match *createMatch(Node *team_head, Node *match)
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

    do
    {
        printf("DIGITE O ID DA PARTIDA \n");
        scanf("%d", &m->id_match);
    } while (searchMatch(match, m->id_match));

    return m;
}

void printThrowOfMatch(void *match_head)
{
    Match *m = (Match *)match_head;
    printf("MIN: %d - %s \n", ((Throw *)m)->min, ((Throw *)m)->desc_throw);
}

void printMatch(void *match_head)
{
    Match *m = (Match *)match_head;

    printf("\n");
    printf("PARTIDA: %d \n", m->id_match);
    printf("%s vs %s \n", m->t1->name, m->t2->name);
    printf("%d -- %d \n", m->goal_t1, m->goal_t2);
}

void showMatch(Node *head)
{
    show(head, &printMatch);
}

void showThrowOfMatch(Node *head)
{
    show(head, &printThrowOfMatch);
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
