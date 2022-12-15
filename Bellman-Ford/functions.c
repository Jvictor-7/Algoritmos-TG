#include "functions.h"
#define TRUE 1
#define FALSE 0

void help(){
    
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
