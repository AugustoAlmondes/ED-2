#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cursosAVL.h"

// definição das structs
struct disciplina
{
    int codDisciplina;
    char nome[20];
    int bloco; // deve ser menor ou IGUAL ao do curso
    int cargaHoraria;
    int altura;
    struct disciplina *esq, *dir;
};

struct curso
{
    int cod;
    char nome[20];
    int blocos;
    int semanas;
    int altura;
    struct curso *esq, *dir;
    Disciplina *disc; // cada curso tem dua árvore de disciplinas
};

Curso *CriarArvore_Curso()
{
    return NULL;
}

//----------------------------------------------------------------------------------------------------
// MEDIA ALTURA
int alturaNo_crs(Curso *no)
{
    if (no == NULL)
        return -1;
    return no->altura;
}

// FUNÇÃO PARA RETORNAR O MAIOR VALOR
int maximo(int esq, int dir)
{
    return (esq > dir) ? esq : dir;
}

Curso *balancearCurso(Curso *raiz)
{
    int fatorBalanceamento = alturaNo_crs(raiz->esq) - alturaNo_crs(raiz->dir);

    if (fatorBalanceamento == 2)
    {
        int fatorEsq = alturaNo_crs(raiz->esq->esq) - alturaNo_crs(raiz->esq->dir);
        if (fatorEsq < 0)
        {
            raiz->esq = rotacaoEsquerda_crs(raiz->esq);
        }
        raiz = rotacaoDireita_crs(raiz);
    }
    else if (fatorBalanceamento == -2)
    {
        int fatorDir =  alturaNo_crs(raiz->dir->esq) - alturaNo_crs(raiz->dir->dir); // mudei aqui, o lado direito tava indo primeiro, por causa disso o fator de balanceamento tava dando errado
        if (fatorDir > 0)
        {
            raiz->dir = rotacaoDireita_crs(raiz->dir);
        }
        raiz = rotacaoEsquerda_crs(raiz);
    }

    return raiz;
}

// ROTACIONAR DIREITA
Curso *rotacaoDireita_crs(Curso *raiz)
{
    Curso *aux = raiz->esq;
    raiz->esq = aux->dir;
    aux->dir = raiz;
    raiz = aux;                        

    aux->dir->altura = maximo(alturaNo_crs(aux->esq), alturaNo_crs(aux->dir)) + 1;
    raiz->altura = maximo(alturaNo_crs(raiz->esq), alturaNo_crs(raiz->dir)) + 1;
    return raiz;
}

// ROTACIONAR ESQUERDA
Curso *rotacaoEsquerda_crs(Curso *raiz)
{
    Curso *aux = raiz->dir;
    raiz->dir = aux->esq;
    aux->esq = raiz;
    raiz = aux;

    aux->esq->altura = maximo(alturaNo_crs(aux->dir), alturaNo_crs(aux->dir)) + 1;
    raiz->altura = maximo(alturaNo_crs(raiz->dir), alturaNo_crs(raiz->dir)) + 1;
    return raiz;
}

// ADICIONAR UM NOVO CURSO
void AdicionarCurso(Curso **raiz_curs, int cod, char nome_curs[], int bloco_curs, int semanas)
{
    if (*raiz_curs == NULL)
    {
        Curso *novoCurso = (Curso *)malloc(sizeof(Curso));
        novoCurso->cod = cod;
        strcpy(novoCurso->nome, nome_curs);
        novoCurso->blocos = bloco_curs;
        novoCurso->semanas = semanas;
        novoCurso->esq = NULL;
        novoCurso->dir = NULL;
        novoCurso->disc = NULL;

        *raiz_curs = novoCurso;
    }
    else
    {
        if (cod < (*raiz_curs)->cod)
        {
            AdicionarCurso(&((*raiz_curs)->esq), cod, nome_curs, bloco_curs, semanas);
        }
        else if (cod > (*raiz_curs)->cod) // mudei aqui tava entarndo codigo repetido
        {
            AdicionarCurso(&((*raiz_curs)->dir), cod, nome_curs, bloco_curs, semanas);
        }

        // Balanceamento da árvore AVL após a inserção
    }
        *raiz_curs = balancearCurso(*raiz_curs);
        (*raiz_curs)->altura = maximo(alturaNo_crs((*raiz_curs)->esq), alturaNo_crs((*raiz_curs)->dir)) + 1;
}
//----------------------------------------------------------------------------------------------------
// EXIBIR DADOS DE UM CURSO
void ExibirCursos(Curso *arvore)
{
    printf("-----------------------------\n");
    printf("Codigo do Curso: %d\n", arvore->cod);
    printf("Nome do Curso: %s\n", arvore->nome);
    printf("Numero de Blocos: %d\n", arvore->blocos);
    printf("Numero de Semanas: %d\n", arvore->semanas);
    printf("-----------------------------\n");
}

