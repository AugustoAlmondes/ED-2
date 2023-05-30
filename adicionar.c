    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include "curso.h"

    Curso *adcCurso()
    {

        Curso *arvoreCursos;

        AdicionarCurso(&arvoreCursos, 7, "Curso 7", 8, 16);
        AdicionarCurso(&arvoreCursos, 29, "Curso 29", 10, 18);
        AdicionarCurso(&arvoreCursos, 2, "Curso 2", 10, 18); // Preenchidio
        AdicionarCurso(&arvoreCursos, 19, "Curso 19", 10, 18);
        AdicionarCurso(&arvoreCursos, 26, "Curso 26", 10, 18);
        AdicionarCurso(&arvoreCursos, 3, "Curso 3", 8, 16);
        AdicionarCurso(&arvoreCursos, 18, "Curso 18", 8, 16);
        AdicionarCurso(&arvoreCursos, 14, "Curso 14", 10, 18);
        AdicionarCurso(&arvoreCursos, 1, "Curso 1", 10, 18);
        AdicionarCurso(&arvoreCursos, 25, "Curso 25", 8, 16);
        AdicionarCurso(&arvoreCursos, 16, "Curso 16", 8, 16);
        AdicionarCurso(&arvoreCursos, 5, "Curso 5", 8, 16);
        AdicionarCurso(&arvoreCursos, 4, "Curso 4", 10, 18); // Preenchidio
        AdicionarCurso(&arvoreCursos, 22, "Curso 22", 8, 16);
        AdicionarCurso(&arvoreCursos, 27, "Curso 27", 10, 18);
        AdicionarCurso(&arvoreCursos, 6, "Curso 6", 8, 16);
        AdicionarCurso(&arvoreCursos, 9, "Curso 9", 10, 18);
        AdicionarCurso(&arvoreCursos, 8, "Curso 8", 8, 16);
        AdicionarCurso(&arvoreCursos, 10, "Curso 10", 10, 18);
        AdicionarCurso(&arvoreCursos, 11, "Curso 11", 8, 16);
        AdicionarCurso(&arvoreCursos, 15, "Curso 15", 10, 18);
        AdicionarCurso(&arvoreCursos, 13, "Curso 13", 8, 16);
        AdicionarCurso(&arvoreCursos, 12, "Curso 12", 8, 16);
        AdicionarCurso(&arvoreCursos, 17, "Curso 17", 10, 18);
        AdicionarCurso(&arvoreCursos, 24, "Curso 24", 10, 18);
        AdicionarCurso(&arvoreCursos, 21, "Curso 21", 8, 16);
        AdicionarCurso(&arvoreCursos, 23, "Curso 23", 10, 18);
        AdicionarCurso(&arvoreCursos, 30, "Curso 30", 8, 16);
        AdicionarCurso(&arvoreCursos, 28, "Curso 28", 8, 16);
        AdicionarCurso(&arvoreCursos, 20, "Curso 20", 10, 18);

        return arvoreCursos;
    }

    Curso *adcDsc()
    {
        Curso *arvoreCursos;
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
        return arvoreCursos;
    }