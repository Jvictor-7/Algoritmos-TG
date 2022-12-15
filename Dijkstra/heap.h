#ifndef HEAP
#define HEAP

<<<<<<< HEAD
=======
#define INFINITO 9999
#define MAX_PRIORITY 0
#define MIN_PRIORITY 9999



>>>>>>> 3f542acfdc4f938d973d0e80649940dae339a97a
typedef struct heap{
    int id;
    int prioridade;
} Heap;
<<<<<<< HEAD
=======

>>>>>>> 3f542acfdc4f938d973d0e80649940dae339a97a

int filhoMaiorPrioridade(Heap *arr, int filhoEsquerda, int filhoDireita);
int maiorPrioridade(Heap *arr);
void trocaPaiFilho(Heap *arr, int filho, int pai);
void extrairMin(Heap *arr, int *tam);
void mudarPrioridade(Heap *arr, int ind, int prioridade);
void inserirFila(Heap *arr, int prioridade, int *tam, int id);
void initHeap(Heap *arr, int qtd_V, int origem, int *tam);



#endif