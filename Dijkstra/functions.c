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

void init_(Heap *arr, int qtd_V, int distancia[], int prev[], int origem){
    for (int i = 0; i < qtd_V; i++)
    {
        distancia[i] = INFINITO;
        prev[i] = -1;
    }
    distancia[origem] = 0;
    
}

void relaxar(int qtd_V ,int matriz_adj[][qtd_V], int distancia[], int prev[], int v_atual, int v_alvo){

    if(distancia[v_alvo] > distancia[v_atual] + matriz_adj[v_atual][v_alvo]){
        distancia[v_alvo] = distancia[v_atual] + matriz_adj[v_atual][v_alvo];
        prev[v_alvo] =  v_atual;
    }
}
 
// Algoritmo de Dijkstra
int dijkstra(int qtd_V, int matriz_adj[qtd_V][qtd_V], int vert_origem){

    int distancia[qtd_V], prev[qtd_V];

    int heapLenght = qtd_V;

    int *tam = (int *)malloc(sizeof(int));
    *tam = 0;
    Heap *H = (Heap *)malloc(sizeof(Heap)*heapLenght);

    initHeap(H, qtd_V, vert_origem, tam);
    init_(H, qtd_V, distancia, prev, vert_origem - 1);
         

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
                printf("\n\n--- vert %d vai para %d\n\n", vertAtual+1, i+1);
                
                if(distancia[i] > distancia[vertAtual] + matriz_adj[vertAtual][i]){
                    distancia[i] = distancia[vertAtual] + matriz_adj[vertAtual][i];
                    prev[i] = vertAtual;
                    mudarPrioridade(H,i, distancia[i]);     
                }

                printf("SOMA DIST\n\n\n");
                for (int j = 0; j < qtd_V; j++)
                {
                    printf("%d ", distancia[j]);
                }
                
            }
        }
        
    }
        printf("LISTA PREV\n\n");
        for (int i = 0; i < qtd_V; i++)
        {
            printf("%d ", prev[i] + 1);
        }
        printf("\n");
    return 0;
}
