#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"


void posicao_aresta(int *vetorVertice, int *vetorResposta, int *cont)
{
    *cont = 0;

    for (int i = 0; i < 81; i++)
    {
        if (vetorVertice[i] == 1)
        {
            if (*cont == 0)
                vetorResposta[0] = i;
            if (*cont == 1)
                vetorResposta[1] = i;
            if (*cont == 2)
                vetorResposta[2] = i;
            *cont += 1;
        }
    }
};

void jogar(Graph *G, int vertice)
{
    int vetorResposta[3], cont, flagParada = 1;

    if (G->vertices[vertice].discos[0] == 3 && G->vertices[vertice].discos[1] == 3 &&
        G->vertices[vertice].discos[2] == 3 && G->vertices[vertice].discos[3] == 3)
    {
        printf("\nVertice atual e conteudo.\n ");
        print_conteudo(G, vertice);
    }
    else
    {

        while (G->vertices[vertice].discos[0] != 3 && G->vertices[vertice].discos[1] != 3 &&
            G->vertices[vertice].discos[2] != 3 && G->vertices[vertice].discos[3] != 3 &&
            flagParada != 0)
        {

            printf("\nVertice atual e conteudo.\n ");
            print_conteudo(G, vertice);
            printf("Possibilidades de para onde pode ir: \n");

            zerar_vetor(vetorResposta);

            posicao_aresta(G->arestas[vertice], vetorResposta, &cont);

            print_conteudo(G, vetorResposta[0]);
            print_conteudo(G, vetorResposta[1]);

            if (cont == 3)
            {
                print_conteudo(G, vetorResposta[2]);
            }

            printf("\nDigite o indice do vertice que deseja ir: ");
            scanf("%d ", &vertice);

            if ((vertice < 0 && vertice > 80) && (vertice != vetorResposta[0] && vertice != vetorResposta[1] && vertice != vetorResposta[2]))
            {
                printf("Indice de vertice não existe.\n");
                flagParada = 0;
            }
        }
    }
    printf("Voce venceu\n");
}

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

void print_conteudo(Graph *G, int i)
{
    printf("vertice = %d, vermelho = %d, amarelo = %d, verde = %i, rosa = %i // vertice %d\n", i, G->vertices[i].discos[0], G->vertices[i].discos[1], G->vertices[i].discos[2], G->vertices[i].discos[3], i);
}

void linha()
{
    printf("\n"
           "_______________________________________"
           "\n");
}

int condicao_vitoria(Graph *G, int i)
{
    int result = 0; // 0 falso -- 1 verdadeiro
    if (G->vertices[i].discos[0] == 3 && G->vertices[i].discos[1] == 3 &&
        G->vertices[i].discos[2] == 3 && G->vertices[i].discos[3] == 3)
    {
        result = 1;
    }
    return result;
}

void zerar_vetor(int *vetorResposta)
{
    for (int i = 0; i < 3; i++)
    {
        free(vetorResposta);
        vetorResposta = (int *)malloc(sizeof(int));
    }
}