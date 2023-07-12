#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcao.h"
#define RED 1
#define BLACK 0

struct Posicao
{
    int lugar;
    psc *prox;
};

struct no
{
    char palavra[100];
    psc *local;
    struct no *esq;
    struct no *dir;
    int cor;
};

// ACESSAAR A COR DE UM NÓ
int cor(NO *H)
{
    int cor;
    if (H == NULL)
    {
        cor = BLACK;
    }
    else
    {
        cor = RED;
    }
    return cor;
}

// TROCAR DE COR
NO *trocar_cor(NO *H)
{
    if (H != NULL)
    {
        H->cor = !H->cor;
        if (H->esq != NULL)
        {
            H->esq->cor = !H->esq->cor;
        }
        if (H->dir != NULL)
        {
            H->dir->cor = !H->dir->cor;
        }
        return H;
    }
}
// ROTACAO ESQUERDA
NO *rotacionaEsquerda(NO *raiz)
{
    // NO *novo;
    // novo = raiz->dir;
    // raiz->dir = novo->esq;
    // novo->esq = raiz;
    // novo->cor = raiz->cor;
    // raiz->cor = RED;
    // return novo;

    NO *aux;

    aux = raiz->dir;
    raiz->dir = aux->esq;
    aux->esq = raiz;
    raiz = aux;

    raiz->cor = raiz->esq->cor;
    raiz->esq->cor = RED;
    return aux;
}
// ROTACAO DIREITA
NO *rotacionaDireita(NO *raiz)
{
    // NO *novo = raiz->esq;
    // raiz->esq = novo->dir;
    // novo->dir = raiz;
    // novo->cor = raiz->cor;
    // raiz->cor = RED;
    // return novo;
    NO *aux;

    aux = raiz->esq;
    raiz->esq = aux->dir;
    aux->dir = raiz;
    raiz = aux;

    raiz->cor = raiz->dir->cor;
    raiz->dir->cor = RED;
    return aux;
}

psc *adicionar_lista_encadeada(psc *no, char palavra_adc[], int linha)
{
    if (no == NULL)
    {
        no = (psc *)malloc(sizeof(psc));
        if (no != NULL)
        {
            printf("Memoria alocada\n");
            no->lugar = linha;
            no->prox = NULL;
            printf("Palavra adiconada a lista\n");
            return no;
        }
    }
    else
    {
        no->prox = adicionar_lista_encadeada(no->prox, palavra_adc, linha);
    }
    return no;
}

NO *cria_no(char palavra_adc[], int linha, int *resp)
{
    NO *novo;
    novo = (NO *)malloc(sizeof(NO));
    if (novo == NULL)
    {
        printf("Erro de alocacao\n");
        *resp = 0;
        return NULL;
    }
    strcpy(novo->palavra, palavra_adc);
    novo->local = (psc *)malloc(sizeof(psc));
    novo->local->lugar = linha;
    novo->local->prox = NULL;
    novo->cor = RED;
    novo->dir = NULL;
    novo->esq = NULL;
    *resp = 1;
    return novo;
}

NO *insere_no(NO *H, char palavra_adc[], int *resp, int linha)
{
    if (H == NULL)
    {

        printf("Adiciona\n");
        H = cria_no(palavra_adc, linha,resp);
        // NO *novo;
        // novo = (NO *)malloc(sizeof(NO));
        // if (novo == NULL)
        // {
        //     printf("Erro de alocacao\n");
        //     *resp = 0;
        //     return NULL;
        // }
        // strcpy(novo->palavra, palavra_adc);
        // novo->local = (psc *)malloc(sizeof(psc));
        // novo->local->lugar = linha;
        // novo->local->prox = NULL;
        // novo->cor = RED;
        // novo->dir = NULL;
        // novo->esq = NULL;
        // *resp = 1;
        // return novo;
    }
    else if (strcmp(palavra_adc, H->palavra) == 0)
    {
        adicionar_lista_encadeada(H->local, palavra_adc, linha);
    }
    else if (strcmp(palavra_adc, H->palavra) < 0)
    {
        printf("Passa pra esquerda\n");
        H->esq = insere_no(H->esq, palavra_adc, resp, linha);
    }
    else
    {
        printf("Passa pra direita\n");
        H->dir = insere_no(H->dir, palavra_adc, resp, linha);
    }
    // COMPARAÇÕES
    if (cor(H->dir) == RED && cor(H->esq) == BLACK)
    {
        printf("Rotacao Esquerda\n");
        H = rotacionaEsquerda(H);
    }
    if (cor(H->esq) == RED && cor(H->esq->esq) == RED)
    {
        printf("Rotacao Direita\n");
        H = rotacionaDireita(H);
    }
    if (cor(H->esq) == RED && cor(H->dir) == RED)
    {
        printf("troca cor\n");
        H = trocar_cor(H);
    }
    return H;
}

NO *insere_arv(NO *raiz, char palavra_adc[], int *resp, int linha)
{
    raiz = insere_no(raiz, palavra_adc, resp, linha);
    // printf("voltou aki\n");
    if (raiz != NULL)
    {
        printf("Raiz Preta\n");
        raiz->cor = BLACK;
    }
    exibir_palavras(raiz);
    return raiz;
}

NO *ler_arquivo(NO *raiz, const char *nome_arquivo)
{
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

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        token = strtok(linha, " ");
        while (token != NULL)
        {
            int resp;
            // raiz = insere_no(raiz, token, &resp, linha_atual);
            printf("_______________________\n");
            token[strcspn(token, "\n")] = '\0';
            raiz = insere_arv(raiz, token, &resp, linha_atual);
            token = strtok(NULL, " ");
        }
        linha_atual++;
        // printf("leitura concluida\n");
    }
    return raiz;
    fclose(arquivo);
}


void exibir_lista_encadeada(psc *lista)
{
    if (lista != NULL)
    {
        printf("%d ", lista->lugar);
        exibir_lista_encadeada(lista->prox);
    }
}

void exibir_palavras(NO *raiz)
{
    if (raiz != NULL)
    {
        printf("Palavra: %s\n", raiz->palavra);
        printf("Linhas: ");
        exibir_lista_encadeada(raiz->local);
        printf("\n");
        if (raiz->cor == 1)
        {
            printf("cor RED\n");
        }
        else
        {
            printf("cor BLACK\n");
        }
        printf("\n\n");
        exibir_palavras(raiz->esq);
        exibir_palavras(raiz->dir);
    }
}