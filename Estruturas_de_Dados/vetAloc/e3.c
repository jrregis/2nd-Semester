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
void Inverte(int *v, int n)
{
	int aux[n], i, j;
	for(i=n-1, j=0;i>0,j<=n;i--,j++)
	{
		aux[j] = v[i];
	}
	for(int i=0; i<n; i++)
	{
		v[i] = aux[i];
	}
}
int main()
{
	int *v, n;
	printf("Tamanho do vetor\n");
	scanf("%d", &n);
	v = (int *)malloc(n*sizeof(int));
	Le_vet(v, n);
	Inverte(v,n);
	printf("Novo vetor\n");
	for(int i=0; i<n; i++)
	{
		printf("%d\n", v[i]);
	}
	free(v);
}