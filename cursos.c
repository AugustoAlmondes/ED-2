#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "curso.h"

// definição das structs
struct disciplina{
    int codDisciplina;
    char nome[20];
    int bloco; // deve ser menor ou IGUAL ao do curso
    int cargaHoraria;
    struct disciplina *esq,*dir;
};

struct curso{
    int cod;
    char nome[20];
    int blocos;
    int semanas;
    struct curso *esq,*dir;
    Disciplina *disc;//cada curso tem dua árvore de disciplinas
};

Curso *CriarArvore_Curso()
{
    return NULL;
}

Disciplina *CriarArvore_Dsc()
{
    return NULL;
}

//ADICIONAR UM NOVO CURSO
void AdicionarCurso(Curso **raiz_curs, int cod, char nome_curs[], int bloco_curs, int semanas)
{
    if (*raiz_curs == NULL) {
        Curso *novoCurso = (Curso*) malloc(sizeof(Curso));
        novoCurso->cod = cod;
        strcpy(novoCurso->nome, nome_curs);
        novoCurso->blocos = bloco_curs;
        novoCurso->semanas = semanas;
        novoCurso->esq = NULL;
        novoCurso->dir = NULL;
        novoCurso->disc = CriarArvore_Dsc();

        *raiz_curs = novoCurso;
    } else {
        if (cod < (*raiz_curs)->cod) {
            AdicionarCurso(&((*raiz_curs)->esq), cod, nome_curs, bloco_curs, semanas);
        } else {
            AdicionarCurso(&((*raiz_curs)->dir), cod, nome_curs, bloco_curs, semanas);
        }
    }
}

//EXIBIR TODAS AS DISCIPLINAS DADO O CODIGO DE UM CURSO
void ExibirDsc_por_Curso(Curso *arvore_curso, int codigo_curso)
{
    if( arvore_curso != NULL)
    {
        if (arvore_curso->cod == codigo_curso)
        {
            DadosDisciplinas(arvore_curso->disc);
        }
        else if(codigo_curso < arvore_curso->cod)
        {
            ExibirDsc_por_Curso(arvore_curso->esq,codigo_curso);
        }
        else
        {
            ExibirDsc_por_Curso(arvore_curso->dir,codigo_curso);
        }
    }
}

//EXIBIR DADOS DE TODOS OS CURSOS
void Exibir_Todos_Cursos(Curso *arvore)
{
    if (arvore != NULL) {
        Exibir_Todos_Cursos(arvore->esq);
        ExibirCursos(arvore);
        Exibir_Todos_Cursos(arvore->dir);
    }
}

//EXIBIR DADOS DE UM CURSO
void ExibirCursos(Curso *arvore)
{       
        printf("-----------------------------\n");
        printf("Codigo do Curso: %d\n", arvore->cod);
        printf("Nome do Curso: %s\n", arvore->nome);
        printf("Numero de Blocos: %d\n", arvore->blocos);
        printf("Numero de Semanas: %d\n", arvore->semanas);
        printf("-----------------------------\n");
}

//EXIBIR DADOS DE UMA UNICA DISCIPLINA
void ExibirDados_Dsc(Disciplina *arvore)
{
    printf("-----------------------------\n");
    printf("Codigo da Disciplina: %d\n", arvore->codDisciplina);
    printf("Nome da Disciplina: %s\n", arvore->nome);
    printf("Bloco: %d\n", arvore->bloco);
    printf("Carga Horario: %d\n", arvore->cargaHoraria);
    printf("-----------------------------\n");
}

