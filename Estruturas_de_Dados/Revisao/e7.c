#include<stdio.h>
#include<curses.h>
struct empregado
{
char nome[40];
int numeroDependentes;
float salario;
};
typedef struct empregado Empregado;
void Reajuste(Empregado *emp)
{
	for(int i=0; i<5; i++){
		if(emp[i].numeroDependentes > 0)
			emp[i].salario = emp[i].salario + (emp[i].salario * 0.20);
		else
			emp[i].salario = emp[i].salario + (emp[i].salario * 0.05);
	}
}
int main()
{
	Empregado emp[5];
	printf("Preencha o cadastro dos funcionarios\n");
	for(int i=0; i<5; i++)
	{
		printf("Digite o nome:  ");
		scanf("%s", emp[i].nome);
		printf("Digite o numero de dependentes ");
		scanf("%d", &emp[i].numeroDependentes);
		printf("Digite o salario ");
		scanf("%f", &emp[i].salario);
	}
	Reajuste(emp);
	for(int i=0; i<5; i++)
	{
		printf("Empregado : %s \n", emp[i].nome);
		printf("Numero de dependentes: %d \n", emp[i].numeroDependentes);
		printf("Salario: %.2f \n", emp[i].salario);
	}
}