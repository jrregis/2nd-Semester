#include<stdio.h>
#include<curses.h>
int SomaLinha(int mat[3][3])
{
	int iguais = 0, sumL0=0, sumL1=0, sumL2=0;
	for(int i = 0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(i == 0)
				sumL0 = sumL0+mat[i][j];
			if(i == 1)
				sumL1 = sumL1+mat[i][j];
			if(i == 2)
				sumL2 = sumL2+mat[i][j];
		}
	}
	if(sumL0 == sumL1 && sumL1 == sumL2)
		iguais = 1;
	else 
		iguais = 0;
	return iguais;
}
int SomaColuna(int mat[3][3])
{
	int iguais = 0, sumC0=0, sumC1=0, sumC2=0;
	for(int i = 0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(i == 0)
				sumC0 = sumC0+mat[i][j];
			if(i == 1)
				sumC1 = sumC1+mat[i][j];
			if(i == 2)
				sumC2 = sumC2+mat[i][j];
		}
	}
	if(sumC0 == sumC1 && sumC1 == sumC2)
		iguais = 1;
	else 
		iguais = 0;
	return iguais;
}
int SomaDP(int mat[3][3])
{
	int sumDP=0;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++){
			if(i == j)
				sumDP = sumDP + mat[i][j];
		}
	}
	return sumDP;
}
int SomaDS(int mat[3][3])
{
	int sumDS=0;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++){
			if(i == 3-1-j)
				sumDS = sumDS+mat[i][j];
		}
	}
	return sumDS;
}
void VerificaQuadrado(int col, int lin, int dp, int ds)
{
	int quadrado = 0; 

	if(col == lin && dp == ds){
		printf("A matriz eh um quadrado magico\n");
	}
	else{
		printf("A matriz nao eh um quadrado magico\n");
	}
}
void PreencheMat(int mat[3][3])
{
	for(int i = 0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			printf("Preencha a matriz na linha %d coluna %d\n", i, j);
			scanf("%d", &mat[i][j]);
		}
	}
}
void ImprimeMat(int mat[3][3])
{
	printf("Imprimindo matriz\n");
	for(int i = 0; i<3; i++)
	{
		printf("\n");
		for(int j=0; j<3; j++)
		{
			printf("%d ", mat[i][j]);
		}
	}
}
int main()
{
	int mat[3][3], igualC, igualL, sumDP, sumDS, quadrado;
	PreencheMat(mat);
	ImprimeMat(mat);
	igualL = SomaLinha(mat);
	igualC = SomaColuna(mat);
	sumDP  = SomaDP(mat);
	sumDS  = SomaDS(mat);
	VerificaQuadrado(igualC, igualL, sumDP, sumDS);
}