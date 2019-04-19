#include<stdio.h>
#include<curses.h>
#include<stdlib.h>
void Le_vet(int *v, int n)
{
	printf("Preencha o vetor\n");
	for(int i=0; i<n; i++)
	{
		scanf("%d", &v[i]);
	}
}
void AlocaVet(int *v, int n)
{
	v = (int *)malloc(n*sizeof(int));
}
float Media(int *v, int n)
{
	float md=0;
	for(int i=0; i<n; i++)
	{
		md+=v[i];
	}
	md/=n;
	return md;
}
void Maiores(float md, int *v, int n)
{
	float count=0;
	for(int i=0; i<n; i++)
	{
		if(v[i] > md)
		{	
			count++;
		}
	}
	count= (count*100)/n;
	printf("Percentual = %.0f%\n", count);
}
int main()
{
	int *v, n;
	float md;
	printf("Tamanho do vetor\n");
	scanf("%d", &n);
	AlocaVet(v,n);
	Le_vet(v, n);
	md = Media(v, n);
	Maiores(md, v, n);
	free(v);
}