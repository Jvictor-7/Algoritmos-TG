#include "heap.h"

#define INFINITO 9999

int filhoMaiorPrioridade(Heap *arr, int filhoEsquerda, int filhoDireita){
    if(arr[filhoDireita].prioridade < arr[filhoEsquerda].prioridade){
        return filhoDireita;
    }
    return filhoEsquerda;
}

Heap *menorPrioridade(Heap *arr){
    return &arr[0];
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
    if(prioridade > arr[ind].prioridade){
        printf("ERRO - Prioridade não aumentada.");
    }

    arr[ind].prioridade = prioridade;

    int pai = (ind-1)/2;

    while (prioridade < arr[pai].prioridade)
    {
        trocaPaiFilho(arr, ind, pai);
        ind = pai;
        pai = (ind-1)/2;
    }
    
}

void inserirFila(Heap *arr, int prioridade, int *tam){
    *tam = *tam + 1;
    arr[*tam - 1].prioridade = INFINITO;
    mudarPrioridade(arr, *tam - 1, prioridade);
}