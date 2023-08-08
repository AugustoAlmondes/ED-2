#include <stdio.h>

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

void print(int vermelho, int amarelo, int verde, int rosa, int i)
{
    printf("inserirValorVertice(G, vertice = %d, vermelho_1 = %d, amarelo_2 = %d, verde_3 = %i, rosa_4 = %i, aresta1 = 2, aresta2 = 7, aresta3 = 8, qtdArestas = 3); // vertice %d\n", i, vermelho, amarelo, verde, rosa, i);
}

void verificar_rosa(int vermelho, int amarelo, int verde, int rosa_pino_2[], int rosa_pino_3[], int i)
{
    int rosa = 1;
    // ROSA
    if (verificar(rosa_pino_2, rosa_pino_3, i) == 3)
    {
        rosa = 3;
        print(vermelho, amarelo, verde, rosa, i);
    }
    // ROSA
    else if (verificar(rosa_pino_2, rosa_pino_3, i) == 2)
    {
        rosa = 2;
        print(vermelho, amarelo, verde, rosa, i);
    }
    // ROSA
    else
    {
        print(vermelho, amarelo, verde, rosa, i);
    }
}

void verificar_verde(int vermelho, int amarelo, int verde_pino_2[], int verde_pino_3[], int rosa_pino_2[], int rosa_pino_3[], int i)
{
    int verde = 1;
    // VERDE
    if (verificar(verde_pino_2, verde_pino_3, i) == 3)
    {
        verde = 3;
        verificar_rosa(vermelho, amarelo, verde, rosa_pino_2, rosa_pino_3, i);
    }
    // VERDE
    else if (verificar(verde_pino_2, verde_pino_3, i) == 2)
    {
        verde = 2;
        verificar_rosa(vermelho, amarelo, verde, rosa_pino_2, rosa_pino_3, i);
    }
    // VERDE
    else
    {
        verificar_rosa(vermelho, amarelo, verde, rosa_pino_2, rosa_pino_3, i);
    }
}

void verificar_amarelo(int vermelho, int amarelo_pino_2[], int amarelo_pino_3[], int verde_pino_2[], int verde_pino_3[], int rosa_pino_2[], int rosa_pino_3[], int i)
{
    int amarelo = 1;
    // AMARELO
    if (verificar(amarelo_pino_2, amarelo_pino_3, i) == 3)
    {
        amarelo = 3;
        verificar_verde(vermelho, amarelo, verde_pino_2, verde_pino_3, rosa_pino_2, rosa_pino_3, i);
    }
    // AMARELO
    else if (verificar(amarelo_pino_2, amarelo_pino_3, i) == 2)
    {
        amarelo = 2;
        verificar_verde(vermelho, amarelo, verde_pino_2, verde_pino_3, rosa_pino_2, rosa_pino_3, i);
    }
    // AMARELO
    else
    {
        verificar_verde(vermelho, amarelo, verde_pino_2, verde_pino_3, rosa_pino_2, rosa_pino_3, i);
    }
}

int main()
{
    int rosa_pino_3[27] = {50, 58, 65, 46, 71, 70, 53, 61, 76, 77, 56, 64, 28, 42, 43, 29, 33, 40, 9, 20, 21, 26, 17, 13, 2, 4, 5};
    int rosa_pino_2[27] = {1, 3, 8, 12, 16, 19, 24, 25, 10, 27, 38, 39, 32, 36, 41, 47, 74, 75, 55, 63, 80, 52, 60, 69, 57, 49, 58};

    int verde_pino_3[27] = {57, 65, 66, 46, 51, 52, 62, 75, 76, 63, 77, 78, 28, 31, 32, 34, 39, 40, 9, 11, 12, 18, 25, 26, 3, 5, 6};
    int verde_pino_2[27] = {4, 7, 8, 10, 13, 14, 35, 41, 42, 47, 53, 54, 64, 79, 80, 15, 19, 20, 27, 29, 30, 59, 69, 70, 58, 67, 68};

    int amarelo_pino_2[27] = {9, 11, 12, 15, 16, 19, 20, 21, 22, 27, 29, 30, 33, 34, 37, 38, 39, 40, 48, 55, 56, 63, 64, 77, 78, 79, 80};
    int amarelo_pino_3[27] = {10, 13, 14, 17, 18, 23, 24, 25, 26, 45, 49, 50, 57, 58, 65, 66, 67, 68, 28, 31, 32, 35, 36, 41, 42, 43, 44};

    int vermelho_pino_3[27] = {27, 29, 30, 33, 34, 37, 38, 39, 40, 45, 46, 49, 50, 51, 52, 57, 58, 59, 60, 65, 66, 67, 68, 69, 70, 71, 72};
    int vermelho_pino_2[27] = {28, 31, 32, 35, 36, 41, 42, 43, 44, 47, 48, 53, 54, 55, 56, 61, 62, 63, 64, 73, 74, 75, 76, 77, 78, 79, 80};
    for (int i = 0; i <= 80; i++)
    {
        int vermelho = 1;
        // VERMELHO
        if (i >= 26 && verificar(vermelho_pino_2, vermelho_pino_3, i) == 3)
        {
            vermelho = 3;
            verificar_amarelo(vermelho, amarelo_pino_2, amarelo_pino_3, verde_pino_2, verde_pino_3, rosa_pino_2, rosa_pino_3, i);
        }
        // VERMELHO
        else if (i >= 26 && verificar(vermelho_pino_2, vermelho_pino_3, i) == 2)
        {
            vermelho = 2;
            verificar_amarelo(vermelho, amarelo_pino_2, amarelo_pino_3, verde_pino_2, verde_pino_3, rosa_pino_2, rosa_pino_3, i);
        }
        // VERMELHO
        else
        {
            verificar_amarelo(vermelho, amarelo_pino_2, amarelo_pino_3, verde_pino_2, verde_pino_3, rosa_pino_2, rosa_pino_3, i);
        }
    }
}