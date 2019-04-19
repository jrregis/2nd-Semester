#include<stdio.h>
#include<curses.h>

struct usuario
{
char sexo;
int idade;
int qtdade;
};
typedef struct usuario Usuario;
void LeVet(int tam, Usuario *user)
{
	printf("Responda a pesquisa\n");
	for(int i=1; i<=tam; i++)
	{
		printf("Digite seu sexo(M/F)\n");
		scanf("%s", &user[i].sexo);
		printf("Digite sua idade\n");
		scanf("%d", &user[i].idade);
		printf("Digite a quantidade de livros lidos\n");
		scanf("%d", &user[i].qtdade);
	}
}
int CalculaLivros(int tam, Usuario *user)
{
	int qtd=0;
	for(int i=1; i<=5; i++)
	{
		if(user[i].idade == 10)
		{
			qtd = qtd + user[i].qtdade;
		}
	}
	return qtd;
}
int CalculaM(int tam, Usuario *user)
{
	int qtd=0;
	for(int i=1; i<=5; i++)
	{
		if(user[i].sexo == 'f' && user[i].qtdade >= 5)
		{
			qtd++;
		}
	}
	return qtd;
}
int main()
{
	int qtd10, qtdM;
	Usuario users[5];
	LeVet(5, &users);
	qtd10 = CalculaLivros(5, &users);
	qtdM  = CalculaM(5, &users);
	
	printf("Livros lidos por criancas de 10 anos = %d\n", qtd10);
	printf("Mulheres que leram 5 livros ou mais  = %d\n", qtdM);
}