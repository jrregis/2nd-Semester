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
#include "round.h"

void menuReport(Node *team, Node *player, Node *coach, Node *match, Node *round)
{
    int op, op1, len = 0;
    Node *show_team;

    system("clear");
    printf("0 - ESTATISTICAS TIME\n1 - ESTATISTICAS JOGADORES\n2 - RANK TIMES\n3 - RANK JOGADORES\n4 - VOLTAR\n");
    scanf("%d", &op);
    switch (op)
    {
    case 0:
        system("clear");
        showDataTeam(team);
        break;
    case 1:
        system("clear");
        showDataPlayer(player);
        break;
    case 2:
        system("clear");
        bubble_sort(team, 0);
        printf("\t\tRANK TIMES\n");
        showRank(team);
        break;
    case 3:
        system("clear");
        bubble_sort(player, 1);
        printf("RANK JOGADORES\n");
        showRankPlayer(player);
        break;
    case 4:
        mainMenu(team, player, coach, match, round);
    default:
        break;
    }
    if (op != 4)
    {
        printf("(1)VOLTAR (0)SAIR\n");
        scanf("%d", &op1);
        switch (op1)
        {
        case 0:
            exitProgram(team, player, coach, match, round);
            break;
        case 1:
            menuReport(team, player, coach, match, round);
        default:
            break;
        }
    }
}
void menuSearch(Node *team, Node *player, Node *coach, Node *match, Node *round)
{
    int op, op1, id;

    system("clear");
    printf("\t\tBUSCAR\n");
    printf("0 - TIME\n1 - JOGADOR\n2 - TECNICO\n3 - RODADA\n4 - PARTIDA \n5 - VOLTAR \n");
    scanf("%d", &op);

    switch (op)
    {
    case 0:
        id = readId(0);
        if (searchTeam(team, id) != NULL)
            printTeam(searchTeam(team, id));
        else
            printf("TIME NAO CADASTRADO\n");
        break;
    case 1:
        id = readId(1);
        if (searchPlayer(player, id) != NULL)
            printPlayer(searchPlayer(player, id));
        else
            printf("JOGADOR NAO CADASTRADO\n");
        break;
    case 2:
        id = readId(2);
        if (searchCoach(coach, id) != NULL)
            printCoach(searchCoach(coach, id));
        else
            printf("TECNICO NAO CADASTRADO\n");
        break;
    case 3:
        id = readId(3);
        if (searchRound(round, id) != NULL)
            printRound(searchRound(round, id));
        else
            printf("RODADA NAO CADASTRADA\n");
        break;
    case 4:
        id = readId(4);
        if (searchMatch(match, id) != NULL)
        {
            printMatch(searchMatch(match, id));
            printf("LANCES DA PARTIDA:\n");
            showThrowOfMatch(searchMatch(match, id)->throw_s);
        }
        else
            printf("PARTIDA NAO CADASTRADA\n");
        break;
    case 5:
        menuSignUp(team, player, coach, match, round);
        break;

    default:
        break;
    }
    if (op != 5)
    {
        printf("(1)VOLTAR (0)SAIR\n");
        scanf("%d", &op1);
        switch (op1)
        {
        case 0:
            exitProgram(team, player, coach, match, round);
            break;
        case 1:
            menuSignUp(team, player, coach, match, round);
        default:
            break;
        }
    }
}
void menuDelete(Node *team, Node *player, Node *coach, Node *match, Node *round)
{
    int op, op1, id;
    system("clear");
    printf("\t\tEXCLUIR\n");
    printf("0 - TIME\n1 - JOGADOR\n2 - TECNICO\n3 - RODADA\n4 - PARTIDA\n5 - VOLTAR\n");
    scanf("%d", &op);

    switch (op)
    {
    case 0:
        do
        {
            id = readId(0);
        } while (searchTeam(team, id) == NULL);

        team = removeTeam(team, id);
        break;
    case 1:
        do
        {
            id = readId(1);
        } while (searchPlayer(player, id) == NULL);

        player = removePlayer(player, id);
        break;
    case 2:
        do
        {
            id = readId(2);
        } while (searchCoach(coach, id) == NULL);

        coach = removeCoach(coach, id);
        break;
    case 3:
        do
        {
            id = readId(3);
        } while (searchRound(round, id) == NULL);
        round = removeRound(round, id);
        break;
    case 4:
        do
        {
            id = readId(4);
        } while (searchMatch(match, id) == NULL);

        match = removeMatch(match, id);
        break;
    case 5:
        menuSignUp(team, player, coach, match, round);

    default:
        break;
    }
    if (op != 5)
    {
        printf("(1)VOLTAR (0)SAIR\n");
        scanf("%d", &op1);
        switch (op1)
        {
        case 0:
            exitProgram(team, player, coach, match, round);
            break;
        case 1:
            menuSignUp(team, player, coach, match, round);
        default:
            break;
        }
    }
}
void menuInclude(Node *team, Node *player, Node *coach, Node *match, Node *round)
{
    int op;
    system("clear");
    printf("\t\tINCLUIR\n");
    printf("0 - TIME\n1 - JOGADOR\n2 - TECNICO\n3 - RODADA\n4 - VOLTAR \n");
    scanf("%d", &op);

    switch (op)
    {
    case 0:
        readTeam(team, player, coach, match, round);
        break;
    case 1:
        readPlayer(team, player, coach, match, round);
        break;
    case 2:
        readCoach(team, player, coach, match, round);
        break;
    case 3:
        readRound(round);
        break;
    case 4:
        menuSignUp(team, player, coach, match, round);
        break;

    default:
        break;
    }
}
void menuSignUp(Node *team, Node *player, Node *coach, Node *match, Node *round)
{
    int op;
    system("clear");
    printf("\t\tCADASTROS\n");
    printf("0 - INCLUIR\n1 - EXCLUIR\n2 - BUSCAR\n3 - VOLTAR\n");
    scanf("%d", &op);

    switch (op)
    {
    case 0:
        menuInclude(team, player, coach, match, round);
        break;
    case 1:
        menuDelete(team, player, coach, match, round);
        break;
    case 2:
        menuSearch(team, player, coach, match, round);
        break;
    case 3:
        mainMenu(team, player, coach, match, round);
        break;
    default:
        exit(1);
        break;
    }
}
void menuNarration(Match *m, Node *team, Node *player, Node *coach, Node *match, Node *round)
{
    int op;
    Throw *thorow_match;
    thorow_match = readThrow();
    m->throw_s = insertEnd(m->throw_s, thorow_match);

    printf("\n0 - MARCAR GOL\n1 - MARCAR FALTA\n2 - FAZER SUBSTITUICAO\n");
    scanf("%d", &op);

    switch (op)
    {
    case 0:
        markGoal(m, team, player, coach, match, round);
        break;
    case 1:
        markFault(m, team, player, coach, match, round);
        break;
    case 2:
        replacePlayer(m, team, player, coach, match, round);
        break;
    }
}
void menuThrow(Match *m, Node *team, Node *player, Node *coach, Node *match, Node *round)
{
    int op, id_round;
    Round *r;
    system("clear");
    printf("\t\tNARRACAO\n");
    printf("0 - NARRAR LANCE\n1 - ENCERRAR PARTIDA\n");
    scanf("%d", &op);

    switch (op)
    {
    case 0:
        menuNarration(m, team, player, coach, match, round);
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

        match = insertEnd(match, m);

        printf("DIGITE O ID DA RODADA A VINCULAR A PARTIDA:\n");
        do
        {
            scanf("%d", &id_round);
        } while (searchRound(round, id_round) == NULL);

        r = searchRound(round, id_round);
        registerMatch(r, m);
        mainMenu(team, player, coach, match, round);
        break;
    default:
        break;
    }
}

