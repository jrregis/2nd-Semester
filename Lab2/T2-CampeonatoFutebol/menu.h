#ifndef MENU_H
#define MENU_H
#include "lseVoid.h"
#include "match.h"

void mainMenu(Node *team, Node *player, Node *coach, Node *match, Node *round); //MENU PRINCIPAL

void menuSignUp(Node *team, Node *player, Node *coach, Node *match, Node *round);  //MENU DE CADASTROS
void menuInclude(Node *team, Node *player, Node *coach, Node *match, Node *round); //INCLUSÃO NOS CADASTROS
void menuDelete(Node *team, Node *player, Node *coach, Node *match, Node *round);  //BUSCA NOS CADASTROS
void menuSearch(Node *team, Node *player, Node *coach, Node *match, Node *round);  //EXLCUSÃO NOS CADASTROS

void menuToTell(Node *team, Node *player, Node *coach, Node *match, Node *round);              //MENU PARA NARRAR
void menuThrow(Match *m, Node *team, Node *player, Node *coach, Node *match, Node *round);     //MENU PARA NARRA O LANCE
void menuNarration(Match *m, Node *team, Node *player, Node *coach, Node *match, Node *round); //MENU DE GOLS/FALTAS/SUBSTITUIÇÕES

void markGoal(Match *m, Node *team, Node *player, Node *coach, Node *match, Node *round);      //MARCA GOL
void markFault(Match *m, Node *team, Node *player, Node *coach, Node *match, Node *round);     //MARCA FALTA
void replacePlayer(Match *m, Node *team, Node *player, Node *coach, Node *match, Node *round); //SUBSTITUI JOGADOR NO TIME TITULAR

int readId(int type);                           //LER AS IDS DE TIME/JOGADOR/TÉCNICO/RODADA/PARTIDA
Throw *readThrow(void);                         //LÊ OS LANCES
void listPlayerToMatch(Match *m, Node *player); //RELACIONA JOGADORES DA LISTA DE JOGADORES À PARTIDA
void selectHeaderPlayers(Match *m);             //ESCALA TIME TITULAR

void menuReport(Node *team, Node *player, Node *coach, Node *match, Node *round);  //MENU DE RELATÓRIOS
void bubble_sort(Node *head, int op);                                              //ORDENA TIMES POR PONTOS E JOGADORES POR GOLS
void exitProgram(Node *team, Node *player, Node *coach, Node *match, Node *round); //LIBERA TODAS AS LISTAS
#endif