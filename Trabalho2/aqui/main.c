#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcao.h"

int main()
{
    NO *raiz;
    raiz = criar_raiz(raiz);
    raiz = ler_arquivo(raiz, "palavras.txt");
    char palavra[20];
    char palavra_busca[20];
    int acao = -1;
    // exibir_palavras(raiz);
    while (acao != 5)
    {
        int achou = 0;
        int opc = -1;
        printf("___________________________\n"
               "           MENU            \n");
        printf("___________________________\n");
        printf("Qual acao deseja realiza:\n"
               "1 - Exibir lista\n"
               "2 - Procurar palavra\n"
               "3 - Excluir palavra\n"
               "4 - Adicionar palavra\n"
               "5 - sair\n"
               "___________________________\n"
               "Opcao: ");
        scanf(" %d", &acao);
        switch (acao)
        {
        case 1:
            printf("___________________________\n"
                   "MOSTRAR TODAS AS PALAVRAS\n"
                   "___________________________\n");
            exibir_palavras(raiz);
            break;
        case 2:
            printf("___________________________\n"
                   " MOSTRAR UMA UNICA PALAVRA\n"
                   "___________________________\n");
            while ((opc != 2))
            {
                printf("\ndeseja procurar uma palavra?\n1 - Sim\n2 - Nao\nOpcao: ");
                scanf(" %d", &opc);
                switch (opc)
                {
                case 1:
                    achou = 0;
                    printf("\nDigite a palvra que deseja buscar: ");
                    scanf(" %[^\n]s", palavra);
                    printf("\n");
                    exibir_no(raiz, palavra, &achou);
                    printf("\n");
                    if (achou == 0)
                    {
                        printf("A palavra nao foi encontrada ou nao existe\n");
                    }
                case 2:
                    break;
                    break;
                default:
                    printf("Opcao não existe\n");
                    break;
                }
            }

            break;
        case 3:
            while (opc != 2)
            {
                printf("___________________________\n"
                       "    EXLUIR UMA PALAVRAS\n"
                       "___________________________\n");
                printf("deseja excluir uma palavra\n1 - Sim\n2 - Nao\nOpcao: ");
                scanf(" %d", &opc);
                switch (opc)
                {
                case 1:
                    printf("\nDigite a palavra que deseja procurar: ");
                    scanf(" %[^\n]s", palavra_busca);
                    excluir_palavra(raiz, palavra_busca, &achou);
                    break;
                case 2:
                    break;
                default:
                    printf("Valor inexistente\n");
                    break;
                }
            }
            break;
        case 4:
            printf("___________________________\n"
                   "   ADICIONAR UMA PALAVRAS  \n"
                   "___________________________\n");
            char palavra_adc[20];
            int linha;
            printf("Digite a palvra que deseja adicionar: ");
            scanf("%s", palavra_adc);
            printf("Digite a linha da palavra: ");
            scanf(" %d", &linha);
            raiz = insere_arv(raiz, palavra_adc, &achou, linha);
            break;
        default:
            printf("   ESSA OPCAO NAO EXISTE\n");
            break;
        }
    }
}