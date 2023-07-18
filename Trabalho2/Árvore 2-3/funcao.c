#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcao.h"

struct Posicao
{
    int lugar;
    posicao *prox_plavra;
};

struct arvore
{
    char palavra_dois[20], palavra_um[20];
    posicao *psc_palavra_1, *psc_palavra_2;
    struct arvore *filho_esq;
    struct arvore *filho_crt;
    struct arvore *filho_dir;
    int num_chaves;
};

Arv *criar_raiz(Arv *raiz)
{
    return NULL;
}

Arv *quebra_no(Arv **no, char palavra[], char sobe[], Arv *filho, int linha)
{
    Arv *novo;
    if (strcmp(palavra, (*no)->palavra_dois) > 0)
    {
        printf("%s Condicao 1\n", (*no)->palavra_dois);
        printf("%s Sobe\n", sobe);
        strcpy(sobe, (*no)->palavra_dois);
        printf("passou daqui\n");
        novo = cria_no(palavra, (*no)->filho_dir, filho, NULL, linha);
    }
    else if (strcmp(palavra, (*no)->palavra_um) > 0)
    {
        strcpy(sobe, palavra);
        printf("%s Condicao 2\n", palavra);
        novo = cria_no((*no)->palavra_dois, filho, (*no)->filho_dir, NULL, linha);
    }
    else
    {
        printf("%s Condicao 3\n", (*no)->palavra_um);
        strcpy(sobe, (*no)->palavra_um);
        novo = cria_no((*no)->palavra_dois, filho, (*no)->filho_dir, NULL, linha);
        strcpy((*no)->palavra_um, palavra);
    }
    printf("retornou raiz\n");
    (*no)->num_chaves = 1;
    // strcpy((*no)->palavra_dois,NULL);
    return novo;
}

void adicionar_palavra_lista(posicao **raiz, char palavra[], int linha)
{
    if (*raiz == NULL)
    {
        printf("entrou\n");
        *raiz = (posicao *)malloc(sizeof(posicao));
        printf("alocou\n");
        (*raiz)->lugar = linha;
        (*raiz)->prox_plavra = NULL;
    }
    else
    {
        printf("proximo\n");
        adicionar_palavra_lista(&(*raiz)->prox_plavra, palavra, linha);
    }
}

Arv *adiciona_no(Arv *raiz, char palavra[], Arv *filho_dir)
{
    printf("Adiciona no NO\n");
    if (strcmp(palavra, raiz->palavra_um) < 0)
    {
        printf("Palavra eh menor\n");
        // char aux[20];
        // strcpy(aux, raiz->palavra_um);
        // strcpy(raiz->palavra_um, palavra);
        // strcpy(raiz->palavra_dois, aux);
        strcpy(raiz->palavra_dois, raiz->palavra_um);
        strcpy(raiz->palavra_um, palavra);
        raiz->filho_dir = raiz->filho_crt;
        raiz->filho_crt = filho_dir;
    }
    else
    {
        printf("Palavra eh maior\n");
        strcpy(raiz->palavra_dois, palavra);
        raiz->filho_dir = filho_dir;
    }
    raiz->num_chaves = 2;
    return raiz;
}

Arv *eh_folha(Arv *raiz)
{
    if (raiz != NULL && raiz->filho_esq == NULL &&
        raiz->filho_crt == NULL && raiz->filho_dir == NULL)
    {
        return raiz;
    }
    return NULL;
}

Arv *cria_no(char palavra[], Arv *esquerda, Arv *centro, Arv *direita, int linha)
{
    printf("\n\tCriar novo NO\n");
    Arv *novo;
    novo = (Arv *)malloc(sizeof(Arv));
    if (novo == NULL)
    {
        printf("Erro de alocacao\n");
        return NULL;
    }
    strcpy(novo->palavra_um, palavra);
    novo->psc_palavra_1 = (posicao *)malloc(sizeof(posicao));
    novo->psc_palavra_2 = (posicao *)malloc(sizeof(posicao));
    novo->psc_palavra_1->lugar = linha;
    novo->psc_palavra_1->prox_plavra = NULL;
    novo->filho_crt = centro;
    novo->filho_dir = direita;
    novo->filho_esq = esquerda;
    novo->num_chaves = 1;
    printf("\n\tNO Criado\n");
    return novo;
}

