#include "graph.h"

int dequeue(Q *P)
{
    int x;
    x = P->data[P->F];

    if (P->R == P->F)
    {
        P->R = -1;
        P->F = -1;
    }
    else
        P->F = P->F + 1;
    return x;
}

int empty(Q *P) { return (P->R == -1); }

int full(Q *P) { return (P->R == MAX - 1); }

void enqueue(Q *P, int x)
{
    if (P->R == -1)
    {
        P->R = P->F = 0;
        P->data[P->R] = x;
    }
    else
    {
        P->R = P->R + 1;
        P->data[P->R] = x;
    }
}

void BFS(int v)
{
    int w, i, visited[MAX];
    Q q;

    node *p;
    q.R = q.F = -1;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(&q, v);
    printf("\t%d ", v);
    visited[v] = 1;

    while (!empty(&q))
    {
        v = dequeue(&q);

        for (p = G[v]; p != NULL; p = p->next)
        {
            w = p->vertex;
            if (visited[w] == 0)
            {
                enqueue(&q, w);
                visited[w] = 1;
                printf(" %d ", w);
            }
        }
    }
}

void DFS(int i)
{
    node *p;

    printf("\%d ", i);

    p = G[i];
    visited[i] = 1;

    while (p != NULL)
    {
        i = p->vertex;
        if (!visited[i])
            DFS(i);
        p = p->next;
    }
}

void readgraph()
{
    int i, vi, vj, no_of_edges;
    printf("\nEntre com o nr de vertices :");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        G[i] = NULL;

    printf("\nEntre a quantidade de arestas :");
    scanf("%d", &no_of_edges);
    for (i = 0; i < no_of_edges; i++)
    {
        printf("\nEntre com o valor da aresta:");
        scanf("%d%d", &vi, &vj);
        insert(vi, vj);
        insert(vj, vi);
    }
}

void insert(int vi, int vj)
{
    node *p, *q;

    q = (node *)malloc(sizeof(node));
    q->vertex = vj;
    q->next = NULL;

    if (G[vi] == NULL)
        G[vi] = q;
    else
    {
        p = G[vi];
        while (p->next != NULL)
            p = p->next;
        p->next = q;
    }
}
