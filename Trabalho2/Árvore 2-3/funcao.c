#include <stdio.h>
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
    posicao psc_palavra_1, psc_palavra_2;
    struct arvore *filho_esq;
    struct arvore *filho_crt;
    struct arvore *filho_dir;
    int num_chaves;
};

Arv *quebra_no(Arv **no, char palavra[], char sobe[], Arv *filho, int linha)
{
    Arv *novo;
    if (strcmp(palavra, (*no)->palavra_dois) == 1)
    {
        strcpy(sobe, (*no)->palavra_dois);
        novo = cria_no(palavra, (*no)->filho_dir, filho, NULL, linha);
        (*no)->num_chaves = 1;
    }
    else if (strcmp(palavra, (*no)->palavra_um) == 1)
    {
        strcpy(sobe, palavra);
        novo = cria_no((*no)->palavra_dois, filho, (*no)->filho_dir, NULL, linha);
        (*no)->num_chaves = 1;
    }
    else
    {
        strcpy(sobe, (*no)->palavra_um);
        novo = cria_no((*no)->palavra_dois, filho, (*no)->filho_dir, NULL, linha);
        (*no)->num_chaves = 1;
        strcpy((*no)->palavra_um, palavra);
    }
    (*no)->num_chaves = 1;
    return novo;
}

void adicionar_palavra_lista(posicao **raiz, char palavra[], int linha)
{
    if ((*raiz) == NULL)
    {
        *raiz = (posicao *)malloc(sizeof(posicao));
        if ((*raiz) != NULL)
        {
            (*raiz)->lugar = linha;
            (*raiz)->prox_plavra = NULL;
        }
    }
}

Arv *adiciona_no(Arv *raiz, char palavra, Arv filho_dir)
{
    if (raiz == NULL)
    {
        if (strcmp(raiz->palavra_um, palavra) == -1)
        {
            strcpy(raiz->palavra_dois, palavra);
            raiz->num_chaves = 2;
        }
        else
        {
            char aux[20];
            strcpy(aux, raiz->palavra_um);
            strcpy(raiz->palavra_um, palavra);
            strcpy(raiz->palavra_dois, aux);
            raiz->num_chaves = 2;
        }
    }
    return raiz;
}

Arv *eh_folha(Arv *raiz)
{
    if (raiz != NULL)
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
    strcpy(novo->palavra_um, palavra);
    novo->psc_palavra_1.lugar = linha;
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
    maior_no = NULL;
    if (*raiz == NULL)
    {
        cria_no(palavra, NULL, NULL, NULL, linha);
    }
    else if (strcmp((*raiz)->palavra_um, palavra) == 0)
    {
        adicionar_palavra_lista((&(*raiz)->psc_palavra_1), palavra, linha);
    }
    else if (strcmp((*raiz)->palavra_dois, palavra) == 0)
    {
        adicionar_palavra_lista((&(*raiz)->psc_palavra_2), palavra, linha);
    }
    else
    {
        if (eh_folha(*raiz))
        {
            if (((*raiz)->num_chaves == 1))
            {
                raiz = adiciona_no(&raiz, palavra, *maior_no);
            }
            else
            {
                maior_no = quebra_no(raiz, palavra, sobe, NULL, linha);
                if (pai == NULL)
                {
                    *raiz = cria_no(sobe, *raiz, maior_no, NULL, linha);
                    maior_no = NULL;
                }
            }
        }
        else if (strcmp(palavra, (*raiz)->palavra_um) == -1)
        {
            maior_no = insere_no(&((*raiz)->filho_esq), palavra, *raiz, sobe, linha);
        }
        else if ((*raiz)->num_chaves == 1 || (*raiz)->num_chaves == 2 && (strcmp(palavra, (*raiz)->palavra_dois) == -1))
        {
            maior_no = insere_no((&(*raiz)->filho_crt), palavra, raiz, sobe, linha);
        }
        else
        {
            maior_no = insere_no((&(*raiz)->filho_dir), palavra, *raiz, sobe, linha);
        }
        if ((*raiz)->num_chaves == 1)
        {
            raiz = adiciona_no(&raiz, sobe, *maior_no);
            maior_no = NULL;
        }
        else
        {
            int sobe_novo;
            maior_no = quebra_no(raiz, sobe, &sobe_novo, maior_no, linha);
            if (pai == NULL)
            {
                *raiz = cria_no(sobe_novo, *raiz, maior_no, NULL, linha);
                maior_no = NULL;
            }
        }
    }
    return maior_no;
}