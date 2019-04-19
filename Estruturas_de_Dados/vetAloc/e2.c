#include<stdio.h>
#include<curses.h>
#include<stdlib.h>
void Le_vet(float *v, int n)
{
	printf("Preencha o vetor\n");
	for(int i=0; i<n; i++)
	{
		scanf("%f", &v[i]);
	}
}
int Negativos(float *v, int n)
{
	int count;
	for(int i=0; i<n; i++)
	{
		if(v[i] < 0)
			count ++;
	}
	return count;
}
int main()
{
	float *v;
	int n, qtd;
	printf("Informe o tamanho do vetor\n");
	scanf("%d", &n);
	v = (float *)malloc(n*sizeof(float));
	Le_vet(v, n);
	qtd = Negativos(v,n);
	printf("Quantidade de numeros negativos = %d\n", qtd);
	free(v);
}