#include "functions.h"
#include "heap.h"

void help(){
    printf("help\n");
}

// Função de imprimir matriz
void ImprimeMatriz(int qtd_V, int matriz[qtd_V][qtd_V]){
    for(int i = 0;i < qtd_V; i++){
        for(int j = 0;j < qtd_V; j++){
            printf("\t%d",matriz[i][j]);
        }
        printf("\n");
    }
}

<<<<<<< HEAD
//Parâmetros de entrada: -i -s
int dijkstra(int qtd_V, int grafo[qtd_V][qtd_V], int vert_origem){
    int distancia[qtd_V], prev[qtd_V];

    for (int i = 0; i < qtd_V; i++) distancia[i] = INFINITO;
=======
void init_(Heap *arr, int qtd_V, int distancia[], int prev[], int origem){
    for (int i = 0; i < qtd_V; i++)
    {
        distancia[i] = INFINITO;
        prev[i] = -1;
    }
    distancia[origem] = 0;
    
}
 
// Algoritmo de Dijkstra
int dijkstra(int qtd_V, int matriz_adj[qtd_V][qtd_V], int vert_origem, int distancia[], int prev[]){
>>>>>>> 3f542acfdc4f938d973d0e80649940dae339a97a

    int heapLenght = qtd_V;

    int *tam = (int *)malloc(sizeof(int));
    *tam = 0;
    Heap *H = (Heap *)malloc(sizeof(Heap)*heapLenght);
    H[0] = vert_origem;

<<<<<<< HEAD
    distancia[vert_origem - 1] = 0;
    prev[vert_origem - 1] = 0;
=======
    initHeap(H, qtd_V, vert_origem, tam);
    init_(H, qtd_V, distancia, prev, vert_origem - 1);
         
>>>>>>> 3f542acfdc4f938d973d0e80649940dae339a97a

    while (*tam != 0)
    {
        if(H[0].prioridade == MIN_PRIORITY){
            printf("grafo desconexo\n");
            break;
        }

        int vertAtual = maiorPrioridade(H) - 1;

        extrairMin(H, tam);

        for (int i = 0; i < qtd_V; i++)
        {
            if(matriz_adj[vertAtual][i] != 0){             
                if(distancia[i] > distancia[vertAtual] + matriz_adj[vertAtual][i]){
                    distancia[i] = distancia[vertAtual] + matriz_adj[vertAtual][i];
                    prev[i] = vertAtual;
                    mudarPrioridade(H,i, distancia[i]);     
                }        
            }
        }
        
    }
    return 0;
}
