#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcao.h"

int main()
{
    NO *raiz = NULL;
    raiz = ler_arquivo(raiz, "texto.txt");
    printf("\n");
    exibir_palavras(raiz);
}