/* bibliotecas necessárias para executar o algoritmo */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>

/* Trabalho de Criação de Processos, Aluno: Carlos Eduardo dos Santos Cavalheiro 118302 */

/* função que multiplica os vetores */
void multiplicacao(int* vetor_1, int* vetor_2, int* Vetor_resultado, int Tamanho) {
    for (int cont = 0; cont < Tamanho; cont++) {
        Vetor_resultado[cont] = vetor_1[cont] * vetor_2[cont];
    }
}

/* função que subtrai os vetores */
void subtracao(int* vetor_1, int* vetor_2, int* Vetor_resultado, int Tamanho) {
    for (int cont = 0; cont < Tamanho; cont++) {
        Vetor_resultado[cont] = vetor_1[cont] - vetor_2[cont];
    }
}

/* função que soma os vetores */
void adicao(int* vetor_1, int* vetor_2, int* Vetor_resultado, int Tamanho) { 
    for (int cont = 0; cont < Tamanho; cont++) {
        Vetor_resultado[cont] = vetor_1[cont] + vetor_2[cont];
    }
}

int main(){
    bool pai, filho;
    /* definição da variável que define o tamanho dos vetores */
    int Tamanho;

    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &Tamanho);

    /* criação dos vetores no tamanho definido anteriormente e com valores aleatórios entre 1 e 15 */
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

    if (pid == 0) {
        /* função para retornar o valor do id para para o teste de ser par ou impar e depois para saber se é preciso esperar ou não o processo filho */
        pid_t parent_id = getppid();
        printf("\nPID filho= %d, PID pai= %d\n", getpid(), parent_id);

        filho = (getpid() % 2 == 0);
        pai = (parent_id % 2 == 0);
        printf("\nfilho= %d, pai= %d\n", filho, pai);

        /* testes para saber qual caso é necessário executar dependendo se os valores são pares ou ímpares */
        if (pai && filho) {
            printf("\nAmbos IDs pares, multiplicando os vetores");
            multiplicacao(Vetor_1, Vetor_2, Vetor_resultado, Tamanho);
            sleep(3);
            printf("\nVetor resultante: ");
            for (int cont = 0; cont < Tamanho; cont++) {
                printf("%d ", Vetor_resultado[cont]);
            }
        }
        else if (!pai && !filho) {
            printf("\nAmbos IDs ímpares, subtraindo os vetores");
            subtracao(Vetor_1, Vetor_2, Vetor_resultado, Tamanho);
            sleep(3);
            printf("\nVetor resultante: ");
            for (int cont = 0; cont < Tamanho; cont++) {
                printf("%d ", Vetor_resultado[cont]);
            }
        }
        else if (!pai && filho) {
            printf("\nPai ímpar e filho par, somando vetores");
            adicao(Vetor_1, Vetor_2, Vetor_resultado, Tamanho);
            sleep(3);
            printf("\nVetor resultante: ");
            for (int cont = 0; cont < Tamanho; cont++) {
                printf("%d ", Vetor_resultado[cont]);
            }
        }
        else if (pai && !filho) {
            printf("\nPai par e filho ímpar, realizando todas as operações");
            multiplicacao(Vetor_1, Vetor_2, Vetor_resultado, Tamanho);
            sleep(3);
            printf("\nVetor resultante da multiplicação: ");
            for (int cont = 0; cont < Tamanho; cont++) {
                printf("%d ", Vetor_resultado[cont]);
            }
            subtracao(Vetor_1, Vetor_2, Vetor_resultado, Tamanho);
            sleep(3);
            printf("\nVetor resultante da subtração: ");
            for (int cont = 0; cont < Tamanho; cont++) {
                printf("%d ", Vetor_resultado[cont]);
            }
            adicao(Vetor_1, Vetor_2, Vetor_resultado, Tamanho);
            sleep(3);
            printf("\nVetor resultante da adição: ");
            for (int cont = 0; cont < Tamanho; cont++) {
                printf("%d ", Vetor_resultado[cont]);
            }
        }

        _exit(0);

    }

    /* testes para ver quando o processo filho foi terminado e se é necessário esperar */
    else if (pid > 0){
        printf("\nIniciando processo Pai");
        if (pid % 2 == 0) {
            printf("\nProcesso pai aguardando o filho");
            wait(NULL);
        }
        printf("\nProcesso pai encerrado");
    }

    free(Vetor_1);
    free (Vetor_2);
    free(Vetor_resultado);

    return 0;
}
