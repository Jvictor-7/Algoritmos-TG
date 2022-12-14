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
            if (strcmp(argv[i + 1], "-s") == 0){
                inpt = i + 2;
            }
            else{
                inpt = i + 1;
            }
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
    // ImprimeMatriz(qtd_V, matriz_adj);

    int distancia[qtd_V], prev[qtd_V];

    // --- Chamando o algoritmo de Dijkstra ---
    dijkstra(qtd_V, matriz_adj, vertInicial, distancia, prev);

    // --- SAÍDA ---
    if (output != 0)
    {
        FILE *saida = fopen(argv[output], "w");
        if (vertFinal != 0)
        {
            fprintf(saida, "%d", distancia[vertFinal - 1]);
            if(soluc == TRUE){
                int indPai = vertFinal - 1;
                while (prev[indPai] != -1)
                {
                    fprintf(saida, " ");
                    fprintf(saida ,"(%d, %d)", indPai + 1, prev[indPai] + 1);
                    indPai = prev[indPai];
                }
            }
            
        }
        if (vertFinal == 0 && vertInicial != 0)
        {
            for (int i = 0; i < qtd_V; i++)
            {
                fprintf(saida, "%d:%d", i + 1, distancia[i]);
                if(soluc == TRUE){
                    int indPai = i;
                    while (prev[indPai] != -1)
                    {
                        fprintf(saida, " ");
                        fprintf(saida, "(%d, %d)", indPai + 1, prev[indPai] + 1);
                        indPai = prev[indPai];
                    }
                    if(i + 1 != qtd_V){
                        fprintf(saida, "\n");
                    }
                }
                else{
                    if(i+1 != qtd_V){
                        fprintf(saida, " ");
                    }
                }
            }
        }
        fclose(saida);
    }
    else
    {
        if (vertFinal != 0)
        {
            printf("%d\n", distancia[vertFinal - 1]);
            if(soluc == TRUE){
                int indPai = vertFinal - 1;
                while (prev[indPai] != -1)
                {
                    printf(" ");
                    printf("(%d, %d)", indPai + 1, prev[indPai] + 1);
                    indPai = prev[indPai];
                }
                printf("\n");
            }
        }
        else if (vertFinal == 0 && vertInicial != 0)
        {
            for (int i = 0; i < qtd_V; i++)
            {
                printf("%d:%d", i + 1, distancia[i]);
                if(soluc == TRUE){
                    int indPai = i;
                    while (prev[indPai] != -1)
                    {
                        printf(" ");
                        printf("(%d, %d)", indPai + 1, prev[indPai] + 1);
                        indPai = prev[indPai];
                    }
                    printf("\n");
                }

                if(i + 1 != qtd_V){
                    printf("\n");
                }
                
            }
        }
    }
     
    return 0;
}