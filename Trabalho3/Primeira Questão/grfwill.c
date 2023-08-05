#include <stdio.h>
#include <stdlib.h>

#define TAM 80

typedef struct Vertice Vertice;

struct Vertice
{ // vertice
    /* informacao associada a cada noh
     */
    int discos[4];
};
struct arc
{
    int adj;
    /* informacao associada a cada arco */
};

typedef struct Graph Graph;
struct Graph
{
    Vertice *vertices;
    int **arestas;
};

Graph *iniciaGrafo(int n)
{
    Graph *G;

    G = (Graph *)malloc(sizeof(Graph));

    G->vertices = (Vertice *)malloc(n * sizeof(Vertice));
    G->arestas = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        G->arestas[i] = (int *)calloc(n, sizeof(int));
    }

    return G;
}

void imprimirGrafo(Graph *G, int n)
{
    printf("Vertices: \n"
           "  ");
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

void inserirValorVertice(Graph *G, int vertice, int vermelho_1, int amarelo_2, int verde_3, int rosa_4, int aresta1, int aresta2, int aresta3, int qtdArestas)
{
    G->vertices[vertice].discos[0] = vermelho_1;
    G->vertices[vertice].discos[1] = amarelo_2;
    G->vertices[vertice].discos[2] = verde_3;
    G->vertices[vertice].discos[3] = rosa_4;

    if (qtdArestas == 2)
    {
        G->arestas[vertice][aresta1] = 1;
        G->arestas[vertice][aresta2] = 1;
    }
    else if (qtdArestas == 3)
    {
        G->arestas[vertice][aresta1] = 1;
        G->arestas[vertice][aresta2] = 1;
        G->arestas[vertice][aresta3] = 1;
    }
}

void imprimirConteudoVertice(Graph *G, int vertice)
{
    printf("Vertice %d: %d %d %d %d\n", vertice, G->vertices[vertice].discos[0], G->vertices[vertice].discos[1], G->vertices[vertice].discos[2], G->vertices[vertice].discos[3]);
}

int main()
{
    Graph *G;
    int vertice, vermelho_1, amarelo_2, verde_3, rosa_4, aresta1, aresta2, aresta3, qtdArestas;

    G = iniciaGrafo(TAM);

    inserirValorVertice(G, vertice = 0, vermelho_1 = 1, amarelo_2 = 1, verde_3 = 1, rosa_4 = 1, aresta1 = 1, aresta2 = 2, aresta3 = 0, qtdArestas = 2); // vertice 0
    inserirValorVertice(G, vertice = 1, vermelho_1 = 1, amarelo_2 = 1, verde_3 = 1, rosa_4 = 2, aresta1 = 0, aresta2 = 2, aresta3 = 3, qtdArestas = 3); // vertice 1
    inserirValorVertice(G, vertice = 2, vermelho_1 = 1, amarelo_2 = 1, verde_3 = 1, rosa_4 = 3, aresta1 = 0, aresta2 = 1, aresta3 = 4, qtdArestas = 3); // vertice 2
    inserirValorVertice(G, vertice = 3, vermelho_1 = 1, amarelo_2 = 1, verde_3 = 3, rosa_4 = 2, aresta1 = 1, aresta2 = 5, aresta3 = 6, qtdArestas = 3); // vertice 3
    inserirValorVertice(G, vertice = 4, vermelho_1 = 1, amarelo_2 = 1, verde_3 = 2, rosa_4 = 3, aresta1 = 2, aresta2 = 7, aresta3 = 8, qtdArestas = 3); // vertice 4
    inserirValorVertice(G, vertice = 5, vermelho_1 = 1, amarelo_2 = 1, verde_3 = 3, rosa_4 = 3, aresta1 = 3, aresta2 = 6, aresta3 = 9, qtdArestas = 3); // vertice 5
    inserirValorVertice(G, vertice = 6, vermelho_1 = 1, amarelo_2 = 1, verde_3 = 3, rosa_4 = 1, aresta1 = 3, aresta2 = 5, aresta3 = 7, qtdArestas = 3); // vertice 6
    
    imprimirGrafo(G, TAM);
    imprimirConteudoVertice(G, 0);
    imprimirConteudoVertice(G, 1);
    imprimirConteudoVertice(G, 2);
    return 0;
}
