#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcao.h"

int main()
{
    Arv *raiz;
    raiz = criar_raiz(raiz);
    char nome_arquivo[100];
    int escolha = -1;
    while (escolha != 3)
    {
        printf("\n------- Menu -------\n");
        printf("1. Ler arquivo\n");
        printf("2. Exibir árvore\n");
        printf("3. Sair\n");
        printf("---------------------\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            printf("Digite o nome do arquivo: ");
            // scanf("%s", nome_arquivo);
            raiz = ler_arquivo(raiz, "texto.txt");
            // printf("Arquivo lido e árvore construída com sucesso.\n");
            break;
        case 2:
            printf("Exibindo árvore:\n");
            exibirNoRecursivo(raiz);
            break;
        case 3:
            break;
        default:
            printf("Opção inválida. Por favor, tente novamente.\n");
        }
    }

    printar_raiz(raiz);
}
