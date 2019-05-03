#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "lseVoid.h"
#include "team.h"
#include "player.h"
#include "coach.h"
#include "match.h"
#include "menu.h"
#include "round.h"

int main()
{
    Node *team_head = createList();
    Node *match_head = createList();
    Node *player_head = createList();
    Node *coach_head = createList();
    Node *round_head = createList();
    Team *t;
    Player *p;
    Coach *c;
    //NAVEGAÇÃO EH FEITA PELOS MENUS ESSAS PRIMEIRAS INSERÇÕES FORAM FEITAS PARA AGILIZAR OS TESTES
    //CRIA NÓS NA LISTA DE TIMES COM PONTOS
    team_head = insertEnd(team_head, createTeamP("Real", "Estadio do Real", "Madrid", 10, 10, 1998, 1, 3));
    team_head = insertEnd(team_head, createTeamP("Porto", "Estadio do Porto", "Porto", 10, 10, 1998, 2, 2));
    team_head = insertEnd(team_head, createTeamP("Inter", "Beira Rio", "Porto Alegre", 10, 10, 1998, 0, 4));
    team_head = insertEnd(team_head, createTeamP("Gremio", "Arena da OAS", "Porto Alegre", 10, 10, 1998, 3, 6));
    team_head = insertEnd(team_head, createTeamP("Brasil", "Estadio do Brasil", "Cidades Brasileiras", 10, 10, 1998, 4, 9));

    //CRIA 15 NÓS NA LISTA DE JOGADORES COM IDADES, GOLS, NUMERO CAMISETA ALEATÓRIOS
    srand(time(NULL));
    for (int i = 0; i < 15; i++)
    {
        int age = rand() % 30;
        int number = rand() % 25;
        int goal = rand() % 50;
        player_head = insertEnd(player_head, createPlayerG("Nome Jogador", "Ata", age, number, i, goal));
    }
    //CRIA TECNICOS NA LISTA DE TÉCNICOS PARA TESTE
    for (int i = 0; i < 4; i++)
        coach_head = insertEnd(coach_head, createCoach("Nome do Tecnico", i));

    mainMenu(team_head, player_head, coach_head, match_head, round_head);
}