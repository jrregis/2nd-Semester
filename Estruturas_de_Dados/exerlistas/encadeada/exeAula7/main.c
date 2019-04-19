#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include "lista.h"
int main(void)
{
  Lista *l, *l2, *l3;
  int op = 0;
  int conprimentoLista = 0, num = 0;
  Lista *end = 0;
  int maioresN = 0;
  l = lst_cria();
  l2 = lst_cria();
  l3 = lst_cria();
  l = lst_insere(l, 23);
  l = lst_insere(l, 45);
  printf("Lista 1:\n");
  lst_imprime(l);
  l2 = lst_insere(l2, 10);
  l2 = lst_insere(l2, 50);
  printf("Lista 2:\n");
  lst_imprime(l2);
  /*int retorno = lst_vazia (l);
if (retorno==1)
	printf ("\nLista Vazia\n");
else
	printf ("\nLista NAO Vazia\n");
Lista* lis= busca (l, 23);
if(lis==NULL)
printf ("\nO no de valor %d nao foi encontrado\n", lis->info);
else
printf ("\nO no de valor %d foi encontrado\n", lis->info);
*/
  printf("Exercicios dia 7\n");
  printf("1-E1 2-E2 3-E3 4-E4\n");
  scanf("%d", &op);
  switch (op)
  {
  case 1:

    conprimentoLista = comprimento(l);
    printf("Numero de itens da lista = %d\n", conprimentoLista);
    break;
  case 2:
    printf("Digite o valor para ver quantos valores maiores que ele existem na lista\n");
    scanf("%d", &num);
    maioresN = maiores(l, num);
    printf("Existem %d valores na lista maiores que %d\n", maioresN, num);
    break;
  case 3:
    end = ultimo(l);
    printf("O ultimo elemento da lista eh %d no endereco %p e o proximo %p eh null\n", end->info, end, end->prox);
    break;
  case 4:
    l3 = Concat(l, l2);
    printf("Lista 3:\n");
    lst_imprime(l3);
  }

  return 0;
}