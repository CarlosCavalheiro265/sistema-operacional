#Bibliotecas usadas
import threading
import random


def soma(A, B, C, linha_i, linha_f, N_coluna):#função da soma das matrizes
    for aux_linha in range(linha_i, linha_f):#loop para percorrer as linhas
        for aux_coluna in range(N_coluna): #loop para percorrer as colunas
            C[aux_linha][aux_coluna] = A[aux_linha][aux_coluna] + B[aux_linha][aux_coluna] #Soma dos valores em cada matriz 

def main():
    #atribuições dos tamanhos das matrizes e número de threads
    N_Linha = int(input("Número de linhas das matrizes: "))
    N_coluna = int(input("Número de colunas das matrizes: "))
    N_threads = int(input("Número de threads: "))

    #Criação das matrizes no tamanho solicitado e com números aleatórios e da matriz C zerada
    A = [[random.randint(0, 100) for _ in range(N_coluna)] for _ in range(N_Linha)]
    B = [[random.randint(0, 100) for _ in range(N_coluna)] for _ in range(N_Linha)]
    C = [[0 for _ in range(N_coluna)] for _ in range(N_Linha)]

    #print das matrizes
    print("Matriz A:")
    for linha in A:
        print(linha)
    
    print("Matriz B:")
    for linha in B:
        print(linha)

    #cálculo de numero de linhas executada por cada thread
    linhas_por_thread = N_Linha // N_threads

    #criação da lista de threads
    threads = []
    #loop de execução
    for aux in range(N_threads):
        linha_i = aux * linhas_por_thread #Definição da linha inicial da operação
        linha_f = N_Linha if aux == N_threads - 1 else (aux + 1) * linhas_por_thread #Definição da linha final da operação e teste para garantir que todas sejem executadas independente do valor da divisão
        thread = threading.Thread(target=soma, args=(A, B, C, linha_i, linha_f, N_coluna))#Exucução da operação
        threads.append(thread)#Adição da thread na lista
        thread.start()#star da thread

    #loop para garantir que todas threads tenham sido terminadas
    for thread in threads:
        thread.join()

    #Print do resultado
    print("Matriz C:")
    for linha in C:
        print(linha)

main()#chamada da função main