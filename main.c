#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include"curso.h"

int main() {

    int codigo;

    Curso *arvoreCursos = CriarArvore_Curso();
    Disciplina *arvoreDisciplinas = CriarArvore_Dsc();
    AdicionarCurso(&arvoreCursos, 1, "ENG", 8, 16);
    AdicionarCurso(&arvoreCursos, 2, "ADM", 10, 18);
    AdicionarCurso(&arvoreCursos, 3, "MED", 8, 16);
    AdicionarCurso(&arvoreCursos, 4, "SI", 10, 18);
    AdicionarCurso(&arvoreCursos, 5, "ENG.AGR", 8, 16);
    AdicionarCurso(&arvoreCursos, 7, "ENG.MEC", 10, 18);
    AdicionarCurso(&arvoreCursos, 6, "ENG.CIV", 8, 16);
    AdicionarCurso(&arvoreCursos, 9, "NUTR", 10, 18);
    AdicionarCurso(&arvoreCursos, 8, "MATE", 8, 16);
    AdicionarCurso(&arvoreCursos, 10, "ED.FIS", 10, 18);
    
    //primeira questao - C - 1
    printf("----- Todos os Cursos -----\n");
    Exibir_Todos_Cursos(arvoreCursos);

    //primeira questao - C - 2
    printf("----- Dados de um Curso -----\n");
    printf("Digite o codigo do curso que deseja ver os dados: ");
    scanf(" %d",&codigo);
    ExibirDados_Curso(arvoreCursos,codigo);

    //primeira questao - c - 3
    printf("----- Exibir Cursos por Blocos -----\n");
    int quantidade;
    printf("Digite a quantidade de blocos que deseja procurar: ");
    scanf(" %d", &quantidade);
    ExibirCursoBloco(arvoreCursos,quantidade);

    AdicionarDsc_em_curso(&arvoreCursos,4, 101, "POO1", 4, 60);
    AdicionarDsc_em_curso(&arvoreCursos,4, 102, "BD1", 4, 90);
    AdicionarDsc_em_curso(&arvoreCursos,4, 113, "ED1", 4, 60);
    AdicionarDsc_em_curso(&arvoreCursos,4, 104, "ALG1", 4, 90);
    AdicionarDsc_em_curso(&arvoreCursos,4, 105, "REDES1", 4, 60);
    AdicionarDsc_em_curso(&arvoreCursos,4, 111, "POO2", 4, 90);
    AdicionarDsc_em_curso(&arvoreCursos,4, 107, "BD2", 4, 60);
    AdicionarDsc_em_curso(&arvoreCursos,4, 120, "ED2", 4, 90);
    AdicionarDsc_em_curso(&arvoreCursos,4, 109, "ALG2", 4, 60);
    AdicionarDsc_em_curso(&arvoreCursos,4, 110, "REDES2", 4, 90);   

    AdicionarDsc_em_curso(&arvoreCursos,2, 101, "GESTAO", 2, 60);
    AdicionarDsc_em_curso(&arvoreCursos,2, 102, "FILOSOFIA", 2, 90);
    AdicionarDsc_em_curso(&arvoreCursos,2, 113, "EMPREENDEDORISMO", 2, 60);
    AdicionarDsc_em_curso(&arvoreCursos,2, 104, "CALCULO 1", 5, 90);
    AdicionarDsc_em_curso(&arvoreCursos,2, 105, "CALCULO 2", 2, 60);
    AdicionarDsc_em_curso(&arvoreCursos,2, 111, "PLANEJAMENTO", 2, 90);
    AdicionarDsc_em_curso(&arvoreCursos,2, 107, "SERVICOS", 2, 60);
    AdicionarDsc_em_curso(&arvoreCursos,2, 120, "MERCADO", 2, 90);
    AdicionarDsc_em_curso(&arvoreCursos,2, 109, "MARKETING", 2, 60);
    AdicionarDsc_em_curso(&arvoreCursos,2, 110, "FINANCEIRO", 2, 90);

    //primeira questao - C - 4
    printf("----- Disciplinas do Curso -----\n");
    printf("Digite o codigo do curso para ver as disciplinas: ");
    scanf(" %d",&codigo);
    ExibirDsc_por_Curso(arvoreCursos,codigo);

    //primeira questao - C - 5
    printf("---- Dados de uma unica Disciplina -----\n");
    int codigo_dsc;
    printf("Digite o codigo do Curso: ");
    scanf(" %d",&codigo);
    printf("Digite o codigo da Disciplina: ");
    scanf(" %d",&codigo_dsc);
    Imprimir_dsc(arvoreCursos,codigo,codigo_dsc);

    //primeira questao - C - 6
    printf("----- Dados das Disciplinas de acordo com um bloco -----\n ");
    int bloco;
    printf("Digite codigo do bloco: ");
    scanf(" %d",&bloco);
    printf("Digite codigo do curso: ");
    scanf(" %d",&codigo);

    BuscarCurso_para_ExibirDsc_por_Bloco(arvoreCursos,codigo,bloco);

    //primeira questao - C - 7
    printf("----- Dados das Disciplinas por Carga horaria -----\n");
    int cargahr;
    printf("Digite a Carga Horaia: ");
    scanf(" %d",&cargahr);
    printf("Digite o Codigo do Curso: ");
    scanf(" %d",&codigo);
    BuscarCurso_para_ExibirDsc_por_CH(arvoreCursos,codigo,cargahr);
     
    //primeira questao - C - 8
    printf("----- Remover Disciplina -----\n");
    printf("Digite o codigo da Disciplina: ");
    scanf(" %d",&codigo_dsc);
    printf("Digite o codigo do Curso: ");
    scanf(" %d",&codigo);
    BuscarCurso_para_RemoverDsc(&arvoreCursos,codigo,codigo_dsc);
     
        /*while (opcao != 0)
    {
        switch (opcao)
        {
        case 1:
            //imprimir arvore de cursos em ordem crescente
            break;
        case 2:
            //imprimir os dados de um curso de acordo com o código
            break;
        case 3:
            //Imprimir os curso com a mesma quantidade de blocos, onde o usuário informa os blocos
            break;
        case 4:
            //Imprimir a ávore das disciplinas em ordem crescente pelo código da disciplina dado o código do curso
            break;
        case 5:
            //Imprimir os dados de uma disciplina dado o código dela e do curso ao qual pertence
            break;
        case 6:
            //Imprimir as disciplinas de um determinado bloco de um curso, dado o bloco e o curso
            break;
        case 7:
            //Imprimir todas as disciplinas de um determinado curso com a mesma carga horaria, onde o codigo do curso e a cargo horario devem ser informado pelo usuario
            break;
        case 8:
            //Excluir uma disciplina dado o código da disciplina e o código do curso
            break;
        case 9:
            //Excluir um curso dado o código do mesmo, desde que não haja disciplinas cadastradas no mesmo
            break;
        default:
        printf("ESSA OPCAO NAO EXISTE\n");
            break;
        }
    }*/ 
    return 0;
}