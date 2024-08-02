/* bibliotecas necessárias para executar o algoritmo */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/* Trabalho de Criação de Processos, Aluno: Carlos Eduardo dos Santos Cavalheiro 118302 */

/* função que multiplica os vetores */
void multiplicação(int* vetor_1, int* vetor_2, int* Vetor_resultado, int Tamanho) {
    for (int cont = 0; cont < Tamanho; cont++) {
        Vetor_resultado[cont] = vetor_1[cont] * vetor_2[cont];
    }
}

int main() {
    /* definição da variável que define o tamanho dos vetores */
    int Tamanho;

    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &Tamanho);

    /* criação dos vetores no tamanho definido anteriormente e com velores aleatórios entre 1 e 15 */
    int* Vetor_1 = malloc(Tamanho * sizeof(int));
    int* Vetor_2 = malloc(Tamanho * sizeof(int));
    int* Vetor_resultado = malloc(Tamanho * sizeof(int));

    for (int cont = 0; cont < Tamanho; cont++) {
        Vetor_1[cont] = rand() % 15 + 1; 
        Vetor_2[cont] = rand() % 15 + 1;
    }

    printf("Vetor 1: ");
    for (int cont = 0; cont < Tamanho; cont++) {
            printf("%d ", Vetor_1[cont]);
        }
    printf("\n");
    printf("Vetor 2: ");
    for (int cont = 0; cont < Tamanho; cont++) {
            printf("%d ", Vetor_2[cont]);
        }
    printf("\n");

    /* criação do pid */
    pid_t pid = fork();

    /* teste para valdiar valor do pid e realizar o exercício */
    if (pid == 0) {
        printf("Iniciando o processo filho\n");
        printf("Multiplicando vetores");
        multiplicação(Vetor_1, Vetor_2, Vetor_resultado, Tamanho);
        sleep(3);
        printf("\nVetor resultante: ");
        for (int cont = 0; cont < Tamanho; cont++) {
            printf("%d ", Vetor_resultado[cont]);
        }
        printf("\n");

    /* teste para saber o quanto o processo pai precisa esperar o filho ser executado */
    } else if (pid > 0) {
        printf("Processo pai aguardando\n");

        /* função para determinar o fim do processo filho */
        wait(NULL);

        printf("Processo filho executado");
        printf("\nEncerrando processo Pai");

    } 

    /* liberação do espaço de memória dos vetores */
    free(Vetor_1);
    free(Vetor_2);
    free(Vetor_resultado);

    return 0;
}