void menuToTell(Node *team, Node *player, Node *coach, Node *match, Node *round)
{
    int op1, id_player;
    Match *m;

    system("clear");
    printf("\t\tNARRACAO\n");
    printf("\tESCOLHER TIMES DA PARTIDA\n");
    m = createMatch(team, match);

    listPlayerToMatch(m, player);
    selectHeaderPlayers(m);

    menuThrow(m, team, player, coach, match, round);
}
void mainMenu(Node *team, Node *player, Node *coach, Node *match, Node *round)
{
    int op, op1, i = 0;
    system("clear");
    printf("\t\tCAMPEONATO DE FUTEBOL\n");
    printf("0 - CADASTROS\n1 - NARRAR\n2 - RELATORIOS\n3 - SAIR\n");
    scanf("%d", &op);

    switch (op)
    {
    case 0:
        menuSignUp(team, player, coach, match, round);
        break;
    case 1:
        menuToTell(team, player, coach, match, round);
        break;
    case 2:
        menuReport(team, player, coach, match, round);
        break;
    case 3:
        exitProgram(team, player, coach, match, round);
        break;

    default:
        exit(1);
        break;
    }
}

void markGoal(Match *m, Node *team, Node *player, Node *coach, Node *match, Node *round)
{
    int id_player, id_team;

    printf("DIGITE A ID(%s[%d] / %s[%d]) DO TIME QUE MARCOU: ", m->t1->name, m->t1->id_team, m->t2->name, m->t2->id_team);
    scanf("%d", &id_team);
    if (id_team == m->t1->id_team)
    {
        m->goal_t1++;
        m->t1->goal_done++;
        m->t2->goal_conceded++;

        printf("DIGITE A ID DO JOGADOR QUE MARCOU:\n ");
        showHeaderPlayer(m->t1->selection);
        scanf("%d", &id_player);
        if (searchPlayer(m->t1->selection, id_player) != NULL)
        {
            searchPlayer(m->t1->selection, id_player)->goal++;
        }
    }
    else
    {
        m->goal_t2++;
        m->t2->goal_done++;
        m->t1->goal_conceded++;
        printf("DIGITE A ID DO JOGADOR QUE MARCOU:\n ");
        showHeaderPlayer(m->t2->selection);
        scanf("%d", &id_player);
        if (searchPlayer(m->t2->selection, id_player))
        {
            searchPlayer(m->t2->selection, id_player)->goal++;
        }
    }
    menuThrow(m, team, player, coach, match, round);
}
void markFault(Match *m, Node *team, Node *player, Node *coach, Node *match, Node *round)
{
    int id_player, id_team, card_y, card_r;
    Player *p;
    printf("DIGITE A ID(%d / %d) DO TIME QUE COMETEU: ", m->t1->id_team, m->t2->id_team);
    scanf("%d", &id_team);

    printf("HOUVE CARTAO VERMELHO (1)SIM (0)NAO: ");
    scanf("%d", &card_r);
    if (card_r == 0)
    {
        printf("HOUVE CARTAO AMARELO  (1)SIM (0)NAO:");
        scanf("%d", &card_y);
    }

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
    menuThrow(m, team, player, coach, match, round);
}

