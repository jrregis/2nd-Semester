#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "lseVoid.h"
#include "team.h"
#include "player.h"
#include "coach.h"
#include "match.h"
#include "menu.h"

void menuSearch(Node *team, Node *player, Node *coach)
{
    int op, op1, id_team, id_player, id_coach;
    Team *t;
    Player *p;
    Coach *c;

    system("clear");
    printf("\t\tBUSCAR\n");
    printf("0 - TIME\n1 - JOGADOR\n2 - TECNICO\n3 - VOLTAR\n");
    scanf("%d", &op);

    switch (op)
    {
    case 0:
        printf("DIGITE A ID DO TIME A SER BUSCADO: ");
        scanf("%d", &id_team);
        t = searchTeam(team, id_team);
        if (t != NULL)
        {
            printTeam(t);
        }
        else
        {
            printf("TIME NAO CADASTRADO\n");
        }
        break;
    case 1:
        printf("DIGITE A ID DO JOGADOR A SER BUSCADO: ");
        scanf("%d", &id_player);
        p = searchPlayer(player, id_player);
        if (p != NULL)
        {
            printPlayer(p);
        }
        else
        {
            printf("JOGADOR NAO CADASTRADO\n");
        }
        break;
    case 2:
        printf("DIGITE A ID DO TECNICO A SER BUSCADO: ");
        scanf("%d", &id_coach);
        c = searchCoach(coach, id_coach);
        if (c != NULL)
        {
            printCoach(c);
        }
        else
        {
            printf("TECNICO NAO CADASTRADO\n");
        }
        break;
    case 3:
        menuSignUp(team, player, coach);

    default:
        break;
    }
    printf("(1)VOLTAR (0)SAIR\n");
    scanf("%d", &op1);
    switch (op1)
    {
    case 0:
        exit(1);
        break;
    case 1:
        menuSignUp(team, player, coach);
    default:
        break;
    }
}
void menuDelete(Node *team, Node *player, Node *coach)
{
    int op, id_team, id_player, id_coach;
    system("clear");
    printf("\t\tEXCLUIR\n");
    printf("0 - TIME\n1 - JOGADOR\n2 - TECNICO\n3 - VOLTAR\n");
    scanf("%d", &op);

    switch (op)
    {
    case 0:
        do
        {
            printf("DIGITE A ID DO TIME A SER EXCLUIDO: ");
            scanf("%d", &id_team);
        } while (searchTeam(team, id_team) == NULL);

        team = removeTeam(team, id_team);

        break;
    case 1:
        do
        {
            printf("DIGITE A ID DO JOGADOR A SER EXCLUIDO: ");
            scanf("%d", &id_player);
        } while (searchPlayer(player, id_player) == NULL);

        player = removePlayer(player, id_player);

        break;
    case 2:
        do
        {
            printf("DIGITE A ID DO TECNICO A SER EXCLUIDO: ");
            scanf("%d", &id_coach);
        } while (searchCoach(coach, id_coach) == NULL);

        coach = removeCoach(coach, id_coach);

        break;
    case 3:
        menuSignUp(team, player, coach);

    default:
        break;
    }
}
void menuInclude(Node *team, Node *player, Node *coach)
{
    int op;
    system("clear");
    printf("\t\tINCLUIR\n");
    printf("0 - TIME\n1 - JOGADOR\n2 - TECNICO\n3 - VOLTAR\n");
    scanf("%d", &op);

    switch (op)
    {
    case 0:
        readTeam(team, player, coach);
        break;
    case 1:
        readPlayer(team, player, coach);
        break;
    case 2:
        readCoach(team, player, coach);
        break;
    case 3:
        menuSignUp(team, player, coach);

    default:
        break;
    }
}
void menuSignUp(Node *team, Node *player, Node *coach)
{
    int op;
    system("clear");
    printf("\t\tCADATROS\n");
    printf("0 - INCLUIR\n1 - EXCLUIR\n2 - BUSCAR\n3 - VOLTAR\n");
    scanf("%d", &op);

    switch (op)
    {
    case 0:
        menuInclude(team, player, coach);
        break;
    case 1:
        menuDelete(team, player, coach);
        break;
    case 2:
        menuSearch(team, player, coach);
        break;
    case 3:
        mainMenu(team, player, coach);
        break;
    default:
        exit(1);
        break;
    }
}
void menuNarration(Match *m, Node *team, Node *player, Node *coach)
{
    int op, min;
    char desc_throw[50];
    system("clear");
    printf("\t\tNARRACAO\n");
    printf("DIGITE O MIN DO LANCE: ");
    scanf("%d", &min);
    printf("DIGITE A DESCRICAO DO LANCE: ");
    scanf("%s", desc_throw);

    printf("0 - MARCAR GOL\n1 - MARCAR FALTA\n2 - FAZER SUBSTITUICAO\n");
    scanf("%d", &op);

    switch (op)
    {
    case 0:
        markGoal(m, team, player, coach);
        break;
    case 1:
        markFault(m, team, player, coach);
        break;
    case 2:
        replacePlayer(m, team, player, coach);
        break;
    }
}
void menuThrow(Match *m, Node *team, Node *player, Node *coach)
{
    int op;
    system("clear");
    printf("\t\tNARRACAO\n");
    printf("0 - NARRAR LANCE\n1 - ENCERRAR PARTIDA\n");
    scanf("%d", &op);

    switch (op)
    {
    case 0:
        menuNarration(m, team, player, coach);
        break;
    case 1:
        if (m->goal_t1 > m->goal_t2)
            m->t1->points += 3;
        if (m->goal_t2 > m->goal_t1)
            m->t2->points += 3;
        if (m->goal_t2 == m->goal_t1)
        {
            m->t1->points += 1;
            m->t2->points += 1;
        }
        mainMenu(team, player, coach);
        break;
    default:
        break;
    }
}
void menuToTell(Node *team, Node *player, Node *coach)
{
    int op1, id_player;
    Match *m;
    Player *p;
    system("clear");
    printf("\t\tNARRACAO\n");
    printf("\tESCOLHER TIMES DA PARTIDA\n");
    m = createMatch(team);

    system("clear");
    printf("\t\tNARRACAO\n");
    printf("\tRELACIONAR JOGADORES DO %s\n", m->t1->name);
    do
    {
        printf("RELACIONAR: 0-SIM 1-PRONTO\n");
        scanf("%d", &op1);
        if (op1 == 0)
        {
            printf("DIGITE A ID DO JOGADOR A SER RELACIONADO: ");
            scanf("%d", &id_player);
            registerPlayer(m->t1, searchPlayer(player, id_player));
        }

    } while (op1 == 0);

    system("clear");
    printf("\t\tNARRACAO\n");
    printf("\tRELACIONAR JOGADORES DO %s\n", m->t2->name);
    do
    {
        printf("RELACIONAR: 0-SIM 1-PRONTO\n");
        scanf("%d", &op1);
        if (op1 == 0)
        {
            printf("DIGITE A ID DO JOGADOR A SER RELACIONADO: ");
            scanf("%d", &id_player);
            registerPlayer(m->t2, searchPlayer(player, id_player));
        }

    } while (op1 == 0);
    system("clear");
    printf("\t\tNARRACAO\n");
    printf("\tESCALAR JOGADORES DO %s\n", m->t1->name);
    for (int i = 0; i < 5; i++)
    {
        printf("DIGITE A ID DO JOGADOR A SER ESCALADO: ");
        scanf("%d", &id_player);
        if (searchPlayer(m->t1->players, id_player))
        {
            p = searchPlayer(m->t1->players, id_player);
            m->t1->selection = insertEnd(m->t1->selection, p);
        }
    }
    system("clear");
    printf("\t\tNARRACAO\n");
    printf("\tESCALAR JOGADORES DO %s\n", m->t2->name);
    for (int i = 0; i < 5; i++)
    {
        printf("DIGITE A ID DO JOGADOR A SER ESCALADO: ");
        scanf("%d", &id_player);
        if (searchPlayer(m->t2->players, id_player))
        {
            p = searchPlayer(m->t2->players, id_player);
            m->t2->selection = insertEnd(m->t2->selection, p);
        }
    }
    menuThrow(m, team, player, coach);
}
void mainMenu(Node *team, Node *player, Node *coach)
{
    int op;
    system("clear");
    printf("\t\tCAMPEONATO RAIZ DE FUTEBOL\n");
    printf("0 - CADASTROS\n1 - NARRAR\n2 - RELATORIOS\n3 - Testes\n");
    scanf("%d", &op);

    switch (op)
    {
    case 0:
        menuSignUp(team, player, coach);
        break;
    case 1:
        menuToTell(team, player, coach);
        break;
    case 2:
        exit(1);
        // menuReport();
        break;
    case 3:
        showTeams(team);
        showPlayers(player);
        // showCoachs(coach);
        break;

    default:
        exit(1);
        break;
    }
}

