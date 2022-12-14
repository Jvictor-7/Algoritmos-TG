#ifndef FUNCTIONS
#define FUNCTIONS
#include "heap.h"


void help();
int dijkstra(int qtd_V, int matriz_adj[qtd_V][qtd_V], int vert_origem, int distancia[], int prev[]);
void ImprimeMatriz(int qtd_V, int matriz[qtd_V][qtd_V]);
void init_(Heap *arr, int qtd_V, int distancia[], int prev[], int origem);



#endif