void replacePlayer(Match *m, Node *team, Node *player, Node *coach, Node *match, Node *round)
{
    int id_out, id_in, id_team;
    Player *p;

    printf("DIGITE A ID(%s[%d] / %s[%d]) DO TIME QUE FARA A ALTERACAO: ", m->t1->name, m->t1->id_team, m->t2->name, m->t2->id_team);
    scanf("%d", &id_team);

    if (id_team == m->t1->id_team)
    {
        printf("JOGADORES EM CAMPO\n");
        showHeaderPlayer(m->t1->selection);

        do
        {
            printf("DIGITE A ID D JOGADOR QUE SAIRA: ");
            scanf("%d", &id_out);
        } while (searchPlayer(m->t1->selection, id_out) == NULL);
        m->t1->selection = removePlayer(m->t1->selection, id_out);

        printf("JOGADORES NO BANCO\n");
        showHeaderPlayer(m->t1->players);

        do
        {
            printf("DIGITE A ID D JOGADOR QUE ENTRARA: ");
            scanf("%d", &id_in);
        } while (searchPlayer(m->t1->players, id_in) == NULL);
        p = searchPlayer(m->t1->players, id_in);
        m->t1->selection = insertEnd(m->t1->selection, p);

        printf("TIME ATUAL:\n");
        showHeaderPlayer(m->t1->selection);
    }

    else
    {
        printf("JOGADORES EM CAMPO\n");
        showHeaderPlayer(m->t2->selection);

        do
        {
            printf("DIGITE A ID D JOGADOR QUE SAIRA: ");
            scanf("%d", &id_out);
        } while (searchPlayer(m->t2->selection, id_out) == NULL);
        m->t2->selection = removePlayer(m->t2->selection, id_out);

        printf("JOGADORES NO BANCO\n");
        showHeaderPlayer(m->t2->players);

        do
        {
            printf("DIGITE A ID D JOGADOR QUE ENTRARA: ");
            scanf("%d", &id_in);
        } while (searchPlayer(m->t2->players, id_in) == NULL);
        p = searchPlayer(m->t2->players, id_in);
        m->t2->selection = insertEnd(m->t2->selection, p);

        printf("TIME ATUAL:\n");
        showHeaderPlayer(m->t2->selection);
    }
    sleep(5);
    menuThrow(m, team, player, coach, match, round);
}

