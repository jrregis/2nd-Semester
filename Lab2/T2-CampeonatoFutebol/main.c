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
    team_head = insertEnd(team_head, createTeam("Inter", "Beira Rio", "POA", 10, 10, 1998, 0));
    team_head = insertEnd(team_head, createTeam("Time 1", "Estadio 1", "Cidade 1", 1, 1, 1999, 1));
    team_head = insertEnd(team_head, createTeam("Time 2", "Estadio 2", "Cidade 2", 05, 03, 2010, 2));
    printf("LISTA DE TIMES\n");
    showTeamS(team_head);

    Node *player_head = createList();
    player_head = insertEnd(player_head, createPlayer("Joao", "Ata", 20, 10, 0));
    player_head = insertEnd(player_head, createPlayer("P2", "Lte", 25, 15, 1));
    printf("\n\nLISTA DE JOGADORES\n");
    showPlayers(player_head);

    Node *coach_head = createList();
    coach_head = insertEnd(coach_head, createCoach("TEC 1", 1));
    coach_head = insertEnd(coach_head, createCoach("TEC 2", 2));
    printf("\n\nLISTA DE TECNICOS\n");
    showCoachs(coach_head);
}