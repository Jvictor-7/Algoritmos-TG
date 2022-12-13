#ifndef HEAP
#define HEAP


int filhoMaiorPrioridade(Heap *arr, int filhoEsquerda, int filhoDireita);
Heap *menorPrioridade(Heap *arr);
void trocaPaiFilho(Heap *arr, int filho, int pai);
void extrairMin(Heap *arr, int *tam);
void mudarPrioridade(Heap *arr, int ind, int prioridade);
void inserirFila(Heap *arr, int prioridade, int *tam);


#endif