int readId(int type)
{
    int id;
    switch (type)
    {
    case 0:
        printf("DIGITE A ID DO TIME: ");
        scanf("%d", &id);
        break;
    case 1:
        printf("DIGITE A ID DO JOGADOR: ");
        scanf("%d", &id);
        break;
    case 2:
        printf("DIGITE A ID DO TECNICO: ");
        scanf("%d", &id);
        break;
    case 3:
        printf("DIGITE A ID DA RODADA: ");
        scanf("%d", &id);
        break;
    case 4:
        printf("DIGITE A ID DA PARTIDA: ");
        scanf("%d", &id);
    default:
        break;
    }
    return id;
}

Throw *readThrow(void)
{
    Throw *t = (Throw *)malloc(sizeof(Throw));
    char temp;
    system("clear");
    printf("\t\tNARRACAO\n");
    printf("DIGITE O MIN DO LANCE: ");
    scanf("%d", &t->min);
    printf("DIGITE A DESCRICAO DO LANCE: ");
    scanf("%c", &temp);
    scanf("%[^\n]", t->desc_throw);
    return t;
}

void listPlayerToMatch(Match *m, Node *player)
{
    int op1, id_player;
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
            if (searchPlayer(player, id_player) != NULL && searchPlayer(m->t2->players, id_player) == NULL)
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
            if (searchPlayer(player, id_player) != NULL && searchPlayer(m->t1->players, id_player) == NULL)
                registerPlayer(m->t2, searchPlayer(player, id_player));
        }

    } while (op1 == 0);
}

//PARA QUESTÕES DE TESTES MAIS RÁPIDOS OS TIMES TEM 5 JOGADORES ESCALADOS
//ASSIM COMO NO FUTEBOL DE SALÃO, PODENDO FACILMENTE SER AJUSTADO
//PARA FUTEBOL DE CAMPO AJUSTANDO O FOR DE LEITURA DOS TITULARES
void selectHeaderPlayers(Match *m)
{
    int id_player;

    system("clear");
    printf("\t\tNARRACAO\n");
    printf("\tESCALAR JOGADORES DO %s\n", m->t1->name);
    // LEITURA DE 5 JOGADORES TITULARES, PARA REALIZAR TESTES MAIS RÁPIDOS
    for (int i = 0; i < 5; i++)
    {
        printf("DIGITE A ID DO JOGADOR A SER ESCALADO: ");
        scanf("%d", &id_player);
        if (searchPlayer(m->t1->players, id_player))
        {
            m->t1->selection = insertEnd(m->t1->selection, searchPlayer(m->t1->players, id_player));
            m->t1->players = removePlayer(m->t1->players, id_player);
        }
    }
    system("clear");
    printf("\t\tNARRACAO\n");
    printf("\tESCALAR JOGADORES DO %s\n", m->t2->name);
    // LEITURA DE 5 JOGADORES TITULARES, PARA REALIZAR TESTES MAIS RÁPIDOS
    for (int i = 0; i < 5; i++)
    {
        printf("DIGITE A ID DO JOGADOR A SER ESCALADO: ");
        scanf("%d", &id_player);
        if (searchPlayer(m->t2->players, id_player))
        {
            m->t2->selection = insertEnd(m->t2->selection, searchPlayer(m->t2->players, id_player));
            m->t2->players = removePlayer(m->t2->players, id_player);
        }
    }
}
void bubble_sort(Node *head, int op)
{
    struct Node *tmp = createList(), *store = head;
    void *swap_data;

    while (head != NULL)
    {
        tmp = store;
        while (tmp != NULL)
        {
            if (tmp->next && ((Team *)tmp->info)->points < ((Team *)tmp->next->info)->points && op == 0)
            {
                swap_data = tmp->info;
                tmp->info = tmp->next->info;
                tmp->next->info = swap_data;
            }

            if (tmp->next && ((Player *)tmp->info)->goal < ((Player *)tmp->next->info)->goal && op == 1)
            {
                swap_data = tmp->info;
                tmp->info = tmp->next->info;
                tmp->next->info = swap_data;
            }
            tmp = tmp->next;
        }
        head = head->next;
    }
}

void exitProgram(Node *team, Node *player, Node *coach, Node *match, Node *round)
{
    freeList(team);
    printf("LISTA DE TIMES LIBERADA\n");
    freeList(player);
    printf("LISTA DE JOGADORES LIBERADA\n");
    freeList(coach);
    printf("LISTA DE TECNICOS LIBERADA\n");
    freeList(match);
    printf("LISTA DE PARTIDAS LIBERADA\n");
    freeList(round);
    printf("LISTA DE RODADAS LIBERADA\n");
}