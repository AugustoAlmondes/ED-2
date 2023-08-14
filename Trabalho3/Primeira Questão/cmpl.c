#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#define MAX 81

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