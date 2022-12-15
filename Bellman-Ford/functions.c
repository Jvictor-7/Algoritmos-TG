#include "functions.h"
#define TRUE 1
#define FALSE 0

void help(){
    printf("\t\t\t BEM VINDO...\n");
    printf("Este codigo foi desenvolvido com o intuito de implementar o algoritmo de BELLMAN-FORD.\n");
    printf("Para rodar o codigo de forma correta, primeiramente deve-se usar o MAKEFILE atraves do terminal:\n");
    printf("\t 1. Certifique-se de estar no diretorio do algoritmo\n");
    printf("\t 2. Rode o comando make.\n");
    printf("Apos rodar o make, temos alguns prefixos que podem ser usados para rodar o algoritmo:\n");
    printf("\t-h : help\n\t-o <arquivo> : redireciona a saida para o arquivo\n\t-f <arquivo> : indica o arquivo que contem o grafo de entrada\n\t-s : mostra a solucao\n\t-i <vertice>: vertice inicial\n\t-l <vertice>: vertice final\n");
    printf("OBS: usa-se '-s' após o comando '-f'!");
    printf("\nEXEMPLOS DE COMANDOS:\n");
    printf("\t./bellman -f -s entrada.txt -o saida.txt -i 1\n");
    printf("\t./bellman -f entrada.txt -i 1\n");
    printf("\t./bellman -h\n");
    printf("\t./bellman -f -s entrada.txt -i 1 -l 5 -o saida.txt\n");
}

void solucaoPrint(int prev[], int vert, int vertOrigem){
    if(prev[vert] != vertOrigem && vertOrigem != vert){
        solucaoPrint(prev, prev[vert], vertOrigem);
    }
    
    if(vert != vertOrigem){
        printf("(%d, %d)", prev[vert] + 1, vert+1);
    }
}

void solucaoArq(FILE* saida, int prev[], int vert, int vertOrigem){
    if(prev[vert] != vertOrigem && vertOrigem != vert){
        solucaoArq(saida, prev, prev[vert], vertOrigem);
    }
    
    if(vert != vertOrigem){
        fprintf(saida, "(%d, %d)", prev[vert] + 1, vert+1);
    }
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

void init_(int qtd_V, int distancia[], int prev[], int origem){
    for (int i = 0; i < qtd_V; i++)
    {
        distancia[i] = INFINITO;
        prev[i] = -1;
    }
    distancia[origem] = 0;
    
}

int bellman(int qtdV, int matrizAdj[][qtdV], int distancia[], int prev[], int vertOrigem){

    init_(qtdV, distancia, prev, vertOrigem - 1);

    for (int i = 0; i < qtdV-1; i++)
    {
        for (int j = 0; j < qtdV; j++)
        {
            for (int k = 0; k < qtdV; k++)
            {
                if(matrizAdj[j][k] != 0){
                    if(distancia[k] > distancia[j] + matrizAdj[j][k]){
                        distancia[k] = distancia[j] + matrizAdj[j][k];
                        prev[k] = j;
                    }
                }
            } 
        }
    }

    for (int j = 0; j < qtdV; j++)
    {
        for (int k = 0; k < qtdV; k++)
        {
            if(matrizAdj[j][k] != 0){
                if(distancia[k] > distancia[j] + matrizAdj[j][k]){
                    return FALSE;
                }
            }
        } 
    }
    return TRUE;

}
