#include<stdio.h>
void Func1(int *v)
{
	printf("Inverso\n");
	for(int i=9; i>=0; i--)
		printf("%d\n", v[i]);
}
int main()
{
	int *v;
	v = (int *)malloc(10*sizeof(int));
	printf("Preencha o vetor\n");
	for(int i=0; i<10; i++)
	{
		scanf("%d", &v[i]);
	}
	Func1(v);
	free(v);
}