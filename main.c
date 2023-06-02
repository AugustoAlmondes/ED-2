#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "cursos.h"

int main()
{

    int codigo;

    Curso *arvoreCursos = CriarArvore_Curso();

    clock_t inicio, fim;

    double tempo;

    inicio = clock();

    // FUNÇÃO PARA ADICIONAR NÓ NA ÁRVORE DE CURSOS
    AdicionarCurso(&arvoreCursos, 7, "Curso 7", 8, 16);
    AdicionarCurso(&arvoreCursos, 29, "Curso 29", 10, 18);
    AdicionarCurso(&arvoreCursos, 2, "Curso 2", 10, 18); // Preenchidio
    AdicionarCurso(&arvoreCursos, 19, "Curso 19", 10, 18);
    AdicionarCurso(&arvoreCursos, 26, "Curso 26", 10, 18);
    AdicionarCurso(&arvoreCursos, 3, "Curso 3", 8, 16);
    AdicionarCurso(&arvoreCursos, 35, "Curso 35", 8, 16);
    AdicionarCurso(&arvoreCursos, 48, "Curso 48", 10, 18);
    AdicionarCurso(&arvoreCursos, 1, "Curso 1", 10, 18);
    AdicionarCurso(&arvoreCursos, 25, "Curso 25", 8, 16);
    AdicionarCurso(&arvoreCursos, 16, "Curso 16", 8, 16);
    AdicionarCurso(&arvoreCursos, 5, "Curso 5", 8, 16);
    AdicionarCurso(&arvoreCursos, 47, "Curso 47", 10, 18); // Preenchidio
    AdicionarCurso(&arvoreCursos, 22, "Curso 22", 8, 16);
    AdicionarCurso(&arvoreCursos, 27, "Curso 27", 10, 18);
    AdicionarCurso(&arvoreCursos, 6, "Curso 6", 8, 16);
    AdicionarCurso(&arvoreCursos, 9, "Curso 9", 10, 18);
    AdicionarCurso(&arvoreCursos, 8, "Curso 8", 8, 16);
    AdicionarCurso(&arvoreCursos, 10, "Curso 10", 10, 18);
    AdicionarCurso(&arvoreCursos, 11, "Curso 11", 8, 16);
    AdicionarCurso(&arvoreCursos, 15, "Curso 15", 10, 18);
    AdicionarCurso(&arvoreCursos, 13, "Curso 33", 8, 16);
    AdicionarCurso(&arvoreCursos, 12, "Curso 12", 8, 16);
    AdicionarCurso(&arvoreCursos, 17, "Curso 17", 10, 18);
    AdicionarCurso(&arvoreCursos, 4, "Curso 4", 10, 18);
    AdicionarCurso(&arvoreCursos, 21, "Curso 21", 8, 16);
    AdicionarCurso(&arvoreCursos, 23, "Curso 23", 10, 18);
    AdicionarCurso(&arvoreCursos, 30, "Curso 30", 8, 16);
    AdicionarCurso(&arvoreCursos, 28, "Curso 28", 8, 16);
    AdicionarCurso(&arvoreCursos, 20, "Curso 20", 10, 18);
    AdicionarCurso(&arvoreCursos, 34, "Curso 34", 10, 18);
    AdicionarCurso(&arvoreCursos, 37, "Curso 37", 8, 16);
    AdicionarCurso(&arvoreCursos, 32, "Curso 32", 10, 18);
    AdicionarCurso(&arvoreCursos, 41, "Curso 41", 8, 16);
    AdicionarCurso(&arvoreCursos, 42, "Curso 42", 8, 16);
    AdicionarCurso(&arvoreCursos, 49, "Curso 49", 10, 18);
    AdicionarCurso(&arvoreCursos, 14, "Curso 14", 10, 18);
    AdicionarCurso(&arvoreCursos, 18, "Curso 18", 8, 16);
    AdicionarCurso(&arvoreCursos, 24, "Curso 24", 10, 18);
    AdicionarCurso(&arvoreCursos, 13, "Curso 13", 8, 16);
    AdicionarCurso(&arvoreCursos, 48, "Curso 48", 8, 16);
    AdicionarCurso(&arvoreCursos, 57, "Curso 57", 10, 18);

    fim = clock();

    tempo = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000;

    printf("Tempo para preencher Arvore: %.5lf milissegundos\n", tempo);
    printf("------------------------------------------------\n");

    // primeira questao - C - 1
    /*printf("----- Todos os Cursos -----\n");
    Exibir_Todos_Cursos(arvoreCursos);*/

    // primeira questao - C - 2

    inicio = clock();
    printf("----- Dados de um Curso -----\n");
    printf("Digite o codigo do curso que deseja ver os dados: ");
    scanf(" %d", &codigo);
    ExibirDados_Curso(arvoreCursos, codigo);
    fim = clock();

    tempo = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000;
    printf("Tempo para exibir dados de um curso: %.5lf milissegundos\n", tempo);
    printf("------------------------------------------------\n");

    // primeira questao - c - 3
    printf("----- Exibir Cursos por Blocos -----\n");
    int quantidade;
    printf("Digite a quantidade de blocos que deseja procurar: ");
    scanf(" %d", &quantidade);
    ExibirCursoBloco(arvoreCursos, quantidade);

        AdicionarDsc_em_curso(&arvoreCursos,4, 101, "DSC_101_CURSO_4", 4, 60);
        AdicionarDsc_em_curso(&arvoreCursos,4, 102, "DSC_102_CURSO_4", 4, 90);
        AdicionarDsc_em_curso(&arvoreCursos,4, 113, "DSC_113_CURSO_4", 4, 60);
        AdicionarDsc_em_curso(&arvoreCursos,4, 104, "DSC_104_CURSO_4", 4, 90);
        AdicionarDsc_em_curso(&arvoreCursos,4, 105, "DSC_105_CURSO_4", 4, 60);
        AdicionarDsc_em_curso(&arvoreCursos,4, 111, "DSC_111_CURSO_4", 4, 90);
        AdicionarDsc_em_curso(&arvoreCursos,4, 107, "DSC_107_CURSO_4", 4, 60);
        AdicionarDsc_em_curso(&arvoreCursos,4, 120, "DSC_201_CURSO_4", 4, 90);
        AdicionarDsc_em_curso(&arvoreCursos,4, 109, "DSC_109_CURSO_4", 4, 60);
        AdicionarDsc_em_curso(&arvoreCursos,4, 110, "DSC_110_CURSO_4", 4, 90);   

        AdicionarDsc_em_curso(&arvoreCursos,2, 113, "DSC_113_CURSO_2", 2, 60);
        AdicionarDsc_em_curso(&arvoreCursos,2, 102, "DSC_102_CURSO_2", 2, 90);
        AdicionarDsc_em_curso(&arvoreCursos,2, 101, "DSC_101_CURSO_2", 2, 60);
        AdicionarDsc_em_curso(&arvoreCursos,2, 104, "DSC_104_CURSO_2", 5, 90);
        AdicionarDsc_em_curso(&arvoreCursos,2, 105, "DSC_105_CURSO_2", 2, 60);
        AdicionarDsc_em_curso(&arvoreCursos,2, 111, "DSC_111_CURSO_2", 2, 90);
        AdicionarDsc_em_curso(&arvoreCursos,2, 107, "DSC_107_CURSO_2", 2, 60);
        AdicionarDsc_em_curso(&arvoreCursos,2, 120, "DSC_120_CURSO_2", 2, 90);
        AdicionarDsc_em_curso(&arvoreCursos,2, 109, "DSC_109_CURSO_2", 2, 60);
        AdicionarDsc_em_curso(&arvoreCursos,2, 110, "DSC_110_CURSO_2", 2, 90);

        AdicionarDsc_em_curso(&arvoreCursos,6, 113, "DSC_113_CURSO_6", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos,6, 101, "DSC_101_CURSO_6", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos,6, 120, "DSC_120_CURSO_6", 6, 90);
        AdicionarDsc_em_curso(&arvoreCursos,6, 105, "DSC_105_CURSO_6", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos,6, 111, "DSC_111_CURSO_6", 6, 90);
        AdicionarDsc_em_curso(&arvoreCursos,6, 107, "DSC_107_CURSO_6", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos,6, 104, "DSC_104_CURSO_6", 6, 90);
        AdicionarDsc_em_curso(&arvoreCursos,6, 109, "DSC_109_CURSO_6", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos,6, 110, "DSC_110_CURSO_6", 6, 90);
        AdicionarDsc_em_curso(&arvoreCursos,6, 102, "DSC_102_CURSO_6", 6, 90);

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
