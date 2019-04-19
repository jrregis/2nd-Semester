#include<stdio.h>
#include<curses.h>
void PreencheMat(int mat[5][5])
{
	for(int i = 0; i<5; i++)
	{
		for(int j=0; j<5; j++)
		{
			printf("Preencha a matriz na linha %d coluna %d\n", i, j);
			scanf("%d", &mat[i][j]);
		}
	}
}
void ImprimeMat(int mat[5][5])
{
	printf("Imprimindo matriz\n");
	for(int i = 0; i<5; i++)
	{
		printf("\n");
		for(int j=0; j<5; j++)
		{
			printf("%d ", mat[i][j]);
		}
	}
}
void Maior(int mat[5][5], int *maior)
{
	for(int i=0;i<5; i++)
	{
		for(int j=0; j<5; j++)
		{
			if(maior[i] < mat[i][j])
			{
				maior[i] = mat[i][j];
			}
		}
	}
	printf("\n");
	for(int i=0; i<5; i++)
	{
		printf("Maior da linha %d = %d \n", i, maior[i]);
	}
}
void Media(int *maior)
{
	float sum, md;
	for(int i=0; i<5; i++)
	{
		sum = sum+maior[i];
	}
	md = sum/5;
	printf("Media dos maiores = %f\n",md);
}
int main()
{
	int mat[5][5], maiores[5]= {0,0,0,0,0};
	PreencheMat(mat);
	ImprimeMat(mat);
	Maior(mat, maiores);
	Media(maiores);
}