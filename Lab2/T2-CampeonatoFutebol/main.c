#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lseVoid.h"
#include "team.h"
#include "player.h"
#include "coach.h"
#include "match.h"
#include "menu.h"

int main()
{
    Node *team_head = createList();
    Node *match_head = createList();
    Node *player_head = createList();
    Node *coach_head = createList();

    Team *test;
    Match *m;
    team_head = insertEnd(team_head, createTeam("Inter", "Beira Rio", "POA", 10, 10, 1998, 0));
    player_head = insertEnd(player_head, createPlayer("Joao", "Ata", 20, 10, 0));
    coach_head = insertEnd(coach_head, createCoach("TEC 1", 1));

    mainMenu(team_head, player_head, coach_head);

    //////////////////////////////INSERÇÕES PARA TESTE RÁPIDO
    /*team_head = insertEnd(team_head, createTeam("Inter", "Beira Rio", "POA", 10, 10, 1998, 0));
    team_head = insertEnd(team_head, createTeam("Time 1", "Estadio 1", "Cidade 1", 1, 1, 1999, 1));
    team_head = insertEnd(team_head, createTeam("Time 2", "Estadio 2", "Cidade 2", 05, 03, 2010, 2));
    team_head = insertEnd(team_head, createTeam("Time 3", "Estadio 3", "Cidade 3", 05, 03, 2010, 3));

    Node *player_head = createList();
    Player *p;
    player_head = insertEnd(player_head, createPlayer("Joao", "Ata", 20, 10, 0));
    player_head = insertEnd(player_head, createPlayer("Maria", "Lte", 25, 15, 1));
    player_head = insertEnd(player_head, createPlayer("Jose", "Ltd", 29, 12, 2));
    player_head = insertEnd(player_head, createPlayer("Ronaldo", "Zg", 32, 12, 3));
    player_head = insertEnd(player_head, createPlayer("Joao", "Ata", 20, 10, 4));
    player_head = insertEnd(player_head, createPlayer("Maria", "Lte", 25, 15, 5));
    player_head = insertEnd(player_head, createPlayer("Jose", "Ltd", 29, 12, 6));
    player_head = insertEnd(player_head, createPlayer("Ronaldo", "Zg", 32, 12, 7));
    player_head = insertEnd(player_head, createPlayer("Joao", "Ata", 20, 10, 8));
    player_head = insertEnd(player_head, createPlayer("Maria", "Lte", 25, 15, 9));
    player_head = insertEnd(player_head, createPlayer("Jose", "Ltd", 29, 12, 10));
    player_head = insertEnd(player_head, createPlayer("Ronaldo", "Zg", 32, 12, 11));
    player_head = insertEnd(player_head, createPlayer("Joao", "Ata", 20, 10, 12));
    player_head = insertEnd(player_head, createPlayer("Maria", "Lte", 25, 15, 13));
    player_head = insertEnd(player_head, createPlayer("Jose", "Ltd", 29, 12, 14));
    player_head = insertEnd(player_head, createPlayer("Ronaldo", "Zg", 32, 12, 15));
    player_head = insertEnd(player_head, createPlayer("Joao", "Ata", 20, 10, 16));
    player_head = insertEnd(player_head, createPlayer("Maria", "Lte", 25, 15, 17));
    player_head = insertEnd(player_head, createPlayer("Jose", "Ltd", 29, 12, 18));
    player_head = insertEnd(player_head, createPlayer("Ronaldo", "Zg", 32, 12, 19));
    player_head = insertEnd(player_head, createPlayer("Joao", "Ata", 20, 10, 20));
    player_head = insertEnd(player_head, createPlayer("Maria", "Lte", 25, 15, 21));
    player_head = insertEnd(player_head, createPlayer("Jose", "Ltd", 29, 12, 22));
    player_head = insertEnd(player_head, createPlayer("Ronaldo", "Zg", 32, 12, 23));
    player_head = insertEnd(player_head, createPlayer("Joao", "Ata", 20, 10, 24));
    player_head = insertEnd(player_head, createPlayer("Maria", "Lte", 25, 15, 25));
    player_head = insertEnd(player_head, createPlayer("Jose", "Ltd", 29, 12, 26));
    player_head = insertEnd(player_head, createPlayer("Ronaldo", "Zg", 32, 12, 27));

    Node *coach_head = createList();
    Coach *c;
    coach_head = insertEnd(coach_head, createCoach("TEC 1", 1));
    coach_head = insertEnd(coach_head, createCoach("TEC 2", 2));
    coach_head = insertEnd(coach_head, createCoach("TEC 3", 3));

    test = searchTeam(team_head, 0);

    for (int i = 0; i <= 26; i++)
        registerPlayer(test, searchPlayer(player_head, i));

    printf("APOS INCLUIR NO TIME\n");
    showTeams(team_head);

    unregisterPlayer(test, 2);
    unregisterPlayer(test, 0);
    printf("APOS EXCLUIR DO TIME\n");
    showTeams(team_head);
    */
}