// EXIBIR DADOS DE UMA UNICA DISCIPLINA
void ExibirDados_Dsc(Disciplina *arvore)
{
    printf("-----------------------------\n");
    printf("Codigo da Disciplina: %d\n", arvore->codDisciplina);
    printf("Nome da Disciplina: %s\n", arvore->nome);
    printf("Bloco: %d\n", arvore->bloco);
    printf("Carga Horario: %d\n", arvore->cargaHoraria);
    printf("-----------------------------\n");
}

// EXIBIR TODAS AS DISCIPLINAS DADO O CODIGO DE UM CURSO
void ExibirDsc_por_Curso(Curso *arvore_curso, int codigo_curso)
{
    if (arvore_curso != NULL)
    {
        if (arvore_curso->cod == codigo_curso)
        {
            DadosDisciplinas(arvore_curso->disc);
        }
        else if (codigo_curso < arvore_curso->cod)
        {
            ExibirDsc_por_Curso(arvore_curso->esq, codigo_curso);
        }
        else
        {
            ExibirDsc_por_Curso(arvore_curso->dir, codigo_curso);
        }
    }
}

// EXIBIR DADOS DE TODOS OS CURSOS
void Exibir_Todos_Cursos(Curso *arvore)
{
    if (arvore != NULL)
    {
        Exibir_Todos_Cursos(arvore->esq);
        ExibirCursos(arvore);
        Exibir_Todos_Cursos(arvore->dir);
    }
}

// EXIBIR DADOS DE TODAS AS DISCIPLINA
void DadosDisciplinas(Disciplina *arvore)
{
    if (arvore != NULL)
    {
        DadosDisciplinas(arvore->esq);
        ExibirDados_Dsc(arvore);
        DadosDisciplinas(arvore->dir);
    }
}
// EXIBIR DADOS DE UM UNICO CURSO
void ExibirDados_Curso(Curso *arvore, int codigo)
{
    if (arvore != NULL)
    {
        if (arvore->cod == codigo)
        {
            ExibirCursos(arvore);
        }
        else if (codigo > arvore->cod)
        {
            ExibirDados_Curso(arvore->dir, codigo);
        }
        else if (codigo < arvore->cod)
        {
            ExibirDados_Curso(arvore->esq, codigo);
        }
    }
}
// EXIBIR CURSO DE ACORDO COM O BLOCO
void ExibirCursoBloco(Curso *arvore, int qtd)
{
    if (arvore != NULL)
    {
        if (arvore->blocos == qtd)
        {
            printf("Nome do Curso: %s\n", arvore->nome);
        }
        ExibirCursoBloco(arvore->esq, qtd);
        ExibirCursoBloco(arvore->dir, qtd);
    }
}

// BUSCA E ADICIONA A DICIPLINA PELO CODIGO DO CURSO
void AdicionarDsc_em_curso(Curso **arvoreCursos, int codigo, int codDisciplina, char nome_dsc[], int bloco_dsc, int cargaHoraria)
{
    if (*arvoreCursos != NULL)
    {
        if ((*arvoreCursos)->cod == codigo)
        {
            AdicionarDisciplinaArvore(&(*arvoreCursos)->disc, codDisciplina, nome_dsc, bloco_dsc, cargaHoraria);
        }
        else if (codigo < (*arvoreCursos)->cod)
        {
            AdicionarDsc_em_curso(&(*arvoreCursos)->esq, codigo, codDisciplina, nome_dsc, bloco_dsc, cargaHoraria);
        }
        else
        {
            AdicionarDsc_em_curso(&(*arvoreCursos)->dir, codigo, codDisciplina, nome_dsc, bloco_dsc, cargaHoraria);
        }
    }
}
int alturaNo_dsc(Disciplina *no)
{
    if (no == NULL)
        return 0;
    return no->altura;
}

