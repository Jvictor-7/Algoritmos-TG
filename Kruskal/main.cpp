#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

class Aresta{
    int vertice1, vertice2, peso;

public:
    // Formando aresta
    Aresta(int v1, int v2, int peso){
        vertice1 = v1;
        vertice2 = v2;
        this->peso = peso;
    }
    // Retornando vertice1
    int obterVertice1(){
        return vertice1;
    }
    // Retornando vertice2
    int obterVertice2(){
        return vertice2;
    }
    // Retornando peso
    int obterPeso(){
        return peso;
    }
    // Retornando a menor das arestas
    bool operator < (const Aresta& aresta2){
        return (peso < aresta2.peso);
    }
};

class Grafo{
    // Quantidade de vértices
    int V;
    // Vetor de Arestas
    vector<Aresta> arestas;
public:
    // Formando o grafo
    Grafo(int V) {
        this-> V = V;
    }
    // Adicionando arestas ao grafo
    void adicionarAresta(int v1, int v2, int peso){
        Aresta aresta(v1, v2, peso);
        arestas.push_back(aresta);
    }
    // UNION-FIND
    // Find do Union-Find - Busca o subconjunto de um vértice v
    int buscar(int subset[], int v) {
        if(subset[v] == -1)
            return v;
        return buscar(subset, subset[v]);
    }

    // Union do Union-Find - Une dois subconjuntos em um único subconjunto
    void unir(int subset[], int v1, int v2) {
        int v1_set = buscar(subset, v1);
        int v2_set = buscar(subset, v2);

        subset[v1_set] = v2_set;
    }
    // UNION-FIND //

    // Algoritmo de Kruskal
    void kruskal(string saida, bool soluc, int vertInicial){
        vector<Aresta> arvore;
        int size_arestas = arestas.size();

        // Ordenando arestas pelo menor peso
        sort(arestas.begin(), arestas.end());

        // Alocando memória pora criar V subconjuntos
        int * subset = new int[V];

        // Inicializando todos os subconjuntos como conjuntos de um único elemento
        memset(subset, -1, sizeof(int) * V);
        if (vertInicial == -1){
            for (int i = 0; i < size_arestas; i++){
                int v1 = buscar(subset, arestas[i].obterVertice1());
                int v2 = buscar(subset, arestas[i].obterVertice2());

                // Se v1 é diferente de v2, logo não forma ciclo e insere o vetor
                if (v1 != v2){
                    arvore.push_back(arestas[i]);
                    unir(subset, v1, v2); // Une
                }
            }
        }
        else{
            for (int i = vertInicial; i < size_arestas; i++){
                int v1 = buscar(subset, arestas[i].obterVertice1());
                int v2 = buscar(subset, arestas[i].obterVertice2());

                // Se v1 é diferente de v2, logo não forma ciclo e insere o vetor
                if (v1 != v2){
                    arvore.push_back(arestas[i]);
                    unir(subset, v1, v2); // Une
                }
            }
        }

        int size_arvore = arvore.size();
        // Imprimir AGM
        if (soluc){
            if (saida != ""){
                ofstream arquivoS;
                arquivoS.open(saida);
                for (int i = 0; i < size_arvore; i++){
                    int v1 = arvore[i].obterVertice1() + 1;
                    int v2 = arvore[i].obterVertice2() + 1;

                    arquivoS << "(" << v1 << "," << v2 << ") = " << arvore[i].obterPeso() << endl;
                }     
                arquivoS.close();       
            }
            else {
                for (int i = 0; i < size_arvore; i++){
                    int v1 = arvore[i].obterVertice1() + 1;
                    int v2 = arvore[i].obterVertice2() + 1;

                    cout << "(" << v1 << "," << v2 << ") = " << arvore[i].obterPeso() << endl;
                } 
            } 
        }
        else{
            if (saida != ""){
                ofstream arquivoS;
                arquivoS.open(saida);
                int soma = 0;
                for (int i = 0; i < size_arvore; i++){
                    soma += arvore[i].obterPeso();
                }     
                arquivoS << soma << endl;
                arquivoS.close();       
            }
            else {
                int soma = 0;
                for (int i = 0; i < size_arvore; i++){
                    soma += arvore[i].obterPeso();
                } 
                cout << soma  << endl;
            } 
        }
    }
};

void help(){
    printf("help\n");
}

int main(int arg, char *argv[])
{
    int output = 0, inpt = 0, vertInicial = -1, vertFinal = 0;

    string entrada;
    string saida = "";

    bool soluc = false;

    for (int i = 0; i < arg; i++)
    {
        if(strcmp(argv[i], "-h") == 0){
            help();
            return 0;
        }
        else if(strcmp(argv[i], "-o") == 0){
            output = i + 1;
            saida = argv[output];
            printf("Arquivo de saida: %s\n", argv[output]);
            printf("A resposta se encontra neste arquivo de saida...\n");
        }
        else if(strcmp(argv[i], "-f") == 0){
            if (strcmp(argv[i + 1], "-s") == 0){
                inpt = i + 2;
                entrada = argv[inpt];
            }
            else{
                inpt = i + 1;
                entrada = argv[inpt];
            }
        }
        else if(strcmp(argv[i], "-s") == 0){
            soluc = true;     
        }
        else if(strcmp(argv[i], "-i") == 0){
            sscanf(argv[i + 1], "%d", &vertInicial);
            vertInicial -= 1;

            // printf("Esta funcao nao esta habilitada para esse tipo de algoritmo.\n");
            // printf("Tente rodar: ./kruskal -f -s entrada.txt\n");
            // printf("Ou: ./kruskal -f -s entrada.txt -o saida.txt\n");
            // printf("Saindo do programa...\n");
            // exit( 3 );    
        }
        else if(strcmp(argv[i], "-l") == 0){
            printf("Esta funcao nao esta habilitada para esse tipo de algoritmo.\n");
            printf("Tente rodar: ./kruskal -f -s entrada.txt\n");
            printf("Ou: ./kruskal -f -s entrada.txt -o saida.txt\n");
            printf("Saindo do programa...\n");
            exit( 3 );     
        }
    }

    int qtd_V, qtd_A;

    ifstream arquivoE(entrada);

    arquivoE >> qtd_V >> qtd_A;


    Grafo g(qtd_V);

    for (int i = 0; i < qtd_A; i++) {
        int u, v, peso;
        arquivoE >> u >> v >> peso;
        u-=1;
        v-=1;

        g.adicionarAresta(u, v, peso);
    }

    arquivoE.close();        

    if(vertInicial + 1> qtd_V){
        printf("Digite um vertice inicial valido. De %d a %d\n", 1, qtd_V);
        printf("Saindo do programa...");
        exit(3);
    }

    // Adicionando as arestas
    g.kruskal(saida, soluc, vertInicial);

    return 0;
}
