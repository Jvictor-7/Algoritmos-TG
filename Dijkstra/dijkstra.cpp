#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *file;
    file = fopen("entrada.txt", "r");

    int qtd_V, qtd_A;

    fscanf(file, "%d%d", &qtd_V, &qtd_A);

    int matriz_adj[qtd_V][qtd_V];

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
            
            matriz_adj[vert_inic-1][vert_fim-1] = peso;
            matriz_adj[vert_fim-1][vert_inic-1] = peso;    
    }

    for (int j = 0; j < qtd_V; j++)
    {
        for (int k = 0; k < qtd_V; k++)
        {
            printf("%i ", matriz_adj[j][k]);
        }
        printf("\n");
    }

    fclose(file);

    return 0;
}