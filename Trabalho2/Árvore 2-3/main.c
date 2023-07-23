#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcao.h"

int main()
{
    Arv *raiz;
    raiz = criar_raiz(raiz);
    char palavra_busca[20];
    char nome_arquivo[100];
    int escolha = -1;
    while (escolha != 4)
    {
        printf("\n------- Menu -------\n"
               "1. Ler arquivo\n"
               "2. Exibir árvore\n"
               "3. Buscar Palavra\n"
               "4. Sair\n"
               "5. Remove Palavra\n"
               "---------------------\n"
               "Digite a opção desejada: ");
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
            printf("Digite a palavra que deseja buscar: ");
            scanf(" %[^\n]s", palavra_busca);
            int result = 0;
            buscar_palavra(raiz, palavra_busca, &result);
            if (result == 0)
            {
                printf("\nESSA PALAVRA NAO FOI ENCONTRADA\n");
            }
            break;
        case 4:
            break;
        case 5:
            // Arv *aux;
            // aux = NULL;
            printf("Digite uma palavra que deseja remover: ");
            char palavra_remover[20];
            scanf(" %[^\n]s",palavra_remover);
            remover23(NULL,&raiz,palavra_remover);
            break;
        default:
            printf("Opção inválida. Por favor, tente novamente.\n");
        }
    }
}
