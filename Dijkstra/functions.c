#include "functions.h"
#include "heap.h"

void help(){
    printf("\t\t\t BEM VINDO...\n");
    printf("Este codigo foi desenvolvido com o intuito de implementar o algoritmo de DIJKSTRA.\n");
    printf("Para rodar o codigo de forma correta, primeiramente deve-se usar o MAKEFILE atraves do terminal:\n");
    printf("\t 1. Certifique-se de estar no diretorio do algoritmo\n");
    printf("\t 2. Rode o comando make.\n");
    printf("Apos rodar o make, temos alguns prefixos que podem ser usados para rodar o algoritmo:\n");
    printf("\t-h : help\n\t-o <arquivo> : redireciona a saida para o arquivo\n\t-f <arquivo> : indica o arquivo que contem o grafo de entrada\n\t-s : mostra a solucao\n\t-i <vertice>: vertice inicial\n\t-l <vertice>: vertice final\n");
    printf("OBS: usa-se '-s' após o comando '-f'!");
    printf("\nEXEMPLOS DE COMANDOS:\n");
    printf("\t./dijkstra -f -s entrada.txt -o saida.txt -i 1\n");
    printf("\t./dijkstra -f entrada.txt -i 1\n");
    printf("\t./dijkstra -h\n");
    printf("\t./dijkstra -f -s entrada.txt -i 1 -l 5 -o saida.txt\n");
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

<<<<<<< HEAD
//Parâmetros de entrada: -i -s
int dijkstra(int qtd_V, int grafo[qtd_V][qtd_V], int vert_origem){
    int distancia[qtd_V], prev[qtd_V];

    for (int i = 0; i < qtd_V; i++) distancia[i] = INFINITO;
=======
void init_(Heap *arr, int qtd_V, int distancia[], int prev[], int origem){
    for (int i = 0; i < qtd_V; i++)
    {
        distancia[i] = INFINITO;
        prev[i] = -1;
    }
    distancia[origem] = 0;
    
}
 
// Algoritmo de Dijkstra
int dijkstra(int qtd_V, int matriz_adj[qtd_V][qtd_V], int vert_origem, int distancia[], int prev[]){
>>>>>>> 3f542acfdc4f938d973d0e80649940dae339a97a

    int heapLenght = qtd_V;

    int *tam = (int *)malloc(sizeof(int));
    *tam = 0;
    Heap *H = (Heap *)malloc(sizeof(Heap)*heapLenght);
    H[0] = vert_origem;

<<<<<<< HEAD
    distancia[vert_origem - 1] = 0;
    prev[vert_origem - 1] = 0;
=======
    initHeap(H, qtd_V, vert_origem, tam);
    init_(H, qtd_V, distancia, prev, vert_origem - 1);
         
>>>>>>> 3f542acfdc4f938d973d0e80649940dae339a97a

    while (*tam != 0)
    {
        if(H[0].prioridade == MIN_PRIORITY){
            printf("grafo desconexo\n");
            break;
        }

        int vertAtual = maiorPrioridade(H) - 1;

        extrairMin(H, tam);

        for (int i = 0; i < qtd_V; i++)
        {
            if(matriz_adj[vertAtual][i] != 0){             
                if(distancia[i] > distancia[vertAtual] + matriz_adj[vertAtual][i]){
                    distancia[i] = distancia[vertAtual] + matriz_adj[vertAtual][i];
                    prev[i] = vertAtual;
                    mudarPrioridade(H,i, distancia[i]);     
                }        
            }
        }
        
    }
    return 0;
}
