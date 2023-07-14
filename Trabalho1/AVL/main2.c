#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "cursosAVL.h"

int main()
{
    // CÓDIGO DE MEDIR TEMPO PARA LINUX 
    // clock_t inicio, fim;
    // double tempo_decorrido;
    int codigo;
    srand(time(NULL));
    Curso *arvoreCursos = CriarArvore_Curso();

    LARGE_INTEGER inicio, fim, frequencia;
    double tempo_total;

    QueryPerformanceFrequency(&frequencia);

    // Obtém o tempo inicial
    // inicio = clock();
    QueryPerformanceCounter(&inicio);

    double tempo;
    // BLOCO DE INSERÇÃO DE CURSOS

    for (int i = 0; i < 40; i++)
    {
        AdicionarCurso(&arvoreCursos, rand()%1000, "Curso ", 8, 16);
    }

    // Obtém o tempo final
    // fim = clock(); // marca o fim da seção de código
    QueryPerformanceCounter(&fim);

    // Calcula o tempo total em milissegundos
    // tempo_decorrido = (double)(fim - inicio) / CLOCKS_PER_SEC * 1000;
    tempo_total = (double)(fim.QuadPart - inicio.QuadPart) / frequencia.QuadPart * 1000;

    // Exibe o tempo total de preenchimento da árvore
    // printf("Tempo decorrido: %.2f segundos\n", tempo_decorrido);
    printf("Tempo total Adicao de Cursos: %.5f milissegundos\n", tempo_total);
    printf("------------------------------------------------\n");

    int cont = 0;
    int opcao = -1;
    double media = 0.0;
    while (opcao != 0)
    {
        printf("----------------\n");
        printf("-----OPCOES-----\n"
               "----------------\n"
               "0 - Para Sair\n"
               "1 - Todos os Cursos\n"
               "2 - Dados de um Curso\n"
               "3 - Exibir Cursos por Blocos\n"
               "4 - Disciplinas do Curso\n"
               "5 - Dados de uma unica Disciplina\n"
               "6 - Dados das Disciplinas de acordo com um bloco\n"
               "7 - Dados das Disciplinas por Carga horaria\n"
               "8 - Remover Disciplina\n"
               "9 - Remover Curso\n"
               "10 - Adicionar Curso\n"
               "11 - Adicionar Disciplina\n"
               "Digite a opcao: ");

        scanf(" %d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("----- Todos os Cursos -----\n");
            Exibir_Todos_Cursos(arvoreCursos);
            printf("\n");
            break;
        case 2:
            printf("----- Dados de um Curso -----\n");
            printf("Digite o codigo do curso que deseja ver os dados: ");
            scanf(" %d", &codigo);

            // MEDIR TEMPO PARA INSERIR UM DADO
            // QueryPerformanceFrequency(&frequencia);
            // Obtém o tempo inicial
            // QueryPerformanceCounter(&inicio);
            // double tempo;

            ExibirDados_Curso(arvoreCursos, codigo);

            // Obtém o tempo final
            // QueryPerformanceCounter(&fim);
            // media += tempo_total = (double)(fim.QuadPart - inicio.QuadPart) / frequencia.QuadPart * 1000;
            // printf("\n\nMedia ta: %.5lf\n\n", media);
            // printf("Tempo total procura de Cursos: %.5f milissegundos\n", tempo_total);

            break;
        case 3:
            printf("----- Exibir Cursos por Blocos -----\n");
            int quantidade;
            printf("Digite a quantidade de blocos que deseja procurar: ");
            scanf(" %d", &quantidade);
            ExibirCursoBloco(arvoreCursos, quantidade);
            break;
        case 4:
            printf("----- Disciplinas do Curso -----\n");
            printf("Digite o codigo do curso para ver as disciplinas: ");
            scanf(" %d", &codigo);
            ExibirDsc_por_Curso(arvoreCursos, codigo);
            printf("\n");
            break;
        case 5:
            printf("---- Dados de uma unica Disciplina -----\n");
            int codigo_dsc;
            printf("Digite o codigo do Curso: ");
            scanf(" %d", &codigo);
            printf("Digite o codigo da Disciplina: ");
            scanf(" %d", &codigo_dsc);
            Imprimir_dsc(arvoreCursos, codigo, codigo_dsc);
            printf("\n");
            break;
        case 6:
            printf("----- Dados das Disciplinas de acordo com um bloco -----\n ");
            int bloco;
            printf("Digite codigo do bloco: ");
            scanf(" %d", &bloco);
            printf("Digite codigo do curso: ");
            scanf(" %d", &codigo);

            BuscarCurso_para_ExibirDsc_por_Bloco(arvoreCursos, codigo, bloco);
            printf("\n");
            break;
        case 7:
            printf("----- Dados das Disciplinas por Carga horaria -----\n");
            int cargahr;
            printf("Digite a Carga Horaia: ");
            scanf(" %d", &cargahr);
            printf("Digite o Codigo do Curso: ");
            scanf(" %d", &codigo);
            BuscarCurso_para_ExibirDsc_por_CH(arvoreCursos, codigo, cargahr);
            printf("\n");
            break;
        case 8:
            printf("----- Remover Disciplina -----\n");
            printf("Digite o codigo da Disciplina: ");
            scanf(" %d", &codigo_dsc);
            printf("Digite o codigo do Curso: ");
            scanf(" %d", &codigo);
            BuscarCurso_para_RemoverDsc(&arvoreCursos, codigo, codigo_dsc);
            printf("----- Disciplinas do Curso -----\n");
            printf("Digite o codigo do curso para ver as disciplinas: ");
            ExibirDsc_por_Curso(arvoreCursos, codigo);
            printf("\n");
            break;
        case 9:
            printf("---- Remover Curso ----\n");
            printf("Digite o codigo do curso: ");
            scanf(" %d", &codigo);
            arvoreCursos = RemoverCurso(arvoreCursos, codigo);
            printf("----- Todos os Cursos -----\n");
            Exibir_Todos_Cursos(arvoreCursos);
            printf("\n");
            break;
        case 10:
            printf("----- Adicionar Novo Curso ----\n");
            char nome_curso[20];
            int codigo_curso;
            int bloco_curso;
            int semana_curso;
            int comparacao = 0;
            printf("Digite o nome do curso: ");
            scanf(" %[^\n]s", nome_curso);
            printf("Digite o codigo do curso: ");
            scanf(" %d", &codigo_curso);
            printf("Digite o bloco do curso: ");
            scanf(" %d", &bloco_curso);
            printf("Digite as semanas do curso: ");
            scanf(" %d", &semana_curso);

            if (verificar_semelhanca(arvoreCursos, nome_curso, codigo_curso) == 1)
            {
                printf("ESSE CODIGO DE CURSO JA EXISTE\n");
            }
            else if (verificar_semelhanca(arvoreCursos, nome_curso, codigo_curso) == 2)
            {
                printf("ESSE NOME DE CURSO JA EXISTE\n");
            }
            else
            {
                AdicionarCurso(&arvoreCursos, codigo_curso, nome_curso, bloco_curso, semana_curso);
                printf("CURSO ADICIONADO COM SUCESSO!!!\n");
            }
            break;
        case 11:
            printf("----- Adicionar Nova Disciplina ----\n");
            printf("Digite o codigo do curso: ");
            scanf(" %d", &codigo_curso);

            if (verificar_semelhanca(arvoreCursos, nome_curso, codigo_curso) == 1)
            {
                char nome_dsc[20];
                int codigo_dsc;
                int cargahorario_dsc;
                int bloco_dsc;
                printf("\t\tCURSO ENCONTRADO\n");
                printf("----- Inserir Dados da Disciplina -----\n");
                printf("Digite o nome da Disciplina: ");
                scanf(" %[^\n]s", nome_dsc);
                printf("Digite o codigo da Disciplina: ");
                scanf(" %d", &codigo_dsc);
                printf("Digite a cargahoraria da Discplina: ");
                scanf(" %d", &cargahorario_dsc);
                printf("Digite o bloco da Disciplina: ");
                scanf(" %d", &bloco_dsc);

                int resultado = 0;
                verificar_semelhanca_dsc(arvoreCursos, codigo_curso, codigo_dsc, cargahorario_dsc, bloco_dsc, &resultado);

                switch (resultado)
                {
                case 1:
                    printf("QUANTIDADE DE BLOCOS MAIOR QUE A DO CURSO\n");
                    break;
                case 2:
                    printf("VALOR DA CARGA HORARIO NAO COMPATIVEL COM SEMANAS DO CURSO\n");
                    break;
                case 0:
                    printf("DISCIPLINA REGISTRADA COM SUCESSO\n");
                    AdicionarDsc_em_curso(&arvoreCursos, codigo_curso, codigo_dsc, nome_dsc, bloco_dsc, cargahorario_dsc);
                    break;
                default:
                    printf("ERRO\n");
                    break;
                }
            }
            else
            {
                printf("\nCURSO NAO ENCONTRADO\n");
            }
            break;
        default:
            break;
        }
    }

}
