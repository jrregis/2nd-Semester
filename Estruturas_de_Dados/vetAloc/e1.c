#include<stdio.h>
#include<stdlib.h>
#include<curses.h>
int InRet(int x0, int y0, int x1, int y1, int x, int y)
{	
	if( (x<x1 && y<y1) && (x>x0 && y>y0)){
		return 1;
		printf("in\n");
	}
	else {
		printf("out\n");
		return 0;
	}
}

void Le_Pontos(int *x,int *y)
{
	printf("Digite o valor de x\n");
	scanf("%d", x);
	printf("Digite o valor de y\n");
	scanf("%d", y);
}

int main(void)
{
	int x0=0, y0=0, x1=0, y1=0, x=0, y=0, result;
	printf("Ponto inferior esquerdo\n");
	Le_Pontos(&x0,&y0);
	printf("Ponto superior direito\n");
	Le_Pontos(&x1,&y1);
	printf("Ponto a ser verirficado\n");
	Le_Pontos(&x,&y);
	result = InRet(x0, y0, x1, y1, x,y);
	printf("Resultado %d \n", result);
}