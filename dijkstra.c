#include <stdio.h>
#include <stdlib.h>

#define LONGINT

// Função de imprimir matriz
 void ImprimeMatriz(int qtd_V, int matriz[qtd_V][qtd_V]){
    for(int i = 0;i < qtd_V; i++){
        for(int j = 0;j < qtd_V; j++){
            printf("\t%d",matriz[i][j]);
        }
        printf("\n");
    }
 }

// Algoritmo de Dijkstra
int dijkstra(int qtd_V, int grafo[qtd_V][qtd_V], int vert_origem){
    int distancia[qtd_V], prev[qtd_V];

    for (int i = 0; i < qtd_V; i++) distancia[i] = 999;

    distancia[vert_origem - 1] = 0;

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

int main()
{
    FILE *file;
    file = fopen("entrada.txt", "r");

    int qtd_V, qtd_A;

    fscanf(file, "%d%d", &qtd_V, &qtd_A);

    // Criando matriz de adjacência
    int matriz_adj[qtd_V][qtd_V];

    // Atribuindo valores da matriz como 0
    for (int j = 0; j < qtd_V; j++)
    {
        for (int k = 0; k < qtd_V; k++)
        {
            matriz_adj[j][k] = 0;
        }
    }

    while(!feof(file)){
            int peso, vert_inic, vert_fim;
            char peso_c;

            fscanf(file, "%i%i", &vert_inic, &vert_fim);

            fscanf(file, "%c", &peso_c);

            if (peso_c == '\n') peso = 1;
            else fscanf(file, "%i", &peso);

            // Atribuindo pesos as arestas e formando o grafo
            matriz_adj[vert_inic-1][vert_fim-1] = peso;
            matriz_adj[vert_fim-1][vert_inic-1] = peso;    
    }

    fclose(file);

    // Imprimindo matriz
    ImprimeMatriz(qtd_V, matriz_adj);

    // Chamando o algoritmo de Dijkstra
    dijkstra(qtd_V, matriz_adj, 1);

    return 0;
}
