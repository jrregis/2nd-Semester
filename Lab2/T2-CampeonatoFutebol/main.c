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

    showTeamS(team_head);
}