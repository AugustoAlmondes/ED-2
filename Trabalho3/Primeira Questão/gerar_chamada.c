#include <stdio.h>

int verificar_amarelo(int pino_2[], int pino_3[], int i)
{
    for (int j = 0; j < 27; j++)
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

int verificar_vermelho(int pino_2[], int pino_3[], int i)
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

int main()
{
    int amarelo_pino_2[27] = {9, 11, 12, 15, 16, 19, 20, 21, 22, 27, 29, 30, 33, 34, 37, 38, 38, 40, 48, 55, 56, 63, 64, 77, 78, 79, 80};
    int amarelo_pino_3[27] = {10, 13, 14, 17, 18, 23, 24, 25, 26, 45, 49, 50, 57, 58, 65, 66, 67, 68, 28, 31, 32, 35, 36, 41, 42, 43, 44};
    int vermelho_pino_3[27] = {27, 29, 30, 33, 34, 37, 38, 39, 40, 45, 46, 49, 50, 51, 52, 57, 58, 59, 60, 65, 66, 67, 68, 69, 70, 71, 72};
    int vermelho_pino_2[27] = {28, 31, 32, 35, 36, 41, 42, 43, 44, 47, 48, 53, 54, 55, 56, 61, 62, 63, 64, 73, 74, 75, 76, 77, 78, 79, 80};
    for (int i = 0; i <= 80; i++)
    {
        int vermelho = 1;
        int amarelo = 1;
        if (i >= 26 && verificar_vermelho(vermelho_pino_2, vermelho_pino_3, i) == 3)
        {
            vermelho = 3;
            if (verificar_amarelo(amarelo_pino_2, amarelo_pino_3, i) == 3)
            {
                amarelo = 3;
                printf("inserirValorVertice(G, vertice = %d, vermelho_1 = %d, amarelo_2 = %d, verde_3 = 2, rosa_4 = 3, aresta1 = 2, aresta2 = 7, aresta3 = 8, qtdArestas = 3); // vertice %d\n", i, vermelho, amarelo, i);
            }
            else if (verificar_amarelo(amarelo_pino_2, amarelo_pino_3, i) == 2)
            {
                amarelo = 2;
                printf("inserirValorVertice(G, vertice = %d, vermelho_1 = %d, amarelo_2 = %d, verde_3 = 2, rosa_4 = 3, aresta1 = 2, aresta2 = 7, aresta3 = 8, qtdArestas = 3); // vertice %d\n", i, vermelho, amarelo, i);
            }
            else
            {
                printf("inserirValorVertice(G, vertice = %d, vermelho_1 = %d, amarelo_2 = %d, verde_3 = 2, rosa_4 = 3, aresta1 = 2, aresta2 = 7, aresta3 = 8, qtdArestas = 3); // vertice %d\n", i, vermelho, amarelo, i);
            }
        }
        else if (i >= 26 && verificar_vermelho(vermelho_pino_2, vermelho_pino_3, i) == 2)
        {
            vermelho = 2;
            if (verificar_amarelo(amarelo_pino_2, amarelo_pino_3, i) == 3)
            {
                amarelo = 3;
                printf("inserirValorVertice(G, vertice = %d, vermelho_1 = %d, amarelo_2 = %d, verde_3 = 2, rosa_4 = 3, aresta1 = 2, aresta2 = 7, aresta3 = 8, qtdArestas = 3); // vertice %d\n", i, vermelho, amarelo, i);
            }
            else if (verificar_amarelo(amarelo_pino_2, amarelo_pino_3, i) == 2)
            {
                amarelo = 2;
                printf("inserirValorVertice(G, vertice = %d, vermelho_1 = %d, amarelo_2 = %d, verde_3 = 2, rosa_4 = 3, aresta1 = 2, aresta2 = 7, aresta3 = 8, qtdArestas = 3); // vertice %d\n", i, vermelho, amarelo, i);
            }
            else
            {
                printf("inserirValorVertice(G, vertice = %d, vermelho_1 = %d, amarelo_2 = %d, verde_3 = 2, rosa_4 = 3, aresta1 = 2, aresta2 = 7, aresta3 = 8, qtdArestas = 3); // vertice %d\n", i, vermelho, amarelo, i);
            }
        }

        else
        {
            if (verificar_amarelo(amarelo_pino_2, amarelo_pino_3, i) == 3)
            {
                amarelo = 3;
                printf("inserirValorVertice(G, vertice = %d, vermelho_1 = %d, amarelo_2 = %d, verde_3 = 2, rosa_4 = 3, aresta1 = 2, aresta2 = 7, aresta3 = 8, qtdArestas = 3); // vertice %d\n", i, vermelho, amarelo, i);
            }
            else if (verificar_amarelo(amarelo_pino_2, amarelo_pino_3, i) == 2)
            {
                amarelo = 2;
                printf("inserirValorVertice(G, vertice = %d, vermelho_1 = %d, amarelo_2 = %d, verde_3 = 2, rosa_4 = 3, aresta1 = 2, aresta2 = 7, aresta3 = 8, qtdArestas = 3); // vertice %d\n", i, vermelho, amarelo, i);
            }
            else
            {
                printf("inserirValorVertice(G, vertice = %d, vermelho_1 = %d, amarelo_2 = %d, verde_3 = 2, rosa_4 = 3, aresta1 = 2, aresta2 = 7, aresta3 = 8, qtdArestas = 3); // vertice %d\n", i, vermelho, amarelo, i);
            }
        }
    }
}