#include<stdio.h>
#include<curses.h>
struct professor
{
	int codigo;
	float salario;
};
typedef struct professor Professores;
void ReajustaSalario(Professores *prof)
{
	for(int i=1; i<=5; i++)
	{
		prof[i].salario = prof[i].salario+(prof[i].salario*0.10);
	
	}
}
float Media_salarial(Professores *prof)
{
	float md=0, sum=0; 
	for(int i=1; i<=5; i++)
	{
		sum = sum+prof[i].salario;
	}
	md = sum/5;
	return md;
}
int main()
{
	Professores prof[5];
	float md=0;
	printf("Preencha o cadastro dos professores\n");
	for(int i=1; i<=5; i++)
	{
		printf("Digite o codigo do professor %d \n", i);
		scanf("%d", &prof[i].codigo);
		printf("Digite o salario do professor %d \n", i);
		scanf("%f", &prof[i].salario);
	}
	ReajustaSalario(&prof);
	md = Media_salarial(&prof);
	printf("Media Salarial = %f\n", md);
}