//EXIBIR DADOS DE TODAS AS DISCIPLINA
void DadosDisciplinas(Disciplina *arvore)
{
    if (arvore != NULL) {
        DadosDisciplinas(arvore->esq);
        ExibirDados_Dsc(arvore);
        DadosDisciplinas(arvore->dir);
    }
}
//EXIBIR DADOS DE UM UNICO CURSO
void ExibirDados_Curso(Curso *arvore,int codigo)
{
    if(arvore != NULL)
    {
        if(arvore->cod == codigo)
        {
            ExibirCursos(arvore);
        }
        else if(codigo > arvore->cod)
        {
            ExibirDados_Curso(arvore->dir,codigo);
        }
        else if(codigo < arvore->cod)
        {
            ExibirDados_Curso(arvore->esq,codigo);
        }
    }
}
//EXIBIR CURSO DE ACORDO COM O BLOCO
void ExibirCursoBloco(Curso *arvore,int qtd)
{
    if (arvore != NULL)
    {
        if (arvore->blocos == qtd)
        {
            printf("Nome do Curso: %s\n", arvore->nome);
        }
        ExibirCursoBloco(arvore->esq,qtd);
        ExibirCursoBloco(arvore->dir,qtd);
    }
}

//BUSCA E ADICIONA A DICIPLINA PELO CODIGO DO CURSO
void AdicionarDsc_em_curso(Curso **arvoreCursos,int codigo, int codDisciplina, char nome_dsc[], int bloco_dsc, int cargaHoraria)
{
    if(*arvoreCursos != NULL)
    {
        if((*arvoreCursos)->cod == codigo)
        {
            AdicionarDisciplinaArvore(&(*arvoreCursos)->disc,codDisciplina,nome_dsc,bloco_dsc,cargaHoraria);
        }
        else if(codigo < (*arvoreCursos)->cod)
        {
            AdicionarDsc_em_curso(&(*arvoreCursos)->esq,codigo,codDisciplina,nome_dsc,bloco_dsc,cargaHoraria);
        }
        else
        {
            AdicionarDsc_em_curso(&(*arvoreCursos)->dir,codigo,codDisciplina,nome_dsc,bloco_dsc,cargaHoraria);;
        }
    }
}

//OS DADOS DA DISCIPLINA É ADICIONADO
void AdicionarDisciplinaArvore(Disciplina **raiz_dsc, int codDisciplina, char nome_dsc[], int bloco_dsc, int cargaHoraria)
{
    if (*raiz_dsc == NULL) {
        Disciplina *novaDisciplina = (Disciplina*) malloc(sizeof(Disciplina));
        novaDisciplina->codDisciplina = codDisciplina;
        strcpy(novaDisciplina->nome, nome_dsc);
        novaDisciplina->bloco = bloco_dsc;
        novaDisciplina->cargaHoraria = cargaHoraria;
        novaDisciplina->esq = NULL;
        novaDisciplina->dir = NULL;

        *raiz_dsc = novaDisciplina;
    
    } else {
        if (codDisciplina < (*raiz_dsc)->codDisciplina) {
            AdicionarDisciplinaArvore(&((*raiz_dsc)->esq), codDisciplina, nome_dsc, bloco_dsc, cargaHoraria);
        } else {
            AdicionarDisciplinaArvore(&((*raiz_dsc)->dir), codDisciplina, nome_dsc, bloco_dsc, cargaHoraria);
        }
    }
}

//IMPRIMIR DADOS DE UMA UNICA DISCIPLINA
void Imprimir_dsc(Curso *arvoreCursos, int codigo, int codigo_dsc)
{
    if(arvoreCursos != NULL)
    {
        if (arvoreCursos->cod == codigo)
        {
            ExibirDsc_por_Codigo(arvoreCursos->disc,codigo_dsc);
        }
        else if(codigo < arvoreCursos->cod)
        {
            Imprimir_dsc(arvoreCursos->esq,codigo,codigo_dsc);
        }
        else
        {
            Imprimir_dsc(arvoreCursos->dir,codigo,codigo_dsc);
        }
    }
}

//
void ExibirDsc_por_Codigo(Disciplina *raiz,int codigo_dsc)
{
    if(raiz != NULL)
    {
        if(raiz->codDisciplina == codigo_dsc)
        {
            ExibirDados_Dsc(raiz);
        }
        else if(codigo_dsc < raiz->codDisciplina)
        {
            ExibirDsc_por_Codigo(raiz->esq,codigo_dsc);
        }
        else
        {
            ExibirDsc_por_Codigo(raiz->dir,codigo_dsc);
        }
    }
}

