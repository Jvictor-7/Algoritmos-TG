#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"
#include "functions.c"
#include "heap.h"
#include "heap.c"

#define TRUE 1
#define FALSE 0

typedef int bool;

int main(int arg, char *argv[]){

    int output = 0, inpt = 0, vertInicial = 0, vertFinal = 0;

    bool soluc = FALSE;

    for (int i = 0; i < arg; i++)
    {
        if(strcmp(argv[i], "-h") == 0){
            help();
            return 0;
        }
        else if(strcmp(argv[i], "-o") == 0){
            output = i + 1;
        }
        else if(strcmp(argv[i], "-f") == 0){
            printf("teste %s\n", argv[i + 1]);

            inpt = i + 1;
        }
        else if(strcmp(argv[i], "-s") == 0){
            soluc = TRUE;
        }
        else if(strcmp(argv[i], "-i") == 0){
            printf("teste %s\n", argv[i + 1]);
            // vertInicial = argv[i+1] - '0';
        }
        else if(strcmp(argv[i], "-l") == 0){
            printf("teste %s\n", argv[i + 1]);

            // vertFinal = argv[i+1];
        }
    }

    // --- ENTRADA ---
    int qtd_V, qtd_A;
    FILE *G;

    G = fopen(argv[inpt], "r");

    fscanf(G, "%d%d", &qtd_V, &qtd_A);

    // --- CRIANDO MATRIZ DE ADJ ---
    int matriz_adj[qtd_V][qtd_V];

    // --- ATRIBUINDO VALORES NA MATRIZ COMO 0 ---
    for (int j = 0; j < qtd_V; j++)
    {
        for (int k = 0; k < qtd_V; k++)
        {
            matriz_adj[j][k] = 0;
        }
    }

    while(!feof(G)){
            int peso, vert_inic, vert_fim;
            char peso_c;

            fscanf(G, "%i%i", &vert_inic, &vert_fim);

            fscanf(G, "%c", &peso_c);

            if (peso_c == '\n') peso = 1;
            else fscanf(G, "%i", &peso);

            // --- Atribuindo pesos as arestas e formando o grafo ---
            matriz_adj[vert_inic-1][vert_fim-1] = peso;
            matriz_adj[vert_fim-1][vert_inic-1] = peso;    
    }

    fclose(G);

    // --- Imprimindo matriz ---
    ImprimeMatriz(qtd_V, matriz_adj);

    // --- Chamando o algoritmo de Dijkstra ---
    dijkstra(qtd_V, matriz_adj, 1);




    // --- SAÍDA ---
    FILE *out = fopen(argv[output], "w");
    fprintf(out, "okei");
    fclose(out);
    
    return 0;
}