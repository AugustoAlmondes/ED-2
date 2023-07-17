typedef struct arvore Arv;
typedef struct Posicao posicao;
Arv *insere_no(Arv **raiz, char palavra[], Arv *pai, char sobe[],int linha);
Arv *cria_no(char palavra[], Arv *esquerda, Arv *centro,Arv *direita, int linha);
Arv *eh_folha(Arv *raiz);
Arv *adiciona_no(Arv *raiz,char palavra, Arv filho_dir);
void adicionar_palavra_lista(posicao **raiz,char palavra[],int linha);
Arv *quebra_no(Arv **no, char palavra[], char sobe[], Arv *filho, int linha);
