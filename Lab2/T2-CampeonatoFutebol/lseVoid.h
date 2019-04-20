#ifndef LSEVOID_H
#define LSEVOID_H

#include <stdbool.h>
typedef struct Node
{
    void *info;
    struct Node *next;
} Node;

Node *createList(void);                     //APONTA A LISTA PARA NULL
bool emptyList(Node *head);                 //VERIFICA SE A LISTA EH VAZIA
Node *insertEnd(Node *head, void *element); //INSERE UM ELEMENTO NO FIM DA LISTA
Node *insertTop(Node *head, void *element); //INSERE UM ELEMENTO NO COMECO DA LISTA
Node *freeList(Node *head);                 //LIBERA A LISTA DA MEMORIA
Node *lastNode(Node *head);                 //ACHA O ULTIMO NO DA LISTA

void show(Node *head, void showElement(void *));               //RECEBE A LISTA E UM PONTEIRO PARA IMPRIMIR CADA ELEMENTO DA LISTA NA showElement()
void *searching(Node *head, int id, bool equal(void *, int));  //RECEBE A LISTA E UM PONTEIRO PARA UMA FUNCAO QUE COMPORA DOIS ELEMENTO DA LISTA
Node *removeNode(Node *head, int id, bool equal(void *, int)); //RECEBE A LISTA E UM PONTEIRO PARA UMA FUNCAO QUE COMPORA DOIS ELEMENTO DA LISTA

#endif