//FUNÇÃO PARA PROCURAR O CURSO PELO CODIGO
void BuscarCurso_para_ExibirDsc_por_Bloco(Curso *raiz,int codigo_curso, int bloco_curso)
{
    if(raiz != NULL)
    {
        if (raiz->cod == codigo_curso)
        {
            ExibirDsc_por_BlocoAux(raiz->disc,bloco_curso);
        }
        else if(codigo_curso < raiz->cod)
        {
            BuscarCurso_para_ExibirDsc_por_Bloco(raiz->esq,codigo_curso,bloco_curso);
        }
        else
        {
            BuscarCurso_para_ExibirDsc_por_Bloco(raiz->dir,codigo_curso,bloco_curso);
        }
        
    }
}

//FUNÇÃO AUXILIAR PARA PROCURAR AS DISCIPLINAS PELO BLOCO
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

void BuscarCurso_para_ExibirDsc_por_CH(Curso *raiz,int codigo_curso, int Carga_horaria)
{
    if(raiz != NULL)
    {
        if (raiz->cod == codigo_curso)
        {
            ExibirDsc_por_CH(raiz->disc,Carga_horaria);
        }
        else if(codigo_curso < raiz->cod)
        {
            BuscarCurso_para_ExibirDsc_por_CH(raiz->esq,codigo_curso,Carga_horaria);
        }
        else
        {
            BuscarCurso_para_ExibirDsc_por_CH(raiz->dir,codigo_curso,Carga_horaria);
        }

    }
}

void ExibirDsc_por_CH(Disciplina *raiz, int Carga_horaria)
{
    if(raiz != NULL)
    {
        if (raiz->cargaHoraria == Carga_horaria)
        {
            ExibirDados_Dsc(raiz);
        }
        ExibirDsc_por_CH(raiz->esq,Carga_horaria);
        ExibirDsc_por_CH(raiz->dir,Carga_horaria);
    }
}

void BuscarCurso_para_RemoverDsc(Curso **raiz, int codigo,int codigo_dsc)
{
    if (*raiz != NULL)
    {
        if((*raiz)->cod == codigo)
        {
            RemoverDsc(&(*raiz)->disc,codigo_dsc);
        }
        else if((*raiz)->cod > codigo)
        {
            BuscarCurso_para_RemoverDsc(&(*raiz)->esq,codigo,codigo_dsc);
        }
        else
        {
            BuscarCurso_para_RemoverDsc(&(*raiz)->dir,codigo,codigo_dsc);
        }
    }
}

void RemoverDsc(Disciplina **raiz,int codigo)
{
    if (*raiz != NULL)
    {
        Disciplina *aux;
        if((*raiz)->codDisciplina == codigo)
        {
            if((*raiz)->esq == NULL && (*raiz)->dir == NULL)
            {
                free(*raiz);
                (*raiz) = NULL;
            }
            else if((*raiz)->esq == NULL || (*raiz)->dir == NULL)
            {
                Disciplina *endFilho;
                if((*raiz)->esq != NULL)
                {
                    aux = *raiz;
                    endFilho = (*raiz)->esq;
                    *raiz = endFilho;
                    free(aux);
                    aux = NULL;
                }
                else
                {
                    aux = *raiz;
                    endFilho = (*raiz)->dir;
                    *raiz = endFilho;
                    free(aux);
                    aux = NULL;
                }
            }
            else
            {
                Disciplina *filho;
                aux = *raiz;
                filho = (*raiz)->esq;
                buscarfolha(&((*raiz)->esq), (*raiz)->dir);
                *raiz = filho;
                free(aux);      
                aux = NULL;          
            }
        }
        else if (codigo < (*raiz)->codDisciplina)
        {
            RemoverDsc(&(*raiz)->esq,codigo);
        }
        else
        {
            RemoverDsc(&(*raiz)->dir,codigo);
        }
    }
}

void buscarfolha(Disciplina **ultimo, Disciplina *filho)
{
    if(*ultimo)
    {
        buscarfolha(&((*ultimo)->dir), filho);
    }
    else
    {
        *ultimo = filho;
    }
}