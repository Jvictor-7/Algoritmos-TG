#include <bits/stdc++.h>

using namespace std;

int N, M;

void help(){
    printf("\n\t\t\t BEM VINDO...\n");
    printf("Este codigo foi desenvolvido com o intuito de implementar o algoritmo de PRIM.\n");
    printf("Para rodar o codigo de forma correta, primeiramente deve-se usar o MAKEFILE atraves do terminal:\n");
    printf("\t 1. Certifique-se de estar no diretorio do algoritmo\n");
    printf("\t 2. Rode o comando make ou mingw32-make.\n");
    printf("Apos rodar o make, temos alguns prefixos que podem ser usados para rodar o algoritmo:\n");
    printf("\t-h : mostra o help\n\t-o <arquivo> : redireciona a saida para o arquivo\n\t-f <arquivo> : indica o arquivo que contem o grafo de entrada\n\t-s : mostra a solucao\n\t-i : vertice inicial\n\t-l : vertice final (NAO FUNCIONA NESTE ALGORITMO)\n");
    printf("\nEXEMPLOS DE COMANDOS:\n");
    printf("\t./prim -f -s entrada.txt -o saida.txt\n");
    printf("\t./prim -f entrada.txt\n");
    printf("\t./prim -h\n");
    printf("\t./prim -f -s entrada.txt -i 1 -o saida.txt\n");
}

int main(int arg, char *argv[]) {
    int output = 0, inpt = 0, vertInicial = 0, vertFinal = 0;

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
        }
        else if(strcmp(argv[i], "-l") == 0){
            printf("Esta funcao nao esta habilitada para esse tipo de algoritmo.\n");
            printf("Tente rodar novamente sem definir um vertice final.\n");
            printf("Saindo do programa...\n");
            exit( 3 );      
        }
    }

    ifstream arquivoE(entrada);

    while (arquivoE >> N >> M  and N) {
        vector< vector<pair<int,int> > > G(N);
        // Montando o grafo
        for (int i = 0; i < M; i++) {
            int u, v, peso;
            arquivoE >> u >> v >> peso;
            u-=1;
            v-=1;
            G[u].push_back( {v,peso} );
            G[v].push_back( {u,peso} );
        }

        arquivoE.close();        
        // Criando fila de prioridade 
        priority_queue< pair<int,int> > prim;

        vector<bool> mark(N, false);
        vector<int> prev(N, -1);

        mark[vertInicial - 1] = true;
        prev[vertInicial - 1] = vertInicial - 1;         

        // Adicionando todos que estão ligados ao vertice inicial na fila de prioridade
        for(pair<int,int> ed: G[vertInicial - 1]){
            prim.push( { -ed.second, ed.first } );
        }

        ofstream arquivoS;
        arquivoS.open(saida);    

        int soma = 0;
        while (prim.size()) {
            // menor.first é o menor peso do par de vértices da fila
            // menor.second é o vertice de destino
            int vertSeguinte;

            // Pegando a menor aresta, levando ao topo e removendo
            pair<int,int> menor = prim.top();
            vertSeguinte = menor.second;
            prim.pop();
            // Se eu ja visitei o vertice, continue e pegue outra aresta
            if(mark[menor.second] == true){
                vertInicial = vertSeguinte+1;
                continue;
            }

            soma += -menor.first;
            //Marcando como visitado
            mark[menor.second] = true;

            if (soluc){
                if (vertInicial == 6){
                    arquivoS << "("<< vertInicial/2 << ","<< vertSeguinte+1 << ") ";
                }
                else{
                    arquivoS << "("<< vertInicial << ","<< vertSeguinte+1 << ") ";
                }
            }

            //Pegando todas as arestas que estão saindo deste vertice e adicionando na fila de prioridade
            for(pair<int,int> ed: G[menor.second]){
                prim.push( { -ed.second, ed.first } );
            }
            vertInicial = vertSeguinte+1;
        }
        arquivoS.close();        
        if (!soluc){
            if (saida != ""){
                cout << "A resposta esta no arquivo de saida: " << saida << endl;
                ofstream arquivoS;
                arquivoS.open(saida);    
                arquivoS << soma;
                arquivoS.close();       
            }
            else {
                cout << soma << endl;
            }

        }
    }

    return 0;
}