Arv *insere_no(Arv **raiz, char palavra[], Arv *pai, char sobe[], int linha)
{
    Arv *maior_no;
    // maior_no = NULL;
    if (*raiz == NULL)
    {
        printf("Raiz eh NULL\n");
        *raiz = cria_no(palavra, NULL, NULL, NULL, linha);
        printf("%s\n", (*raiz)->palavra_um);
    }
    // else if (strcmp((*raiz)->palavra_um, palavra) == 0)
    // {
    //     adicionar_palavra_lista(&(*raiz)->psc_palavra_1, palavra, linha);
    // }
    // else if (strcmp((*raiz)->palavra_dois, palavra) == 0)
    // {
    //     adicionar_palavra_lista(&((*raiz)->psc_palavra_2), palavra, linha);
    // }
    else
    {
        printf("Nao e null\n");
        if (eh_folha(*raiz))
        {
            printf("eh folha\n");
            if (((*raiz)->num_chaves == 1))
            {
                *raiz = adiciona_no(*raiz, palavra, NULL);
                printf("Palavra 1 da Raiz adicionada %s\n", (*raiz)->palavra_um);
                printf("Palavra 2 da Raiz adicionada %s\n", (*raiz)->palavra_dois);
                maior_no = NULL;
            }
            else
            {
                printf("Eh folha e ta completo\n");
                maior_no = quebra_no(raiz, palavra, sobe, NULL, linha);
                printf("Raiz retornada %s\n", (*raiz)->palavra_um);
                if (pai == NULL)
                {
                    *raiz = cria_no(sobe, *raiz, maior_no, NULL, linha);
                    maior_no = NULL;
                }
            }
        }
        else
        {
            if (strcmp(palavra, (*raiz)->palavra_um) < 0)
            {
                printf("Vai pra esquerda\n");
                maior_no = insere_no(&((*raiz)->filho_esq), palavra, *raiz, sobe, linha);
            }
            else if ((*raiz)->num_chaves == 1 || (*raiz)->num_chaves == 2 && (strcmp(palavra, (*raiz)->palavra_dois) < 0))
            {
                printf("Vai pro centro\n");
                maior_no = insere_no((&(*raiz)->filho_crt), palavra, *raiz, sobe, linha);
            }
            else
            {
                printf("Vai pra direita\n");
                maior_no = insere_no((&(*raiz)->filho_dir), palavra, *raiz, sobe, linha);
            }

            if (maior_no != NULL)
            {
                printf("nao eh folha e tem 1 info\n");
                *raiz = adiciona_no(*raiz, sobe, maior_no);
                maior_no = NULL;
            }
            else
            {
                printf("sobrou aqui\n");
                char sobe_novo[20];
                maior_no = quebra_no(raiz, sobe, sobe_novo, maior_no, linha);
                if (pai == NULL)
                {
                    *raiz = cria_no(sobe_novo, *raiz, maior_no, NULL, linha);
                    maior_no = NULL;
                }
            }
        }
    }
    printf("retorna maior no\n");
    return maior_no;
}

// Arv *insere_no(Arv *raiz, char palavra[], Arv *pai, char sobe[], int linha)
// {
//     Arv *maior_no;
//     maior_no = NULL;
//     if (raiz == NULL)
//     {
//         printf("\n--Adicionar %s ao no--\n", palavra);
//         raiz = cria_no(palavra, NULL, NULL, NULL, linha);
//     }
//     else if (strcmp(raiz->palavra_um, palavra) == 0)
//     {
//         adicionar_palavra_lista(&raiz->psc_palavra_1, palavra, linha);
//     }
//     else if (strcmp(raiz->palavra_dois, palavra) == 0)
//     {
//         adicionar_palavra_lista(&(raiz->psc_palavra_2), palavra, linha);
//     }
//     else
//     {
//         if (eh_folha(raiz))
//         {
//             if ((raiz->num_chaves == 1))
//             {
//                 raiz = adiciona_no(raiz, palavra, *maior_no);
//             }
//             else
//             {
//                 maior_no = quebra_no(&raiz, palavra, sobe, NULL, linha);
//                 if (pai == NULL)
//                 {
//                     raiz = cria_no(sobe, raiz, maior_no, NULL, linha);
//                     maior_no = NULL;
//                 }
//             }
//         }
//         else if (strcmp(palavra, (raiz)->palavra_um) == -1)
//         {
//             maior_no = insere_no(raiz->filho_esq, palavra, raiz, sobe, linha);
//         }
//         else if (raiz->num_chaves == 1 || raiz->num_chaves == 2 && (strcmp(palavra, raiz->palavra_dois) == -1))
//         {
//             maior_no = insere_no(raiz->filho_crt, palavra, raiz, sobe, linha);
//         }
//         else
//         {
//             maior_no = insere_no(raiz->filho_dir, palavra, raiz, sobe, linha);
//         }
//         if ((raiz)->num_chaves == 1)
//         {
//             raiz = adiciona_no(raiz, sobe, *maior_no);
//             maior_no = NULL;
//         }
//         else
//         {
//             char sobe_novo[20];
//             maior_no = quebra_no(&raiz, sobe, sobe_novo, maior_no, linha);
//             if (pai == NULL)
//             {
//                 raiz = cria_no(sobe_novo, raiz, maior_no, NULL, linha);
//                 maior_no = NULL;
//             }
//         }
//     }
//     return maior_no;
// }

Arv *ler_arquivo(Arv *raiz, const char *nome_arquivo)
{
    Arv *aux;
    FILE *arquivo;
    arquivo = fopen(nome_arquivo, "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return raiz;
    }

    char linha[1000];
    char *token;
    int linha_atual = 1;
    char sobe[20];

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        printf("fora\n");
        token = strtok(linha, " ");
        while (token != NULL)
        {
            printf("Dentro\n");
            int resp;
            token[strcspn(token, "\n")] = '\0';
            printf("inserir %s\n", token);
            insere_no(&raiz, token, NULL, sobe, linha_atual);
            printf("_______________________________\n");
            // printf("raiz = %s\n", raiz->palavra_um);
            token = strtok(NULL, " ");
            printf("fim\n");
        }
        linha_atual++;
    }
    return raiz;
    fclose(arquivo);
}

void printar_raiz(Arv *raiz)
{
    printf("Exibir raiz\n");
    printf("%s\n", raiz->palavra_um);
}

void exibirNoRecursivo(Arv *no)
{
    if (no != NULL)
    {
        printf("Informacao 1: %s\n", no->palavra_um);
        if (no->num_chaves == 2)
        {
            printf("Informacao 2: %s\n", no->palavra_dois);
        }
        printf("___________________________\n");
        printf("Esquerda\n");
        exibirNoRecursivo(no->filho_esq);
        printf("Centro\n");
        exibirNoRecursivo(no->filho_crt);
        printf("DIreita\n");
        exibirNoRecursivo(no->filho_dir);
    }
}