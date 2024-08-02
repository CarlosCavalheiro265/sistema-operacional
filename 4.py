#Bibliotecas usadas
import threading
import random

def multiplicar(A, B, C, linha_i, linha_f, coluna_a, coluna_b):
    for aux_1 in range(linha_i, linha_f):
        for aux_2 in range(coluna_b):
            C[aux_1][aux_2] = sum(A[aux_1][k] * B[k][aux_2] for k in range(coluna_a))

def main():
    #Definição dos valores dos tamanhos das matrizes e número de threads além da criação das matrizes A e B com números aleatórios
    linha_a = int(input("Número de linhas da matriz A: "))
    coluna_a = int(input("Número de colunas da matriz A: "))
    print("Número de linhas da matriz B precisa ser igual o número de colunas da matrix A")
    coluna_b = int(input("Número de colunas da matriz B: "))
    N_threads = int(input("Número de threads: "))

    A = [[random.randint(0, 10) for _ in range(coluna_a)] for _ in range(linha_a)]
    B = [[random.randint(0, 10) for _ in range(coluna_b)] for _ in range(coluna_a)]
    C = [[0 for _ in range(coluna_b)] for _ in range(linha_a)]

    #Prints das matrizes iniciais
    print("Matriz A:")
    for linha in A:
        print(linha)
    
    print("Matriz B:")
    for linha in B:
        print(linha)

    linhas_por_thread = linha_a // N_threads #Definição do tamanho de operações que cada thread vai executar

    threads = []#Criação do vetor das Threads

    #loop de execução definindo o valor da operação inicial e final além do teste para confirmar que todas serão executadas independente da divisão e pro fim execução da operação
    for aux in range(N_threads):
        linha_i = aux * linhas_por_thread
        linha_f = linha_a if aux == N_threads - 1 else (aux + 1) * linhas_por_thread
        thread = threading.Thread(target=multiplicar, args=(A, B, C, linha_i, linha_f, coluna_a, coluna_b))
        threads.append(thread)
        thread.start()

    #loop para garantir que todas threads tenham sido terminadas
    for thread in threads:
        thread.join()

    #print do Resultado
    print("Matriz do produto:")
    for linha in C:
        print(linha)

main()