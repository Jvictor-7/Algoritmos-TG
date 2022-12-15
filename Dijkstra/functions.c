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

//Parâmetros de entrada: -i -s
int dijkstra(int qtd_V, int grafo[qtd_V][qtd_V], int vert_origem){
    int distancia[qtd_V], prev[qtd_V];

    for (int i = 0; i < qtd_V; i++) distancia[i] = INFINITO;

    int heapLenght = qtd_V;
    int *tam = (int *)malloc(sizeof(int));
    Heap *H = (Heap *)malloc(sizeof(Heap)*heapLenght);
    H[0] = vert_origem;

    distancia[vert_origem - 1] = 0;
    prev[vert_origem - 1] = 0;

    for (int i = 0; i < qtd_V; i++) prev[i] = -1;

    printf("\n");
    for(int i = 0;i < qtd_V; i++){
        printf("%d ",distancia[i]);
    }
    printf("\n");
    for(int i = 0;i < qtd_V; i++){
        printf("%d ",i + 1);
    }
    printf("\n");

    printf("\n");
    for(int i = 0;i < qtd_V; i++){
        printf("%d ",prev[i]);
    }
    printf("\n");
    for(int i = 0;i < qtd_V; i++){
        printf("%d ",i + 1);
    }
    printf("\n");
    

    return 0;
}
