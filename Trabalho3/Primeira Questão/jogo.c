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