Disciplina *rotacaoEsquerda_dsc(Disciplina *x)
{
    Disciplina *y = x->dir;
    Disciplina *T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->altura = maximo(alturaNo_dsc(x->esq), alturaNo_dsc(x->dir)) + 1;
    y->altura = maximo(alturaNo_dsc(y->esq), alturaNo_dsc(y->dir)) + 1;

    return y;
}

Disciplina *rotacaoDireita_dsc(Disciplina *y)
{
    Disciplina *x = y->esq;
    Disciplina *T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->altura = maximo(alturaNo_dsc(y->esq), alturaNo_dsc(y->dir)) + 1;
    x->altura = maximo(alturaNo_dsc(x->esq), alturaNo_dsc(x->dir)) + 1;

    return x;
}

Disciplina *balancearDisciplina(Disciplina *raiz)
{
    int fatorBalanceamento = alturaNo_dsc(raiz->esq) - alturaNo_dsc(raiz->dir);

    if (fatorBalanceamento == 2)
    {
        int fatorEsq = alturaNo_dsc(raiz->esq->esq) - alturaNo_dsc(raiz->esq->dir);
        if (fatorEsq < 0)
        {
            raiz->esq = rotacaoEsquerda_dsc(raiz->esq);
        }
        raiz = rotacaoDireita_dsc(raiz);
    }
    else if (fatorBalanceamento == -2)
    {
        int fatorDir = alturaNo_dsc(raiz->dir->dir) - alturaNo_dsc(raiz->dir->esq);
        if (fatorDir > 0)
        {
            raiz->dir = rotacaoDireita_dsc(raiz->dir);
        }
        raiz = rotacaoEsquerda_dsc(raiz);
    }

    return raiz;
}

// OS DADOS DA DISCIPLINA É ADICIONADO
void AdicionarDisciplinaArvore(Disciplina **raiz_dsc, int codDisciplina, char nome_dsc[], int bloco_dsc, int cargaHoraria)
{
    if (*raiz_dsc == NULL)
    {
        Disciplina *novaDisciplina = (Disciplina *)malloc(sizeof(Disciplina));
        novaDisciplina->codDisciplina = codDisciplina;
        strcpy(novaDisciplina->nome, nome_dsc);
        novaDisciplina->bloco = bloco_dsc;
        novaDisciplina->cargaHoraria = cargaHoraria;
        novaDisciplina->esq = NULL;
        novaDisciplina->dir = NULL;

        *raiz_dsc = novaDisciplina;
    }
    else
    {
        if (codDisciplina < (*raiz_dsc)->codDisciplina)
        {
            AdicionarDisciplinaArvore(&((*raiz_dsc)->esq), codDisciplina, nome_dsc, bloco_dsc, cargaHoraria);
        }
        else if (codDisciplina > (*raiz_dsc)->codDisciplina)
        {
            AdicionarDisciplinaArvore(&((*raiz_dsc)->dir), codDisciplina, nome_dsc, bloco_dsc, cargaHoraria);
        }
        (*raiz_dsc)->altura = 1 + maximo(alturaNo_dsc((*raiz_dsc)->esq), alturaNo_dsc((*raiz_dsc)->dir));

        *raiz_dsc = balancearDisciplina(*raiz_dsc);
    }
}

//----------------------------------------------------------------------------------------------------

// IMPRIMIR DADOS DE UMA UNICA DISCIPLINA
void Imprimir_dsc(Curso *arvoreCursos, int codigo, int codigo_dsc)
{
    if (arvoreCursos != NULL)
    {
        if (arvoreCursos->cod == codigo)
        {
            ExibirDsc_por_Codigo(arvoreCursos->disc, codigo_dsc);
        }
        else if (codigo < arvoreCursos->cod)
        {
            Imprimir_dsc(arvoreCursos->esq, codigo, codigo_dsc);
        }
        else
        {
            Imprimir_dsc(arvoreCursos->dir, codigo, codigo_dsc);
        }
    }
}

//
void ExibirDsc_por_Codigo(Disciplina *raiz, int codigo_dsc)
{
    if (raiz != NULL)
    {
        if (raiz->codDisciplina == codigo_dsc)
        {
            ExibirDados_Dsc(raiz);
        }
        else if (codigo_dsc < raiz->codDisciplina)
        {
            ExibirDsc_por_Codigo(raiz->esq, codigo_dsc);
        }
        else
        {
            ExibirDsc_por_Codigo(raiz->dir, codigo_dsc);
        }
    }
}

