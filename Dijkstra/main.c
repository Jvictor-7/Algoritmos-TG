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
            inpt = i + 1;
        }
        else if(strcmp(argv[i], "-s") == 0){
            soluc = TRUE;
        }
        else if(strcmp(argv[i], "-i") == 0){
            sscanf(argv[i + 1], "%d", &vertInicial);
        }
        else if(strcmp(argv[i], "-l") == 0){
            sscanf(argv[i + 1], "%d", &vertFinal);
        }
    }

    printf(" vert inicial = %d\n", vertInicial);

    // --- ENTRADA ---
    int qtd_V, qtd_A;
    FILE *entrada;

    entrada = fopen(argv[inpt], "r");

    fscanf(entrada, "%d%d", &qtd_V, &qtd_A);

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

    while(!feof(entrada)){
            int peso, vert_inic, vert_fim;
            char peso_c;

            fscanf(entrada, "%i%i", &vert_inic, &vert_fim);

            fscanf(entrada, "%c", &peso_c);

            if (peso_c == '\n') peso = 1;
            else fscanf(entrada, "%i", &peso);

            // --- Atribuindo pesos as arestas e formando o grafo ---
            matriz_adj[vert_inic-1][vert_fim-1] = peso;
            matriz_adj[vert_fim-1][vert_inic-1] = peso;    
    }

    fclose(entrada);

    // --- Imprimindo matriz ---
    ImprimeMatriz(qtd_V, matriz_adj);

    // --- Chamando o algoritmo de Dijkstra ---
    dijkstra(qtd_V, matriz_adj,3);





    // --- SAÍDA ---
    FILE *out = fopen(argv[output], "w");
    fprintf(out, "okei");
    fclose(out);
    
    return 0;
}