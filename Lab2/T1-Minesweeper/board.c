#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct
{
	int adjBomb, bomb, check, flag;
	char draw;
} Board;
void Flag(Board **mat, int playX, int playY, int line, int colum, int flag, int nWin, time_t start);

void ShowTimer(time_t start, time_t end)
{
	time_t sec = 0, min = 0;
	sec = difftime(end, start);
	min = sec / 60;
	sec = sec % 60;
	printf("Tempo de jogo: %.2ld:%.2ld \n", min, sec);
}
void StartGame(int *line, int *colum, int *nBomb, int *nWin)
{
	int op = 0, limitBomb = 0, linha = 0, coluna = 0;
	printf("\t\t\t\tCAMPO MINADO\n\t\t\t\t1 - Jogar\n\t\t\t\t2 - Sair\n");
	scanf("%d", &op);
	switch (op)
	{
	case 1:
		system("clear");
		printf("Digite o tamanho do tabuleiro:(LinhaxColuna)\nTamanho minimo 4x4\n");
		do
		{
			scanf("%d %d", line, colum); //le numero de linhas e colunas do Board
			system("clear");
			printf("Tamanho invalido, informe um tamanho válido!\n");
		} while (*line < 4 || *colum < 4);
		do
		{
			system("clear");
			printf("Digite a quantidade de bombas(1-%d)\n", ((*line) * (*colum) - 1));
			scanf("%d", nBomb);									   //le numero de bombas que tera o jogo
		} while (*nBomb > ((*line) * (*colum) - 1) || *nBomb < 1); //Verificação do numero de bombas
		*nWin = (*line) * (*colum) - *nBomb;
		break;
	case 2:
		exit(EXIT_SUCCESS);
		break;
	default:
		system("clear");
		printf("Opcao invalida, digite de novo!\n");
		StartGame(line, colum, nBomb, nWin);
		break;
	}
}
Board **AloocMat(int line, int colum)
{
	Board **mat = (Board **)malloc(line * sizeof(Board *)); //aloca um vetor de ponteiros
	for (int i = 0; i < line; i++)
	{
		mat[i] = (Board *)malloc(colum * sizeof(Board)); //aloca as posições do vetor
	}
	return mat;
}
Board **FreeMat(Board **mat, int line)
{
	for (int i = 0; i < line; i++)
		free(mat[i]); //libera a memoria primeiro do vetor
	free(mat);		  //libera a memoria do vetor de ponteiros
}
void DropBomb(Board **mat, int MaxLine, int MaxColum, int nBomb)
{
	int line = 0, colum = 0;
	srand(time(NULL));
	while (nBomb > 0)
	{

		line = rand() % MaxLine;
		colum = rand() % MaxColum;
		if (mat[line][colum].bomb == 0)
		{
			mat[line][colum].bomb = 1;
			nBomb--;
		}
	}
}
void BombAdj(Board **mat, int line, int colum, int x, int y)
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < colum; j++)
		{
			if (i > 0 && j > 0 && i < line - 1 && j < colum - 1) //verica centro
			{
				if (mat[i][j - 1].bomb == 1) // verifica esquerda
					mat[i][j].adjBomb++;
				if (mat[i][j + 1].bomb == 1) // verfica direita
					mat[i][j].adjBomb++;
				if (mat[i - 1][j].bomb == 1) //verifica acima centro
					mat[i][j].adjBomb++;
				if (mat[i - 1][j - 1].bomb == 1) //verifica acima esquerda
					mat[i][j].adjBomb++;
				if (mat[i - 1][j + 1].bomb == 1) // verifica acima direita
					mat[i][j].adjBomb++;
				if (mat[i + 1][j].bomb == 1) //verifica abaixo centro
					mat[i][j].adjBomb++;
				if (mat[i + 1][j - 1].bomb == 1) // verifica abaixo esquerda
					mat[i][j].adjBomb++;
				if (mat[i + 1][j + 1].bomb == 1) // verfica abaixo direita
					mat[i][j].adjBomb++;
			}
			if (i == 0 && (j > 0 && j < colum - 1)) //verifica primeira linha
			{
				if (mat[i][j - 1].bomb == 1) // verifica esquerda
					mat[i][j].adjBomb++;
				if (mat[i][j + 1].bomb == 1) // verfica direita
					mat[i][j].adjBomb++;
				if (mat[i + 1][j].bomb == 1) //verifica abaixo centro
					mat[i][j].adjBomb++;
				if (mat[i + 1][j - 1].bomb == 1) // verifica abaixo esquerda
					mat[i][j].adjBomb++;
				if (mat[i + 1][j + 1].bomb == 1) // verfica abaixo direita
					mat[i][j].adjBomb++;
			}
			if (i == line - 1 && (j > 0 && j < colum - 1)) //verifica a ultima linha
			{
				if (mat[i][j - 1].bomb == 1) // verifica esquerda
					mat[i][j].adjBomb++;
				if (mat[i][j + 1].bomb == 1) // verfica direita
					mat[i][j].adjBomb++;
				if (mat[i - 1][j].bomb == 1) //verifica acima centro
					mat[i][j].adjBomb++;
				if (mat[i - 1][j - 1].bomb == 1) //verifica acima esquerda
					mat[i][j].adjBomb++;
				if (mat[i - 1][j + 1].bomb == 1) // verifica acima direita
					mat[i][j].adjBomb++;
			}
			if (j == 0 && (i > 0 && i < line - 1)) //verifica a primeira coluna
			{
				if (mat[i - 1][j].bomb == 1) //verifica acima centro
					mat[i][j].adjBomb++;
				if (mat[i - 1][j + 1].bomb == 1) // verifica acima direita
					mat[i][j].adjBomb++;
				if (mat[i][j + 1].bomb == 1) // verfica direita
					mat[i][j].adjBomb++;
				if (mat[i + 1][j + 1].bomb == 1) // verfica abaixo direita
					mat[i][j].adjBomb++;
				if (mat[i + 1][j].bomb == 1) //verifica abaixo centro
					mat[i][j].adjBomb++;
			}
			if (j == colum - 1 && (i > 0 && i < line - 1)) //verifica a ultima coluna
			{
				if (mat[i - 1][j].bomb == 1) //verifica acima centro
					mat[i][j].adjBomb++;
				if (mat[i + 1][j].bomb == 1) //verifica abaixo centro
					mat[i][j].adjBomb++;
				if (mat[i + 1][j - 1].bomb == 1) // verifica abaixo esquerda
					mat[i][j].adjBomb++;
				if (mat[i][j - 1].bomb == 1) // verifica esquerda
					mat[i][j].adjBomb++;
				if (mat[i - 1][j - 1].bomb == 1) //verifica acima esquerda
					mat[i][j].adjBomb++;
			}
			if (i == 0 && j == 0) //canto sup esq
			{
				if (mat[i][j + 1].bomb == 1) // verfica direita
					mat[i][j].adjBomb++;
				if (mat[i + 1][j + 1].bomb == 1) // verfica abaixo direita
					mat[i][j].adjBomb++;
				if (mat[i + 1][j].bomb == 1) //verifica abaixo centro
					mat[i][j].adjBomb++;
			}
			if (j == 0 && i == line - 1) // canto inf esq
			{
				if (mat[i][j + 1].bomb == 1) // verfica direita
					mat[i][j].adjBomb++;
				if (mat[i - 1][j].bomb == 1) //verifica acima centro
					mat[i][j].adjBomb++;
				if (mat[i - 1][j + 1].bomb == 1) // verifica acima direita
					mat[i][j].adjBomb++;
			}
			if (i == 0 && j == colum - 1) //canto sup dir
			{
				if (mat[i][j - 1].bomb == 1) // verifica esquerda
					mat[i][j].adjBomb++;
				if (mat[i + 1][j - 1].bomb == 1) // verifica abaixo esquerda
					mat[i][j].adjBomb++;
				if (mat[i + 1][j].bomb == 1) //verifica abaixo centro
					mat[i][j].adjBomb++;
			}
			if (i == line - 1 && j == colum - 1) //canto inf dir
			{
				if (mat[i - 1][j].bomb == 1) //verifica acima centro
					mat[i][j].adjBomb++;
				if (mat[i - 1][j - 1].bomb == 1) //verifica acima esquerda
					mat[i][j].adjBomb++;
				if (mat[i][j - 1].bomb == 1) // verifica esquerda
					mat[i][j].adjBomb++;
			}
		}
	}
}
void Draw(Board **mat, int line, int colum, int loser)
{
	system("clear");
	if (loser == 1)
	{
		for (int i = 0; i < line; i++)
		{
			for (int j = 0; j < colum; j++)
			{
				if (mat[i][j].bomb == 1)
					mat[i][j].draw = '*';
			}
		}
	}
	for (int j = 0; j < colum; j++)
	{
		if (j == 0)
			printf("     %d ", j);
		if (j > 0 && j <= 10)
			printf("  %d ", j);
		if (j > 10)
			printf(" %d ", j);
	}
	printf("\n\n");
	for (int i = 0; i < line; i++)
	{
		if (i < 10)
			printf(" %d ", i);
		else
			printf("%d ", i);
		for (int j = 0; j < colum; j++)
		{
			printf("| %c ", mat[i][j].draw);
		}
		printf("|\n");
	}
}
int InMat(Board **mat, int x, int y, int line, int colum)
{
	if ((x >= 0 && x <= line - 1) && (y >= 0 && y <= colum - 1))
		return 1;
	else
		return 0;
}
void WinCheck(Board **mat, int line, int colum, int nWin, time_t start)
{
	int checkUp = 0;
	time_t end;
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < colum; j++)
		{
			checkUp += mat[i][j].check;
		}
	}
	if (checkUp == nWin)
	{
		time(&end);
		Draw(mat, line, colum, 0);
		printf("Ganhou\n");
		ShowTimer(start, end);
		mat = FreeMat(mat, line);
		exit(EXIT_SUCCESS);
	}
}
void OpenCell(Board **mat, int line, int colum, int x, int y, int nWin, time_t start)
{
	int valid = 0, checkUp = 0;
	valid = InMat(mat, x, y, line, colum);
	if (valid == 1 && mat[x][y].bomb == 0 && mat[x][y].check == 0 && mat[x][y].adjBomb == 0 && mat[x][y].flag == 0)
	{
		mat[x][y].draw = ' ';
		mat[x][y].check = 1;
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				OpenCell(mat, line, colum, x + i, y + j, nWin, start);
				checkUp++;
			}
		}
	}
	if (valid == 1 && mat[x][y].bomb == 0 && mat[x][y].check == 0 && mat[x][y].adjBomb != 0 && mat[x][y].flag == 0)
	{
		mat[x][y].draw = mat[x][y].adjBomb + '0';
		mat[x][y].check = 1;
	}
	WinCheck(mat, line, colum, nWin, start);
}
void IniBoard(Board **mat, int line, int colum)
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < colum; j++)
		{
			mat[i][j].bomb = 0;
			mat[i][j].adjBomb = 0;
			mat[i][j].check = 0;
			mat[i][j].flag = 0;
			mat[i][j].draw = 'x';
		}
	}
}
void ReadMove(int *x, int *y, int line, int colum, Board **mat, int mark)
{

	printf("\n\nDigite a linha(0-%d) e a coluna(0-%d):\n", line - 1, colum - 1);
	do
	{
		scanf("%d %d", x, y);
		if ((*x > line) || (*y > colum))
		{
			system("clear");
			Draw(mat, line, colum, 0);
			printf("\nCoordenada invalida, escolha outra!\n");
		}
		else
		{
			if (mat[*x][*y].check == 1 || mat[*x][*y].flag == 1 && mark == 0)
			{
				do
				{
					system("clear");
					Draw(mat, line, colum, 0);
					printf("\nCoordenada jogada, escolha outra!\n");
					scanf("%d %d", x, y);
				} while (mat[*x][*y].check == 1 || mat[*x][*y].flag == 1);
			}
			if (mat[*x][*y].check == 1 || mat[*x][*y].flag == 0 && mark == 1)
			{
				do
				{
					system("clear");
					Draw(mat, line, colum, 0);
					printf("\nCoordenada sem bandeira!\nEscolha uma posicao que tenha colocado bandeira!\n");
					scanf("%d %d", x, y);
				} while (mat[*x][*y].check == 1 || mat[*x][*y].flag == 0);
			}
		}
	} while ((*x > line || *y > colum));
}
void Boom(Board **mat, int line, int colum, time_t start, int playX, int playY, int nWin)
{
	time_t end;
	mat[playX][playY].draw = '*';
	system("clear");
	OpenCell(mat, line, colum, playX, playY, nWin, start);
	Draw(mat, line, colum, 1);
	time(&end);
	printf("\n\nVoce perdeu!\n");
	ShowTimer(start, end);
	mat = FreeMat(mat, line);
	exit(EXIT_SUCCESS);
}
void Play(Board **mat, int line, int colum, int nWin, time_t start)
{
	int playX = 0, playY = 0, op = 0;
	system("clear");
	Draw(mat, line, colum, 0);
	printf("\n\n1-Revelar posicao\n2-Marcar com bandeira\n3-Remover Bandeira\n");
	scanf("%d", &op);
	Draw(mat, line, colum, 0);
	switch (op)
	{
	case 1:
		system("clear");
		Draw(mat, line, colum, 0);
		ReadMove(&playX, &playY, line, colum, mat, 0);
		if (mat[playX][playY].bomb == 1)
			Boom(mat, line, colum, start, playX, playY, nWin);
		else
		{
			OpenCell(mat, line, colum, playX, playY, nWin, start);
			Play(mat, line, colum, nWin, start);
		}
	case 2:
		system("clear");
		Draw(mat, line, colum, 0);
		ReadMove(&playX, &playY, line, colum, mat, 0);
		Flag(mat, playX, playY, line, colum, 1, nWin, start);

	case 3:
		system("clear");
		Draw(mat, line, colum, 0);
		ReadMove(&playX, &playY, line, colum, mat, 1);
		Flag(mat, playX, playY, line, colum, 0, nWin, start);

	default:
		system("clear");
		Draw(mat, line, colum, 0);
		printf("Opcao invalida!\n");
		Play(mat, line, colum, nWin, start);
	}
}
void Flag(Board **mat, int playX, int playY, int line, int colum, int flag, int nWin, time_t start)
{
	if (flag == 1)
	{
		mat[playX][playY].flag = 1;
		mat[playX][playY].draw = 'F';
		system("clear");
		Draw(mat, line, colum, 0);
		Play(mat, line, colum, nWin, start);
	}
	if (flag == 0)
	{
		mat[playX][playY].flag = 0;
		mat[playX][playY].draw = 'x';
		system("clear");
		Draw(mat, line, colum, 0);
		Play(mat, line, colum, nWin, start);
	}
}
void PC(Board **mat, int line, int colum, int nWin, time_t start)
{
	int playX = 0, playY = 0;
	Draw(mat, line, colum, 0);
	do
	{
		do
		{
			playX = rand() % line;
			playY = rand() % colum;
		} while (playX > line && playY > colum);
		OpenCell(mat, line, colum, playX, playY, nWin, start);
		Draw(mat, line, colum, 0);
	} while (nWin > 0);
}