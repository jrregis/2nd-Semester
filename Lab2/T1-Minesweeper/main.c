#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "board.h"
int main(void)
{
	int line = 0, colum = 0, nBomb, i, j, nWin, op, rand = 0;
	time_t start;
	Board **mat;
	StartGame(&line, &colum, &nBomb, &nWin);
	mat = AloocMat(line, colum);
	IniBoard(mat, line, colum);
	DropBomb(mat, line, colum, nBomb);
	BombAdj(mat, line, colum);
	Draw(mat, line, colum, 0);
	printf("\n\n\t\t\t\t1-Jogador\n\t\t\t\t2-PC\n");
	scanf("%d", &op);
	time(&start);
	switch (op)
	{

	case 1:
		Play(mat, line, colum, nWin, start);
	case 2:
		PC(mat, line, colum, nWin, start);
	}
	return 0;
}