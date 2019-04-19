#ifndef BOARD_H
#define BOARD_H
typedef struct
{
	int adjBomb, bomb, check, show;
	char draw;
} Board;
void StartGame(int *line, int *colum, int *nBomb, int *nWin);						   //le opção de começar ou sair, após le o tamanho da matriz e o numero de bombas
Board **AloocMat(int line, int colum);												   //aloca matriz
Board **FreeMat(Board **mat, int line);												   //libera matriz
void DropBomb(Board **mat, int MaxLine, int MaxColum, int nBomb);					   //coloca bombas na matriz em posições aleatórias
void Draw(Board **mat, int line, int colum, int loser);								   //desenha o board
void IniBoard(Board **mat, int line, int colum);									   //inicia as variaveis do board, matriz de struct
void BombAdj(Board **mat, int line, int colum);										   // verifica bombas vizinhas
void Play(Board **mat, int line, int colum, int nWin, time_t start);				   //joga
void OpenCell(Board **mat, int line, int colum, int x, int y, int nWin, time_t start); //abre as casas onde não tem bomba, ou oloca o numero de bombas em volta
int InMat(Board **mat, int x, int y, int line, int colum);							   //verifica se a posicao existe na matriz
void WinCheck(Board **mat, int line, int colum, time_t start);						   //calcula o numero de casas checadas e se for igual ao numero de casas possiveis ganha o jogo
void PC(Board **mat, int line, int colum, int nWin, time_t start);					   //computador resolve o jogo
void ShowTimer(time_t *start, time_t *end);											   // calcula o tempo decorrido na partida
void Boom(Board **mat, int line, int colum, time_t start, int playX, int playY, int nWin);
void Flag(Board **mat, int playX, int playY, int line, int colum, int flag, int nWin, time_t start);
void ReadMove(int *x, int *y, int line, int colum, Board **mat, int mark);
#endif
