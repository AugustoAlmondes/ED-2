#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{
    // Obter o ID do processo
    pid_t pid = getpid();

    // Obter o tempo atual
    time_t current_time = time(NULL);

    // Calcular a semente combinando o ID do processo e o tempo atual
    unsigned int seed = (unsigned int)(current_time + pid);

    // Inicializar a semente
    srand(seed);

    const int num_numeros = 42;
    int numeros_gerados[num_numeros];

    // Inicializar o vetor com valores inválidos
    for (int i = 0; i < num_numeros; i++)
    {
        numeros_gerados[i] = -1;
    }

    int numeros_gerados_count = 0;

    // Gerar números aleatórios
    while (numeros_gerados_count < num_numeros)
    {
        int numero = rand() % num_numeros;

        // Verificar se o número já foi gerado
        int repetido = 0;
        for (int i = 0; i < numeros_gerados_count; i++)
        {
            if (numeros_gerados[i] == numero)
            {
                repetido = 1;
                break;
            }
        }
        if (!repetido)
        {
            numeros_gerados[numeros_gerados_count] = numero;
            numeros_gerados_count++;
            printf("AdicionarCurso(&arvoreCursos, %d, \"Curso %d\", 8, 16);\n", numero, numero);
        }
    }
    return 0;
}