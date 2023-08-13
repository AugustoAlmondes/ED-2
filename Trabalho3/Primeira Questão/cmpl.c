#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#define MAX 81

// int contador_glb = 0; // variavel global que usei pra verificar (pode relevar)

int verificar(int pino_2[], int pino_3[], int i)
{
    for (int j = 0; j <= 27; j++)
    {
        if (i == pino_3[j])
        {
            return 3;
        }
        else if (i == pino_2[j])
        {
            return 2;
        }
    }
    return 0;
}

void imprimirGrafo(Graph *G, int n)
{
    printf("Vertices: \n"
           "  ");
    // n = 19;
    for (int i = 0; i < n; i++)
    {
        printf(" %d", i);
    }
    printf("\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", i);
        for (int j = 0; j < n; j++)
        {
            printf("%d ", G->arestas[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print(int vermelho, int amarelo, int verde, int rosa, int i)
{
    printf("vertice = %d, vermelho = %d, amarelo = %d, verde = %i, rosa = %i // vertice %d\n", i, vermelho, amarelo, verde, rosa, i);
}

void linha()
{
    printf("\n"
        "_______________________________________"
        "\n");
}