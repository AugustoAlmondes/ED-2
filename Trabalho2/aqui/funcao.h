typedef struct Posicao psc;
typedef struct no NO;

int cor(NO *H);
NO *trocar_cor(NO *H);
NO *rotacionaEsquerda(NO *raiz);
NO *rotacionaDireita(NO *raiz);
psc *adicionar_lista_encadeada(psc *no, char palavra_adc[], int linha);
NO *insere_no(NO *H, char palavra_adc[], int *resp, int linha);
void exibir_lista_encadeada(psc *lista);
void exibir_palavras(NO *raiz);
NO *insere_arv(NO *raiz, char palavra_adc[], int *resp, int linha);
NO *ler_arquivo(NO *raiz, const char *nome_arquivo);