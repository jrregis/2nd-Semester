#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
void main()
{
    int i, op;
    system("clear");
    do
    {
        system("clear");
        printf("\n\n1)Criar Grafo\n2)Busca em largura\n3)Busca em profundidade\n4)Sair");
        printf("\nDigite sua opcao: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            readgraph();
            break;

        case 2:
            printf("\nNo de inicio. : ");
            scanf("%d", &i);
            BFS(i);
            break;

        case 3:
            for (i = 0; i < n; i++)
                visited[i] = 0;
            printf("\nNo de inicio : ");
            scanf("%d", &i);
            DFS(i);
            break;
        }
    } while (op != 4);
}