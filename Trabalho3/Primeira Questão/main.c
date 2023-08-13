#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main()
{
    Graph *G;
    int opc = -1;

    G = iniciaGrafo(81);
    inserirVertices(G);
    inserirArestas(G);

    while (opc != 4)
    {
        linha();
        printf("Digite a opcao:\n"
        "1 - Imprimir Matriz\n"
        "2 - Dijkstra\n"
        "3 - Ford-Moore-Bellman\n"
        "4 - Sair\n"
        "opcao: ");
        linha();
        scanf(" %d",&opc);
        switch (opc)
        {
        case 1:
            linha();
            printf("\n\tIMPRIMIR MATRIZ\n");
            imprimirGrafo(G, 81);
            break;
        case 2:
            linha();
            printf("\n");
            dijkstra(G, 0, 65, 81);
            printf("\n");
            break;
        case 3:
            linha();
            printf("\n");
            fordMooreBellman(G, 0, 81);
            printf("\n");
            break;

        default:
            break;
        }
    }
}