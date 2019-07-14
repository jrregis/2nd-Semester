#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h>
#include <stdlib.h>
#define MAX 20 //valor arbitrário
int visited[MAX];
int n;

typedef struct Q
{
    int data[MAX];
    int R, F;
} Q;

typedef struct node
{
    struct node *next;
    int vertex;
} node;
node *G[20]; //head da lista de adj
void enqueue(Q *, int);
int dequque(Q *);
int empty(Q *);
int full(Q *);

void BFS(int);
void readgraph();
void insert(int vi, int vj);
void DFS(int i);

#endif