// FUNÇÃO PARA PROCURAR O CURSO PELO CODIGO
void BuscarCurso_para_ExibirDsc_por_Bloco(Curso *raiz, int codigo_curso, int bloco_curso)
{
    if (raiz != NULL)
    {
        if (raiz->cod == codigo_curso)
        {
            ExibirDsc_por_BlocoAux(raiz->disc, bloco_curso);
        }
        else if (codigo_curso < raiz->cod)
        {
            BuscarCurso_para_ExibirDsc_por_Bloco(raiz->esq, codigo_curso, bloco_curso);
        }
        else
        {
            BuscarCurso_para_ExibirDsc_por_Bloco(raiz->dir, codigo_curso, bloco_curso);
        }
    }
}

// FUNÇÃO AUXILIAR PARA PROCURAR AS DISCIPLINAS PELO BLOCO
void ExibirDsc_por_BlocoAux(Disciplina *raiz, int bloco_curso)
{
    if (raiz != NULL)
    {

        ExibirDsc_por_BlocoAux(raiz->esq, bloco_curso);
        if (raiz->bloco == bloco_curso)
        {
            ExibirDados_Dsc(raiz);
        }
        ExibirDsc_por_BlocoAux(raiz->dir, bloco_curso);
    }
}

void BuscarCurso_para_ExibirDsc_por_CH(Curso *raiz, int codigo_curso, int Carga_horaria)
{
    if (raiz != NULL)
    {
        if (raiz->cod == codigo_curso)
        {
            ExibirDsc_por_CH(raiz->disc, Carga_horaria);
        }
        else if (codigo_curso < raiz->cod)
        {
            BuscarCurso_para_ExibirDsc_por_CH(raiz->esq, codigo_curso, Carga_horaria);
        }
        else
        {
            BuscarCurso_para_ExibirDsc_por_CH(raiz->dir, codigo_curso, Carga_horaria);
        }
    }
}

void ExibirDsc_por_CH(Disciplina *raiz, int Carga_horaria)
{
    if (raiz != NULL)
    {
        if (raiz->cargaHoraria == Carga_horaria)
        {
            ExibirDados_Dsc(raiz);
        }
        ExibirDsc_por_CH(raiz->esq, Carga_horaria);
        ExibirDsc_por_CH(raiz->dir, Carga_horaria);
    }
}

void BuscarCurso_para_RemoverDsc(Curso **raiz, int codigo, int codigo_dsc)
{
    if (*raiz != NULL)
    {
        if ((*raiz)->cod == codigo)
        {
            (*raiz)->disc = RemoverDsc((*raiz)->disc, codigo_dsc);
        }
        else if ((*raiz)->cod > codigo)
        {
            BuscarCurso_para_RemoverDsc(&(*raiz)->esq, codigo, codigo_dsc);
        }
        else
        {
            BuscarCurso_para_RemoverDsc(&(*raiz)->dir, codigo, codigo_dsc);
        }
    }
}

void buscarfolha_Dsc(Disciplina **ultimo, Disciplina *filho)
{
    if (*ultimo)
    {
        buscarfolha_Dsc(&(*ultimo)->dir, filho);
    }
    else
    {
        *ultimo = filho;
    }
}

void buscarfolha_Curso(Curso **ultimo, Curso *filho)
{
    if (*ultimo)
    {
        buscarfolha_Curso(&(*ultimo)->dir, filho);
    }
    else
    {
        *ultimo = filho;
    }
}