void markGoal(Match *m, Node *team, Node *player, Node *coach)
{
    int id_player, id_team;
    Player *p;
    printf("DIGITE A ID(%d / %d) DO TIME QUE MARCOU: ", m->t1->id_team, m->t2->id_team);
    scanf("%d", &id_team);
    if (id_team == m->t1->id_team)
    {
        m->goal_t1++;
        m->t1->goal_done++;
        m->t2->goal_conceded++;

        printf("DIGITE A ID DO JOGADOR QUE MARCOU: ");
        scanf("%d", &id_player);
        if (searchPlayer(m->t1->selection, id_player))
        {
            p = searchPlayer(m->t1->selection, id_player);
            p->goal++;
        }
    }
    else
    {
        m->goal_t2++;
        m->t2->goal_done++;
        m->t1->goal_conceded++;
        printf("DIGITE A ID DO JOGADOR QUE MARCOU: ");
        scanf("%d", &id_player);
        if (searchPlayer(m->t2->selection, id_player))
        {
            p = searchPlayer(m->t2->selection, id_player);
            p->goal++;
        }
    }
    menuThrow(m, team, player, coach);
}
void markFault(Match *m, Node *team, Node *player, Node *coach)
{
    int id_player, id_team, card_y, card_r;
    Player *p;
    printf("DIGITE A ID(%d / %d) DO TIME QUE COMETEU: ", m->t1->id_team, m->t2->id_team);
    scanf("%d", &id_team);

    printf("HOUVE CARTAO VERMELHO (1)SIM (0)NAO: ");
    scanf("%d", &card_r);
    printf("HOUVE CARTAO AMARELO  (1)SIM (0)NAO:");
    scanf("%d", &card_y);

    if (id_team == m->t1->id_team)
    {
        m->t1->fault++;
        if (card_r == 1)
            m->t1->card_r++;
        if (card_y == 1)
            m->t1->card_y++;

        printf("DIGITE A ID DO JOGADOR QUE MARCOU: ");
        scanf("%d", &id_player);
        if (searchPlayer(m->t1->selection, id_player))
        {
            p = searchPlayer(m->t1->selection, id_player);
            p->fault++;

            if (card_r == 1)
                p->card_r++;
            if (card_y == 1)
                p->card_y++;
        }
    }
    else
    {
        m->t2->fault++;
        if (card_r == 1)
            m->t2->card_r++;
        if (card_y == 1)
            m->t2->card_y++;

        printf("DIGITE A ID DO JOGADOR QUE MARCOU: ");
        scanf("%d", &id_player);
        if (searchPlayer(m->t2->selection, id_player))
        {
            p = searchPlayer(m->t2->selection, id_player);
            p->fault++;

            if (card_r == 1)
                p->card_r++;
            if (card_y == 1)
                p->card_y++;
        }
    }
    menuThrow(m, team, player, coach);
}

