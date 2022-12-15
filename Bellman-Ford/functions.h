#ifndef FUNCTIONS
#define FUNCTIONS

#define INFINITO 9999

void help();
void ImprimeMatriz(int qtd_V, int matriz[qtd_V][qtd_V]);
void init_(int qtd_V, int distancia[], int prev[], int origem);
int bellman(int qtdV, int matrizAdj[][qtdV], int distancia[], int prev[], int vertOrigem);
void solucaoPrint(int prev[], int vert, int vertOrigem);
void solucaoArq(FILE* saida, int prev[], int vert, int vertOrigem);


#endif