Disciplina *RemoverDsc(Disciplina *raiz, int codigo)
{
    if (raiz != NULL)
    {
        if ((raiz)->codDisciplina == codigo)
        {
            Disciplina *aux;
            if ((raiz)->esq == NULL && (raiz)->dir == NULL)
            {
                free(raiz);
                (raiz) = NULL;
            }
            else if ((raiz)->esq == NULL || (raiz)->dir == NULL)
            {
                Disciplina *endFilho;
                if ((raiz)->esq != NULL)
                {
                    aux = raiz;
                    endFilho = (raiz)->esq;
                    raiz = endFilho;
                    free(aux);
                    aux = NULL;
                }
                else
                {
                    aux = raiz;
                    endFilho = (raiz)->dir;
                    raiz = endFilho;
                    free(aux);
                    aux = NULL;
                }
            }
            else
            {
                Disciplina *filho;
                aux = raiz;
                filho = (raiz)->esq;
                buscarfolha_Dsc(&((raiz)->esq),(raiz)->dir);
                raiz = filho;
                free(aux);
            }
        }
        else if (codigo < (raiz)->codDisciplina)
        {
            raiz->esq = RemoverDsc((raiz)->esq, codigo);
        }
        else
        {
            raiz->dir = RemoverDsc((raiz)->dir, codigo);
        }

        if(raiz != NULL)
        {
            (raiz)->altura = 1 + maximo(alturaNo_dsc((raiz)->esq),alturaNo_dsc((raiz)->dir));
            raiz = balancearDisciplina(raiz);
        }
        return raiz;
    }
}

Curso *RemoverCurso(Curso *raiz, int codigo)
{
    if (raiz != NULL)
    {
        if (codigo == raiz->cod)
        {
            if (raiz->disc == NULL)
            {
                Curso *aux;
                if (raiz->esq == NULL && raiz->dir == NULL)
                {
                    free(aux);
                    raiz = NULL;
                }
                else if (raiz->dir == NULL || raiz->esq == NULL)
                {
                    Curso *endfilho;
                    if (raiz->esq != NULL)
                    {
                        aux = raiz;
                        endfilho = raiz->esq;
                        raiz = endfilho;
                        free(aux);
                        aux = NULL;
                    }
                    else
                    {
                        aux = raiz;
                        endfilho = raiz->dir;
                        raiz = endfilho;
                        free(aux);
                        aux = NULL;
                    }
                }
                else
                {
                    Curso *filho;
                    aux = raiz;
                    filho = raiz->esq;
                    buscarfolha_Curso(&(raiz->esq),raiz->dir);
                    raiz = filho;
                    free(aux);
                }
            }
        }
        else if (codigo < raiz->cod)
        {
            raiz->esq = RemoverCurso(raiz->esq, codigo);
        }
        else
        {
            raiz->dir = RemoverCurso(raiz->dir, codigo);
        }

        if (raiz != NULL)
        {
            raiz->altura = 1 + maximo(alturaNo_crs(raiz->esq), alturaNo_crs(raiz->dir));
            raiz = balancearCurso(raiz);
        }

        return raiz;
    }
}

void verificar_semelhanca_dsc(Curso *raiz, int codigo_crs, int codigo, int cargahorario, int blocos, int *resultado)
{
    if (raiz != NULL)
    {
        if (codigo_crs == raiz->cod)
        {
            if (raiz->blocos <= blocos)
            {
                // RETORNAR 1 CASO O NUMERO DE BLOCOS EXCEDA
                *resultado = 1;
            }
            else if ((cargahorario % raiz->semanas) != 0)
            {
                // RETORNA 2 CASO AS CARGAHORARIA SEJA INCOMPATIVEL
                *resultado = 2;
            }
        }
        else if (codigo_crs < raiz->cod)
        {
            verificar_semelhanca_dsc(raiz->esq, codigo_crs, codigo, cargahorario, blocos, resultado);
        }
        else
        {
            verificar_semelhanca_dsc(raiz->dir, codigo_crs, codigo, cargahorario, blocos, resultado);
        }
    }
}

int verificar_semelhanca(Curso *raiz, char nome_crs[], int codigo)
{
    if (raiz != NULL)
    {
        if (codigo == raiz->cod)
        {
            // RETORNA 1 CASO O CODIGO SEJA IGUAL
            return 1;
        }
        if ((compare_strings(raiz->nome, nome_crs) == 1))
        {
            // RETURN 2 CASO O NOME SEJA IGUAL
            return 2;
        }
        else if (codigo < raiz->cod)
        {
            verificar_semelhanca(raiz->esq, nome_crs, codigo);
        }
        else
        {
            verificar_semelhanca(raiz->dir, nome_crs, codigo);
        }
    }
}

int compare_strings(const char *str1, const char *str2)
{
    int i = 0;

    while (str1[i] == str2[i])
    {
        if (str1[i] == '\0')
            return 1;
        i++;
    }

    return 0;
}