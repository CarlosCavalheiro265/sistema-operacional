#Bibliotecas usadas
import threading
import random

#função que soma os vetores
def soma_vetores(A, B, C, inicio, fim):
    for aux in range(inicio, fim): #loop para percorrer o vetor
        C[aux] = A[aux] + B[aux] #multiplicação dos índices

def main():
    Tamanho = int(input("Tamanho dos vetores: ")) #Atribuição do tamanho dos vetores
    N_threads = int(input("Número de threads: ")) #Atribuição do número de Threads
    A = [random.randint(0, 100) for _ in range(Tamanho)] #Criação do Vetor A do tamanho solicitado e com números aleátorios entre 0 e 100
    B = [random.randint(0, 100) for _ in range(Tamanho)] #Criação do Vetor B do tamanho solicitado e com números aleátorios entre 0 e 100
    C = [0] * Tamanho #Criação do Vetor C do tamanho solicitado e com números zeros
    print("Vetor A:",A) #print para mostrar o vetor A
    print("Vetor B:",B) #print para mostrar o vetor B

    tamanho_pedaco = Tamanho // N_threads #Definição do tamanho de operações que cada thread vai executar

    threads = [] #Criação do vetor das Threads
    for aux in range(N_threads): #loop de execução
        inicio = aux * tamanho_pedaco #Definição da thread que sera executada primeiro
        fim = Tamanho if aux == N_threads - 1 else (aux + 1) * tamanho_pedaco #Definição da thread que será executada por último e teste para confirmar que todas serão executadas independente da divisão 
        thread = threading.Thread(target=soma_vetores, args=(A, B, C, inicio, fim))# Execução das operações
        threads.append(thread) #adição da thread no Vetor
        thread.start() #Start das threads

    #loop para garantir que todas threads tenham sido terminadas
    for thread in threads:
        thread.join()

    print("Vetor C:",C)#print do resultado

main()#chamada da função main