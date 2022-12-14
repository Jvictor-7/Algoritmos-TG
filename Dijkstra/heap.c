#include "heap.h"

void initHeap(Heap *arr, int qtd_V, int origem, int *tam){
    for (int i = 0; i < qtd_V; i++)
    {
        if ( (i + 1)  != origem)
        {
            inserirFila(arr, MIN_PRIORITY, tam, i+1);
        }
        else
        {
            inserirFila(arr, MAX_PRIORITY, tam, i+1);
        }
    }  
}

int filhoMaiorPrioridade(Heap *arr, int filhoEsquerda, int filhoDireita){
    if(arr[filhoDireita].prioridade < arr[filhoEsquerda].prioridade){
        return filhoDireita;
    }
    return filhoEsquerda;
}

int maiorPrioridade(Heap *arr){
    return arr[0].id;
}

void trocaPaiFilho(Heap *arr, int filho, int pai){
    Heap aux = arr[pai];
    arr[pai] = arr[filho];
    arr[filho] = aux;
}

void extrairMin(Heap *arr, int *tam){
    if(*tam == 0){
        printf("Fila vazia!\n");
    }

    arr[0] = arr[*tam-1];
    *tam = *tam - 1;

    int indPai = 0;
    int filhoMaior = filhoMaiorPrioridade(arr, (indPai)*2 + 1, (indPai)*2 + 2);

    while (arr[indPai].prioridade > arr[filhoMaior].prioridade){
        trocaPaiFilho(arr, filhoMaior, indPai);
        indPai = filhoMaior;

        if(((indPai)*2 + 1) > *tam-1){
            break;
        }
        
        filhoMaior = filhoMaiorPrioridade(arr, (indPai)*2+1, (indPai)*2+2);
    }   
}



void mudarPrioridade(Heap *arr, int ind, int prioridade){
    int aux = 0;
    while (arr[aux].id != ind + 1)
    {
        aux++;
    }
    
    if(prioridade > arr[aux].prioridade){
        printf("ERRO - Prioridade não aumentada.");
    }

    arr[aux].prioridade = prioridade;

    int pai = (aux-1)/2;

    while (prioridade < arr[pai].prioridade)
    {
        trocaPaiFilho(arr, aux, pai);
        aux = pai;
        pai = (aux-1)/2;
    }
    
}

void inserirFila(Heap *arr, int prioridade, int *tam, int id){
    *tam = *tam + 1;
    arr[*tam - 1].prioridade = INFINITO;
    arr[*tam - 1].id = id;

    mudarPrioridade(arr, *tam - 1, prioridade);
}