#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "cursos.h"

int main()
{

    int codigo;

    Curso *arvoreCursos = CriarArvore_Curso();

    LARGE_INTEGER inicio, fim, frequencia;
    double tempo_total;

    // Obtém a frequência do contador de performance
    QueryPerformanceFrequency(&frequencia);

    // Obtém o tempo inicial
    QueryPerformanceCounter(&inicio);
    
    double tempo;

    // BLOCO DE ADIÇÃO DE CURSOS
    {
        AdicionarCurso(&arvoreCursos, 36, "Curso 36", 8, 16);
        AdicionarCurso(&arvoreCursos, 39, "Curso 39", 8, 16);
        AdicionarCurso(&arvoreCursos, 6, "Curso 6", 8, 16);
        AdicionarCurso(&arvoreCursos, 25, "Curso 25", 8, 16);
        AdicionarCurso(&arvoreCursos, 24, "Curso 24", 8, 16);
        AdicionarCurso(&arvoreCursos, 4, "Curso 4", 8, 16);
        AdicionarCurso(&arvoreCursos, 30, "Curso 30", 8, 16);
        AdicionarCurso(&arvoreCursos, 15, "Curso 15", 8, 16);
        AdicionarCurso(&arvoreCursos, 14, "Curso 14", 8, 16);
        AdicionarCurso(&arvoreCursos, 16, "Curso 16", 8, 16);
        AdicionarCurso(&arvoreCursos, 33, "Curso 33", 8, 16);
        AdicionarCurso(&arvoreCursos, 2, "Curso 2", 8, 16);
        AdicionarCurso(&arvoreCursos, 19, "Curso 19", 8, 16);
        AdicionarCurso(&arvoreCursos, 38, "Curso 38", 8, 16);
        AdicionarCurso(&arvoreCursos, 8, "Curso 8", 8, 16);
        AdicionarCurso(&arvoreCursos, 17, "Curso 17", 8, 16);
        AdicionarCurso(&arvoreCursos, 7, "Curso 7", 8, 16);
        AdicionarCurso(&arvoreCursos, 32, "Curso 32", 8, 16);
        AdicionarCurso(&arvoreCursos, 41, "Curso 41", 8, 16);
        AdicionarCurso(&arvoreCursos, 13, "Curso 13", 8, 16);
        AdicionarCurso(&arvoreCursos, 11, "Curso 11", 8, 16);
        AdicionarCurso(&arvoreCursos, 1, "Curso 1", 8, 16);
        AdicionarCurso(&arvoreCursos, 28, "Curso 28", 8, 16);
        AdicionarCurso(&arvoreCursos, 10, "Curso 10", 8, 16);
        AdicionarCurso(&arvoreCursos, 9, "Curso 9", 8, 16);
        AdicionarCurso(&arvoreCursos, 21, "Curso 21", 8, 16);
        AdicionarCurso(&arvoreCursos, 5, "Curso 5", 8, 16);
        AdicionarCurso(&arvoreCursos, 29, "Curso 29", 8, 16);
        AdicionarCurso(&arvoreCursos, 34, "Curso 34", 8, 16);
        AdicionarCurso(&arvoreCursos, 18, "Curso 18", 8, 16);
        AdicionarCurso(&arvoreCursos, 26, "Curso 26", 8, 16);
        AdicionarCurso(&arvoreCursos, 12, "Curso 12", 8, 16);
        AdicionarCurso(&arvoreCursos, 31, "Curso 31", 8, 16);
        AdicionarCurso(&arvoreCursos, 37, "Curso 37", 8, 16);
        AdicionarCurso(&arvoreCursos, 40, "Curso 40", 8, 16);
        AdicionarCurso(&arvoreCursos, 3, "Curso 3", 8, 16);
        AdicionarCurso(&arvoreCursos, 23, "Curso 23", 8, 16);
        AdicionarCurso(&arvoreCursos, 22, "Curso 22", 8, 16);
        AdicionarCurso(&arvoreCursos, 20, "Curso 20", 8, 16);
        AdicionarCurso(&arvoreCursos, 35, "Curso 35", 8, 16);
        AdicionarCurso(&arvoreCursos, 27, "Curso 27", 8, 16);
        AdicionarCurso(&arvoreCursos, 0, "Curso 0", 8, 16);
    }

    // Obtém o tempo final
    QueryPerformanceCounter(&fim);

    // Calcula o tempo total em milissegundos
    tempo_total = (double)(fim.QuadPart - inicio.QuadPart) / frequencia.QuadPart * 1000;

    // Exibe o tempo total de preenchimento da árvore
    printf("Tempo total Adicao de Cursos: %.5f milissegundos\n", tempo_total);

    printf("------------------------------------------------\n");

    QueryPerformanceFrequency(&frequencia);

    // Obtém o tempo inicial
    QueryPerformanceCounter(&inicio);

    // BLOCO DE ADIÇÃO DE DISCIPLINAS NO CURSO
    //-----------------------------------------------
    {
        AdicionarDsc_em_curso(&arvoreCursos, 36, 115, "DSC_115_CURSO_36", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 36, 113, "DSC_113_CURSO_36", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 36, 107, "DSC_107_CURSO_36", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 36, 159, "DSC_159_CURSO_36", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 36, 127, "DSC_127_CURSO_36", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 36, 164, "DSC_164_CURSO_36", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 36, 167, "DSC_167_CURSO_36", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 36, 165, "DSC_165_CURSO_36", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 36, 105, "DSC_105_CURSO_36", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 36, 153, "DSC_153_CURSO_36", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 27, 175, "DSC_175_CURSO_27", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 27, 105, "DSC_105_CURSO_27", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 27, 196, "DSC_196_CURSO_27", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 27, 105, "DSC_105_CURSO_27", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 27, 131, "DSC_131_CURSO_27", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 27, 136, "DSC_136_CURSO_27", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 27, 156, "DSC_156_CURSO_27", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 27, 133, "DSC_133_CURSO_27", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 27, 137, "DSC_137_CURSO_27", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 27, 163, "DSC_163_CURSO_27", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 1, 108, "DSC_108_CURSO_1", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 1, 110, "DSC_110_CURSO_1", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 1, 137, "DSC_137_CURSO_1", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 1, 188, "DSC_188_CURSO_1", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 1, 153, "DSC_153_CURSO_1", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 1, 175, "DSC_175_CURSO_1", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 1, 134, "DSC_134_CURSO_1", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 1, 130, "DSC_130_CURSO_1", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 1, 190, "DSC_190_CURSO_1", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 1, 122, "DSC_122_CURSO_1", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 149, "DSC_149_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 114, "DSC_114_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 179, "DSC_179_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 152, "DSC_152_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 199, "DSC_199_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 133, "DSC_133_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 102, "DSC_102_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 195, "DSC_195_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 158, "DSC_158_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 184, "DSC_184_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 28, 169, "DSC_169_CURSO_28", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 28, 100, "DSC_100_CURSO_28", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 28, 130, "DSC_130_CURSO_28", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 28, 108, "DSC_108_CURSO_28", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 28, 128, "DSC_128_CURSO_28", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 28, 101, "DSC_101_CURSO_28", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 28, 119, "DSC_119_CURSO_28", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 28, 126, "DSC_126_CURSO_28", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 28, 165, "DSC_165_CURSO_28", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 28, 118, "DSC_118_CURSO_28", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 26, 148, "DSC_148_CURSO_26", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 26, 190, "DSC_190_CURSO_26", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 26, 113, "DSC_113_CURSO_26", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 26, 189, "DSC_189_CURSO_26", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 26, 133, "DSC_133_CURSO_26", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 26, 144, "DSC_144_CURSO_26", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 26, 160, "DSC_160_CURSO_26", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 26, 144, "DSC_144_CURSO_26", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 26, 122, "DSC_122_CURSO_26", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 26, 167, "DSC_167_CURSO_26", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 26, 184, "DSC_184_CURSO_26", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 26, 183, "DSC_183_CURSO_26", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 26, 169, "DSC_169_CURSO_26", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 26, 119, "DSC_119_CURSO_26", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 26, 112, "DSC_112_CURSO_26", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 26, 148, "DSC_148_CURSO_26", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 26, 154, "DSC_154_CURSO_26", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 26, 187, "DSC_187_CURSO_26", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 26, 104, "DSC_104_CURSO_26", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 26, 173, "DSC_173_CURSO_26", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 17, 150, "DSC_150_CURSO_17", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 17, 126, "DSC_126_CURSO_17", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 17, 113, "DSC_113_CURSO_17", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 17, 126, "DSC_126_CURSO_17", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 17, 187, "DSC_187_CURSO_17", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 17, 187, "DSC_187_CURSO_17", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 17, 146, "DSC_146_CURSO_17", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 17, 156, "DSC_156_CURSO_17", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 17, 120, "DSC_120_CURSO_17", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 17, 126, "DSC_126_CURSO_17", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 8, 172, "DSC_172_CURSO_8", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 8, 192, "DSC_192_CURSO_8", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 8, 123, "DSC_123_CURSO_8", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 8, 119, "DSC_119_CURSO_8", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 8, 190, "DSC_190_CURSO_8", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 8, 161, "DSC_161_CURSO_8", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 8, 196, "DSC_196_CURSO_8", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 8, 129, "DSC_129_CURSO_8", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 8, 142, "DSC_142_CURSO_8", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 8, 129, "DSC_129_CURSO_8", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 31, 129, "DSC_129_CURSO_31", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 31, 139, "DSC_139_CURSO_31", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 31, 153, "DSC_153_CURSO_31", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 31, 167, "DSC_167_CURSO_31", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 31, 129, "DSC_129_CURSO_31", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 31, 101, "DSC_101_CURSO_31", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 31, 138, "DSC_138_CURSO_31", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 31, 192, "DSC_192_CURSO_31", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 31, 162, "DSC_162_CURSO_31", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 31, 110, "DSC_110_CURSO_31", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 15, 181, "DSC_181_CURSO_15", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 15, 161, "DSC_161_CURSO_15", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 15, 125, "DSC_125_CURSO_15", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 15, 196, "DSC_196_CURSO_15", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 15, 162, "DSC_162_CURSO_15", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 15, 120, "DSC_120_CURSO_15", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 15, 151, "DSC_151_CURSO_15", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 15, 186, "DSC_186_CURSO_15", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 15, 133, "DSC_133_CURSO_15", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 15, 148, "DSC_148_CURSO_15", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 25, 159, "DSC_159_CURSO_25", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 25, 109, "DSC_109_CURSO_25", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 25, 125, "DSC_125_CURSO_25", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 25, 104, "DSC_104_CURSO_25", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 25, 122, "DSC_122_CURSO_25", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 25, 136, "DSC_136_CURSO_25", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 25, 196, "DSC_196_CURSO_25", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 25, 196, "DSC_196_CURSO_25", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 25, 131, "DSC_131_CURSO_25", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 25, 171, "DSC_171_CURSO_25", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 8, 115, "DSC_115_CURSO_8", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 8, 164, "DSC_164_CURSO_8", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 8, 102, "DSC_102_CURSO_8", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 8, 120, "DSC_120_CURSO_8", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 8, 124, "DSC_124_CURSO_8", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 8, 161, "DSC_161_CURSO_8", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 8, 116, "DSC_116_CURSO_8", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 8, 100, "DSC_100_CURSO_8", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 8, 120, "DSC_120_CURSO_8", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 8, 181, "DSC_181_CURSO_8", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 4, 129, "DSC_129_CURSO_4", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 4, 190, "DSC_190_CURSO_4", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 4, 159, "DSC_159_CURSO_4", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 4, 106, "DSC_106_CURSO_4", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 4, 168, "DSC_168_CURSO_4", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 4, 143, "DSC_143_CURSO_4", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 4, 192, "DSC_192_CURSO_4", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 4, 143, "DSC_143_CURSO_4", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 4, 159, "DSC_159_CURSO_4", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 4, 105, "DSC_105_CURSO_4", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 34, 199, "DSC_199_CURSO_34", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 34, 125, "DSC_125_CURSO_34", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 34, 134, "DSC_134_CURSO_34", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 34, 140, "DSC_140_CURSO_34", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 34, 187, "DSC_187_CURSO_34", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 34, 108, "DSC_108_CURSO_34", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 34, 120, "DSC_120_CURSO_34", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 34, 191, "DSC_191_CURSO_34", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 34, 130, "DSC_130_CURSO_34", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 34, 147, "DSC_147_CURSO_34", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 164, "DSC_164_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 188, "DSC_188_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 186, "DSC_186_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 169, "DSC_169_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 173, "DSC_173_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 193, "DSC_193_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 166, "DSC_166_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 104, "DSC_104_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 183, "DSC_183_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 149, "DSC_149_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 37, 185, "DSC_185_CURSO_37", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 37, 179, "DSC_179_CURSO_37", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 37, 138, "DSC_138_CURSO_37", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 37, 106, "DSC_106_CURSO_37", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 37, 103, "DSC_103_CURSO_37", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 37, 162, "DSC_162_CURSO_37", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 37, 107, "DSC_107_CURSO_37", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 37, 198, "DSC_198_CURSO_37", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 37, 118, "DSC_118_CURSO_37", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 37, 137, "DSC_137_CURSO_37", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 14, 106, "DSC_106_CURSO_14", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 14, 185, "DSC_185_CURSO_14", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 14, 176, "DSC_176_CURSO_14", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 14, 102, "DSC_102_CURSO_14", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 14, 158, "DSC_158_CURSO_14", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 14, 166, "DSC_166_CURSO_14", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 14, 110, "DSC_110_CURSO_14", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 14, 164, "DSC_164_CURSO_14", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 14, 170, "DSC_170_CURSO_14", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 14, 167, "DSC_167_CURSO_14", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 31, 194, "DSC_194_CURSO_31", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 31, 197, "DSC_197_CURSO_31", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 31, 106, "DSC_106_CURSO_31", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 31, 193, "DSC_193_CURSO_31", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 31, 186, "DSC_186_CURSO_31", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 31, 113, "DSC_113_CURSO_31", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 31, 131, "DSC_131_CURSO_31", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 31, 127, "DSC_127_CURSO_31", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 31, 173, "DSC_173_CURSO_31", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 31, 100, "DSC_100_CURSO_31", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 12, 147, "DSC_147_CURSO_12", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 12, 112, "DSC_112_CURSO_12", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 12, 183, "DSC_183_CURSO_12", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 12, 109, "DSC_109_CURSO_12", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 12, 146, "DSC_146_CURSO_12", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 12, 160, "DSC_160_CURSO_12", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 12, 109, "DSC_109_CURSO_12", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 12, 111, "DSC_111_CURSO_12", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 12, 188, "DSC_188_CURSO_12", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 12, 150, "DSC_150_CURSO_12", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 2, 140, "DSC_140_CURSO_2", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 2, 129, "DSC_129_CURSO_2", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 2, 196, "DSC_196_CURSO_2", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 2, 114, "DSC_114_CURSO_2", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 2, 110, "DSC_110_CURSO_2", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 2, 196, "DSC_196_CURSO_2", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 2, 124, "DSC_124_CURSO_2", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 2, 192, "DSC_192_CURSO_2", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 2, 184, "DSC_184_CURSO_2", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 2, 151, "DSC_151_CURSO_2", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 168, "DSC_168_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 155, "DSC_155_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 142, "DSC_142_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 170, "DSC_170_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 199, "DSC_199_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 146, "DSC_146_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 103, "DSC_103_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 142, "DSC_142_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 113, "DSC_113_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 190, "DSC_190_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 7, 166, "DSC_166_CURSO_7", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 7, 121, "DSC_121_CURSO_7", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 7, 176, "DSC_176_CURSO_7", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 7, 115, "DSC_115_CURSO_7", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 7, 156, "DSC_156_CURSO_7", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 7, 170, "DSC_170_CURSO_7", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 7, 165, "DSC_165_CURSO_7", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 7, 193, "DSC_193_CURSO_7", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 7, 120, "DSC_120_CURSO_7", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 7, 163, "DSC_163_CURSO_7", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 36, 191, "DSC_191_CURSO_36", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 36, 172, "DSC_172_CURSO_36", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 36, 165, "DSC_165_CURSO_36", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 36, 131, "DSC_131_CURSO_36", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 36, 154, "DSC_154_CURSO_36", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 36, 177, "DSC_177_CURSO_36", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 36, 162, "DSC_162_CURSO_36", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 36, 191, "DSC_191_CURSO_36", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 36, 165, "DSC_165_CURSO_36", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 36, 164, "DSC_164_CURSO_36", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 22, 170, "DSC_170_CURSO_22", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 22, 114, "DSC_114_CURSO_22", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 22, 104, "DSC_104_CURSO_22", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 22, 117, "DSC_117_CURSO_22", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 22, 101, "DSC_101_CURSO_22", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 22, 138, "DSC_138_CURSO_22", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 22, 191, "DSC_191_CURSO_22", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 22, 175, "DSC_175_CURSO_22", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 22, 157, "DSC_157_CURSO_22", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 22, 148, "DSC_148_CURSO_22", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 33, 150, "DSC_150_CURSO_33", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 33, 192, "DSC_192_CURSO_33", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 33, 148, "DSC_148_CURSO_33", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 33, 123, "DSC_123_CURSO_33", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 33, 175, "DSC_175_CURSO_33", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 33, 144, "DSC_144_CURSO_33", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 33, 126, "DSC_126_CURSO_33", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 33, 125, "DSC_125_CURSO_33", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 33, 115, "DSC_115_CURSO_33", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 33, 111, "DSC_111_CURSO_33", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 10, 149, "DSC_149_CURSO_10", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 10, 127, "DSC_127_CURSO_10", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 10, 121, "DSC_121_CURSO_10", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 10, 119, "DSC_119_CURSO_10", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 10, 108, "DSC_108_CURSO_10", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 10, 155, "DSC_155_CURSO_10", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 10, 131, "DSC_131_CURSO_10", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 10, 126, "DSC_126_CURSO_10", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 10, 116, "DSC_116_CURSO_10", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 10, 148, "DSC_148_CURSO_10", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 1, 193, "DSC_193_CURSO_1", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 1, 126, "DSC_126_CURSO_1", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 1, 178, "DSC_178_CURSO_1", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 1, 184, "DSC_184_CURSO_1", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 1, 136, "DSC_136_CURSO_1", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 1, 155, "DSC_155_CURSO_1", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 1, 115, "DSC_115_CURSO_1", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 1, 194, "DSC_194_CURSO_1", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 1, 123, "DSC_123_CURSO_1", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 1, 169, "DSC_169_CURSO_1", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 33, 157, "DSC_157_CURSO_33", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 33, 177, "DSC_177_CURSO_33", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 33, 123, "DSC_123_CURSO_33", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 33, 126, "DSC_126_CURSO_33", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 33, 154, "DSC_154_CURSO_33", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 33, 163, "DSC_163_CURSO_33", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 33, 164, "DSC_164_CURSO_33", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 33, 103, "DSC_103_CURSO_33", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 33, 146, "DSC_146_CURSO_33", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 33, 173, "DSC_173_CURSO_33", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 28, 116, "DSC_116_CURSO_28", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 28, 199, "DSC_199_CURSO_28", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 28, 160, "DSC_160_CURSO_28", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 28, 160, "DSC_160_CURSO_28", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 28, 113, "DSC_113_CURSO_28", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 28, 187, "DSC_187_CURSO_28", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 28, 163, "DSC_163_CURSO_28", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 28, 117, "DSC_117_CURSO_28", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 28, 158, "DSC_158_CURSO_28", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 28, 119, "DSC_119_CURSO_28", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 32, 144, "DSC_144_CURSO_32", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 32, 113, "DSC_113_CURSO_32", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 32, 174, "DSC_174_CURSO_32", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 32, 198, "DSC_198_CURSO_32", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 32, 188, "DSC_188_CURSO_32", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 32, 128, "DSC_128_CURSO_32", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 32, 190, "DSC_190_CURSO_32", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 32, 191, "DSC_191_CURSO_32", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 32, 114, "DSC_114_CURSO_32", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 32, 107, "DSC_107_CURSO_32", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 141, "DSC_141_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 133, "DSC_133_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 116, "DSC_116_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 176, "DSC_176_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 120, "DSC_120_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 107, "DSC_107_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 116, "DSC_116_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 178, "DSC_178_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 179, "DSC_179_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 166, "DSC_166_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 23, 184, "DSC_184_CURSO_23", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 23, 169, "DSC_169_CURSO_23", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 23, 113, "DSC_113_CURSO_23", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 23, 152, "DSC_152_CURSO_23", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 23, 128, "DSC_128_CURSO_23", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 23, 168, "DSC_168_CURSO_23", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 23, 138, "DSC_138_CURSO_23", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 23, 178, "DSC_178_CURSO_23", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 23, 109, "DSC_109_CURSO_23", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 23, 193, "DSC_193_CURSO_23", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 27, 114, "DSC_114_CURSO_27", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 27, 114, "DSC_114_CURSO_27", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 27, 131, "DSC_131_CURSO_27", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 27, 175, "DSC_175_CURSO_27", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 27, 153, "DSC_153_CURSO_27", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 27, 150, "DSC_150_CURSO_27", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 27, 146, "DSC_146_CURSO_27", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 27, 178, "DSC_178_CURSO_27", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 27, 105, "DSC_105_CURSO_27", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 27, 114, "DSC_114_CURSO_27", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 40, 134, "DSC_134_CURSO_40", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 40, 141, "DSC_141_CURSO_40", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 40, 142, "DSC_142_CURSO_40", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 40, 192, "DSC_192_CURSO_40", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 40, 104, "DSC_104_CURSO_40", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 40, 115, "DSC_115_CURSO_40", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 40, 140, "DSC_140_CURSO_40", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 40, 151, "DSC_151_CURSO_40", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 40, 191, "DSC_191_CURSO_40", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 40, 182, "DSC_182_CURSO_40", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 24, 145, "DSC_145_CURSO_24", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 24, 159, "DSC_159_CURSO_24", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 24, 151, "DSC_151_CURSO_24", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 24, 165, "DSC_165_CURSO_24", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 24, 115, "DSC_115_CURSO_24", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 24, 143, "DSC_143_CURSO_24", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 24, 134, "DSC_134_CURSO_24", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 24, 122, "DSC_122_CURSO_24", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 24, 185, "DSC_185_CURSO_24", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 24, 198, "DSC_198_CURSO_24", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 127, "DSC_127_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 109, "DSC_109_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 106, "DSC_106_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 120, "DSC_120_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 196, "DSC_196_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 174, "DSC_174_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 174, "DSC_174_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 101, "DSC_101_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 180, "DSC_180_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 30, 148, "DSC_148_CURSO_30", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 175, "DSC_175_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 175, "DSC_175_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 126, "DSC_126_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 189, "DSC_189_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 127, "DSC_127_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 145, "DSC_145_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 183, "DSC_183_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 188, "DSC_188_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 119, "DSC_119_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 3, 151, "DSC_151_CURSO_3", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 32, 139, "DSC_139_CURSO_32", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 32, 163, "DSC_163_CURSO_32", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 32, 152, "DSC_152_CURSO_32", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 32, 174, "DSC_174_CURSO_32", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 32, 166, "DSC_166_CURSO_32", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 32, 174, "DSC_174_CURSO_32", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 32, 116, "DSC_116_CURSO_32", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 32, 189, "DSC_189_CURSO_32", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 32, 141, "DSC_141_CURSO_32", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 32, 139, "DSC_139_CURSO_32", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 6, 102, "DSC_102_CURSO_6", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 6, 129, "DSC_129_CURSO_6", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 6, 195, "DSC_195_CURSO_6", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 6, 157, "DSC_157_CURSO_6", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 6, 199, "DSC_199_CURSO_6", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 6, 190, "DSC_190_CURSO_6", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 6, 138, "DSC_138_CURSO_6", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 6, 138, "DSC_138_CURSO_6", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 6, 168, "DSC_168_CURSO_6", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 6, 189, "DSC_189_CURSO_6", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 21, 179, "DSC_179_CURSO_21", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 21, 117, "DSC_117_CURSO_21", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 21, 115, "DSC_115_CURSO_21", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 21, 107, "DSC_107_CURSO_21", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 21, 165, "DSC_165_CURSO_21", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 21, 161, "DSC_161_CURSO_21", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 21, 179, "DSC_179_CURSO_21", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 21, 105, "DSC_105_CURSO_21", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 21, 154, "DSC_154_CURSO_21", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 21, 152, "DSC_152_CURSO_21", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 21, 121, "DSC_121_CURSO_21", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 21, 183, "DSC_183_CURSO_21", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 21, 177, "DSC_177_CURSO_21", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 21, 188, "DSC_188_CURSO_21", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 21, 164, "DSC_164_CURSO_21", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 21, 172, "DSC_172_CURSO_21", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 21, 182, "DSC_182_CURSO_21", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 21, 136, "DSC_136_CURSO_21", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 21, 159, "DSC_159_CURSO_21", 6, 60);
        AdicionarDsc_em_curso(&arvoreCursos, 21, 149, "DSC_149_CURSO_21", 6, 60);
    }
    //-----------------------------------------------
    // Obtém o tempo final
    QueryPerformanceCounter(&fim);

    // Calcula o tempo total em milissegundos
    tempo_total = (double)(fim.QuadPart - inicio.QuadPart) / frequencia.QuadPart * 1000;

    // Exibe o tempo total de preenchimento da árvore
    printf("Tempo total de adicao de Disciplinas: %.5f milissegundos\n", tempo_total);

    int opcao = -1;

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
            ExibirDados_Curso(arvoreCursos, codigo);
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
            RemoverCurso(&arvoreCursos, codigo);
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
                // Obtém a frequência do contador de performance
                QueryPerformanceFrequency(&frequencia);

                // Obtém o tempo inicial
                QueryPerformanceCounter(&inicio);

                double tempo;

                AdicionarCurso(&arvoreCursos, codigo_curso, nome_curso, bloco_curso, semana_curso);
                printf("CURSO ADICIONADO COM SUCESSO!!!\n");
                // Obtém o tempo final
                QueryPerformanceCounter(&fim);

                // Calcula o tempo total em milissegundos
                tempo_total = (double)(fim.QuadPart - inicio.QuadPart) / frequencia.QuadPart * 1000;

                // Exibe o tempo total de preenchimento da árvore
                printf("Tempo para Adicao de Cursos: %.5f milissegundos\n", tempo_total);
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
                scanf(" %d",&codigo_dsc);
                printf("Digite a cargahoraria da Discplina: ");
                scanf(" %d",&cargahorario_dsc);
                printf("Digite o bloco da Disciplina: ");
                scanf(" %d",&bloco_dsc);

                 // Obtém a frequência do contador de performance
                QueryPerformanceFrequency(&frequencia);

                // Obtém o tempo inicial
                QueryPerformanceCounter(&inicio);

                AdicionarDsc_em_curso(&arvoreCursos,codigo_curso,codigo_dsc,nome_dsc,bloco_dsc,cargahorario_dsc);

                QueryPerformanceCounter(&fim);

                // Calcula o tempo total em milissegundos
                tempo_total = (double)(fim.QuadPart - inicio.QuadPart) / frequencia.QuadPart * 1000;

                // Exibe o tempo total de preenchimento da árvore
                printf("Tempo para Adicao de Disciplina: %.5f milissegundos\n", tempo_total);
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
