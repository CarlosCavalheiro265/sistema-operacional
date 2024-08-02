/* bibliotecas necessárias para executar o algoritmo */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/* Trabalho de Criação de Processos, Aluno: Carlos Eduardo dos Santos Cavalheiro 118302 */

/* função que faz a sequência de Collatz */
void collatz(int x) {
    printf("Sequência de Collatz para o número %d = ", x);
    while (x != 1) {
        printf("%d ", x);
        if (x % 2 == 0) {
            x = x / 2;
        } else {
            x = 3 * x + 1;
        }
    }
    printf("\n");
}

int main(){
    /* definição da variável de quantos processos serão feitos*/
    int processos;

    printf("Número de processos = ");
    scanf("%d", &processos);

    /* loop para pegar os valres de ID de cada processo e realizar a sequência de collatz */
    for (int cont = 0; cont < processos; cont++) {
        pid_t pid = fork();

        if (pid == 0) {
            pid_t my_pid = getpid();
            
            int x = (my_pid / 10) % 100;
            if (x == 0) {
                x = 1;
            }
            
            printf("Processo filho com PID = %d, número para Collatz: %d\n", my_pid, x);
            
            collatz(x);
            
            _exit(0); 

        }
    }

    /* teste para ver quando os processos filho terminaram */
    for (int cont = 0; cont < processos; cont++) {
        wait(NULL);
    }

    printf("Todos os processos filhos terminaram.\n");

    return 0;
}
