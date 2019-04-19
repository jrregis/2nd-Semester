#include<stdio.h>
#include<curses.h>
#include <stdlib.h>
void Le_vet(int tamanho, float *vet)
{
	printf("Preencha o vetor\n");

	for(int i = 1; i<=6; i++)
	{
		scanf("%f", &vet[i]);
	}
}

void Imprime(float *vet)
{
	for(int i = 1; i<=6; i++)
	{
		printf(" Posicao [%d] %0.2f\n", i, vet[i]);
	}
}

float Maior(float *vet)
{
	float maior = 0;
	for(int i=1; i<=6; i++)
	{
		if(maior < vet[i])
			maior = vet[i];
	}

	return maior;
}

void Desloca_vet(float *vet, float maior)
{	
	float temp = 0;
	do{
		temp = vet[1];
		for(int i =1; i<=6; i++)
		{
			if(i < 6 && vet[1])
			{
				vet[i] = vet[i+1];
			}
			else if(i == 6 && vet[1])
			{
				vet[i] = temp;
			}
		}		
	}while(vet[1] != maior);
}
int main()
{
	float vet[6] ; 
	float maior = 0;
	Le_vet(6, &vet);
	maior = Maior(&vet);
	printf("Maior = %f\n", maior);
	printf("Antes de deslocar\n");
	Imprime(&vet);
	Desloca_vet(&vet, maior);
	printf("Apos de deslocar\n");
	Imprime(&vet);	
}