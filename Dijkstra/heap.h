#ifndef HEAP
#define HEAP

#define INFINITO 9999
#define MAX_PRIORITY 0
#define MIN_PRIORITY 9999



typedef struct heap{
    int id;
    int prioridade;
} Heap;


int filhoMaiorPrioridade(Heap *arr, int filhoEsquerda, int filhoDireita);
int maiorPrioridade(Heap *arr);
void trocaPaiFilho(Heap *arr, int filho, int pai);
void extrairMin(Heap *arr, int *tam);
void mudarPrioridade(Heap *arr, int ind, int prioridade);
void inserirFila(Heap *arr, int prioridade, int *tam, int id);
void initHeap(Heap *arr, int qtd_V, int origem, int *tam);



#endif