void replacePlayer(Match *m, Node *team, Node *player, Node *coach)
{
    int id_out, id_in, id_team;
    Player *p;

    printf("DIGITE A ID(%d / %d) DO TIME QUE FARA A ALTERACAO: ", m->t1->id_team, m->t2->id_team);
    scanf("%d", &id_team);

    if (id_team == m->t1->id_team)
    {
        do
        {
            printf("DIGITE A ID D JOGADOR QUE SAIRA: ");
            scanf("%d", &id_out);
        } while (searchPlayer(m->t1->selection, id_out) == NULL);
        m->t1->selection = removePlayer(m->t1->selection, id_out);

        do
        {
            printf("DIGITE A ID D JOGADOR QUE ENTRARA: ");
            scanf("%d", &id_in);
        } while (searchPlayer(m->t1->players, id_in) == NULL);
        p = searchPlayer(m->t1->players, id_in);
        m->t1->selection = insertEnd(m->t1->selection, p);
    }

    else
    {
        do
        {
            printf("DIGITE A ID D JOGADOR QUE SAIRA: ");
            scanf("%d", &id_out);
        } while (searchPlayer(m->t2->selection, id_out) == NULL);
        m->t2->selection = removePlayer(m->t2->selection, id_out);

        do
        {
            printf("DIGITE A ID D JOGADOR QUE ENTRARA: ");
            scanf("%d", &id_in);
        } while (searchPlayer(m->t2->players, id_in) == NULL);
        p = searchPlayer(m->t2->players, id_in);
        m->t2->selection = insertEnd(m->t2->selection, p);
    }
    menuThrow(m, team, player, coach);
}
