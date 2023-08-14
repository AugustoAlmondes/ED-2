#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#define MAX 81

int encontrarVerticeMinimo(int distancias[], int visitados[], int numVertices)
{
    int minimo = 999;
    int indiceMinimo;

    for (int v = 0; v < numVertices; v++)
    {
        if (!visitados[v] && distancias[v] <= minimo)
        {
            minimo = distancias[v];
            indiceMinimo = v;
        }
    }

    return indiceMinimo;
}

void dijkstra(Graph *grafo, int origem, int destino, int numVertices)
{
    int *distancias = (int *)malloc(numVertices * sizeof(int));
    int *caminho = (int *)malloc(numVertices * sizeof(int));
    int *visitados = (int *)malloc(numVertices * sizeof(int));

    for (int i = 0; i < numVertices; i++)
    {
        distancias[i] = 999;
        visitados[i] = 0;
    }

    distancias[origem] = 0;

    for (int count = 0; count < numVertices - 1; count++)
    {
        int u = encontrarVerticeMinimo(distancias, visitados, numVertices);
        visitados[u] = 1;

        for (int v = 0; v < numVertices; v++)
        {
            if (!visitados[v] && grafo->arestas[u][v] && distancias[u] != 999 && distancias[u] + grafo->arestas[u][v] < distancias[v])
            {
                distancias[v] = distancias[u] + grafo->arestas[u][v];
                caminho[v] = u;
            }
        }
    }

    printf("Caminho mais curto de %d para %d: %d", origem, destino, distancias[destino]);
    printf("\nCaminho: ");

    int i = destino;
    printf("%d", i);

    while (caminho[i] != origem)
    {
        printf(" <- %d", caminho[i]);
        i = caminho[i];
    }

    printf(" <- %d", origem);
}

void fordMooreBellman(Graph *grafo, int origem, int numVertices)
{
    int *distancias = (int *)malloc(numVertices * sizeof(int));
    int *caminho = (int *)malloc(numVertices * sizeof(int));

    for (int i = 0; i < numVertices; i++)
    {
        distancias[i] = 999;
        caminho[i] = -1;
    }

    distancias[origem] = 0;

    for (int count = 0; count < numVertices - 1; count++)
    {
        for (int u = 0; u < numVertices; u++)
        {
            for (int v = 0; v < numVertices; v++)
            {
                if (grafo->arestas[u][v] && distancias[u] != 999 && distancias[u] + grafo->arestas[u][v] < distancias[v])
                {
                    distancias[v] = distancias[u] + grafo->arestas[u][v];
                    caminho[v] = u;
                }
            }
        }
    }

    printf("Caminhos mais curtos a partir de %d:\n", origem);
    for (int i = 0; i < numVertices; i++)
    {
        printf("Para %d: ", i);
        int j = i;
        while (caminho[j] != -1)
        {
            printf("%d <- ", j);
            j = caminho[j];
        }
        printf("%d Distancia: %d\n", j, distancias[i]);
    }
}