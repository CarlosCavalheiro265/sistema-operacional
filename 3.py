#Bibliotecas usadas
import threading
import random

#função que percorre as linhas e colunas trocando os valores entre sí para deixar a matriz transposta
def transposição(A, B, linha_i, linha_f, N_coluna):
    for aux_linha in range(linha_i, linha_f):
        for aux_coluna in range(N_coluna):
            B[aux_coluna][aux_linha] = A[aux_linha][aux_coluna]

def main():
    #Definição dos valores dos tamanhos das matrizes e número de threads além da criação da matriz A com números aleatórios e da B zerada
    N_Linha = int(input("Número de linhas das matrizes: "))
    N_coluna = int(input("Número de colunas das matrizes: "))
    N_threads = int(input("Número de threads: "))
    A = [[random.randint(0, 100) for _ in range(N_coluna)] for _ in range(N_Linha)]
    B = [[0 for _ in range(N_Linha)] for _ in range(N_coluna)]

    #Print da Matriz A
    print("Matriz A:")
    for linha in A:
        print(linha)

    linhas_por_thread = N_Linha // N_threads #Definição do tamanho de operações que cada thread vai executar

    threads = []#Criação do vetor das Threads
    
    #loop de execução definindo o valor da operação inicial e final além do teste para confirmar que todas serão executadas independente da divisão e pro fim execução da operação
    for aux in range(N_threads):
        linha_i = aux * linhas_por_thread
        linha_f = N_Linha if aux == N_threads - 1 else (aux + 1) * linhas_por_thread
        thread = threading.Thread(target=transposição, args=(A, B, linha_i, linha_f, N_coluna))
        threads.append(thread)
        thread.start()

    #loop para garantir que todas threads tenham sido terminadas
    for thread in threads:
        thread.join()

    #Print do resultado
    print("Matriz B:")
    for linha in B:
        print(linha)

main()