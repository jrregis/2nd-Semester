#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lseVoid.h"
#include "team.h"
#include "player.h"
#include "coach.h"

int main()
{
    Node *team_head = createList();
    Team *test;
    team_head = insertEnd(team_head, createTeam("Inter", "Beira Rio", "POA", 10, 10, 1998, 0));
    team_head = insertEnd(team_head, createTeam("Time 1", "Estadio 1", "Cidade 1", 1, 1, 1999, 1));
    team_head = insertEnd(team_head, createTeam("Time 2", "Estadio 2", "Cidade 2", 05, 03, 2010, 2));

    Node *player_head = createList();
    Player *p;
    player_head = insertEnd(player_head, createPlayer("Joao", "Ata", 20, 10, 0));
    player_head = insertEnd(player_head, createPlayer("P2", "Lte", 25, 15, 1));
    player_head = insertEnd(player_head, createPlayer("P3", "Ltd", 29, 12, 2));

    Node *coach_head = createList();
    Coach *c;
    coach_head = insertEnd(coach_head, createCoach("TEC 1", 1));
    coach_head = insertEnd(coach_head, createCoach("TEC 2", 2));
    coach_head = insertEnd(coach_head, createCoach("TEC 3", 3));

    /*    test = searchTeam(team_head, 0);
    registerPlayer(test, searchPlayer(player_head, 0));
    registerPlayer(test, searchPlayer(player_head, 1));

    printf("APOS INCLUIR NO TIME\n");
    showTeams(team_head);

    unregisterPlayer(test, 2);
    unregisterPlayer(test, 0);
    printf("APOS EXCLUIR DO TIME\n");
    showTeams(team_head); */
    showTeams(team_head);

    insertingPlayerInTeam(team_head, player_head);
    printf("incluido\n");
    showTeams(team_head);

    removingPlayerOfTeam(team_head);
    printf("removido\n");
    showTeams(team_head);
}