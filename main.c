#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "curso.h"

int main()
{

    int codigo;

    Curso *arvoreCursos = CriarArvore_Curso();
    Disciplina *arvoreDisciplinas = CriarArvore_Dsc();

    clock_t inicio, fim;

    double tempo;

    inicio = clock();

    //FUNÇÃO PARA ADICIONAR NÓ NA ÁRVORE DE CURSOS
    arvoreCursos = adcCurso();

    fim = clock();

    tempo = ((double)(fim - inicio)/CLOCKS_PER_SEC) * 1000;

    printf("Tempo para preencher Arvore: %.5lf milissegundos\n", tempo);
    printf("------------------------------------------------\n");

    // primeira questao - C - 1
    printf("----- Todos os Cursos -----\n");
    Exibir_Todos_Cursos(arvoreCursos);

    // primeira questao - C - 2

    inicio = clock();
    printf("----- Dados de um Curso -----\n");
    printf("Digite o codigo do curso que deseja ver os dados: ");
    scanf(" %d", &codigo);
    ExibirDados_Curso(arvoreCursos, codigo);
    fim = clock();

    tempo = ((double)(fim - inicio)/CLOCKS_PER_SEC) * 1000;
    printf("Tempo para exibir dados de um curso: %.5lf milissegundos\n", tempo);
    printf("------------------------------------------------\n");

    // primeira questao - c - 3
    printf("----- Exibir Cursos por Blocos -----\n");
    int quantidade;
    printf("Digite a quantidade de blocos que deseja procurar: ");
    scanf(" %d", &quantidade);
    ExibirCursoBloco(arvoreCursos, quantidade);

    arvoreCursos = adcDsc();

    // primeira questao - C - 4
    printf("----- Disciplinas do Curso -----\n");
    printf("Digite o codigo do curso para ver as disciplinas: ");
    scanf(" %d", &codigo);
    ExibirDsc_por_Curso(arvoreCursos, codigo);

    // primeira questao - C - 5
    printf("---- Dados de uma unica Disciplina -----\n");
    int codigo_dsc;
    printf("Digite o codigo do Curso: ");
    scanf(" %d", &codigo);
    printf("Digite o codigo da Disciplina: ");
    scanf(" %d", &codigo_dsc);
    Imprimir_dsc(arvoreCursos, codigo, codigo_dsc);

    // primeira questao - C - 6
    printf("----- Dados das Disciplinas de acordo com um bloco -----\n ");
    int bloco;
    printf("Digite codigo do bloco: ");
    scanf(" %d", &bloco);
    printf("Digite codigo do curso: ");
    scanf(" %d", &codigo);

    BuscarCurso_para_ExibirDsc_por_Bloco(arvoreCursos, codigo, bloco);

    // primeira questao - C - 7
    printf("----- Dados das Disciplinas por Carga horaria -----\n");
    int cargahr;
    printf("Digite a Carga Horaia: ");
    scanf(" %d", &cargahr);
    printf("Digite o Codigo do Curso: ");
    scanf(" %d", &codigo);
    BuscarCurso_para_ExibirDsc_por_CH(arvoreCursos, codigo, cargahr);

    // primeira questao - C - 8
    printf("----- Remover Disciplina -----\n");
    printf("Digite o codigo da Disciplina: ");
    scanf(" %d", &codigo_dsc);
    printf("Digite o codigo do Curso: ");
    scanf(" %d", &codigo);
    BuscarCurso_para_RemoverDsc(&arvoreCursos, codigo, codigo_dsc);
    printf("----- Disciplinas do Curso -----\n");
    printf("Digite o codigo do curso para ver as disciplinas: ");
    ExibirDsc_por_Curso(arvoreCursos, codigo);

    // primeira questao - C - 9
    printf("---- Remover Curso ----\n");
    printf("Digite o codigo do curso: ");
    scanf(" %d", &codigo);
    RemoverCurso(&arvoreCursos, codigo);
    printf("----- Todos os Cursos -----\n");
    Exibir_Todos_Cursos(arvoreCursos);

    return 0;
}