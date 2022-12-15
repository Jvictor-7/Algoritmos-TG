#include <bits/stdc++.h>

using namespace std;

//Main
// --- ENTRADA ---
int N, M;

void help(){
    printf("help\n");
}

int main(int arg, char *argv[]) {
    int output = 0, inpt = 0, vertInicial = 0, vertFinal = 0;

    string entrada;
    string saida = "sem";

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
            inpt = i + 1;
            printf("nome do arquivo: %s\n", argv[inpt]);
            entrada = argv[inpt];
        }
        else if(strcmp(argv[i], "-s") == 0){
            soluc = true;
            printf("Erro de sistema...");
            exit( 3 );      
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
        mark[vertInicial - 1] = true;

        // Adicionando todos que estão ligados ao verticel inicial na fila de prioridade
        for(pair<int,int> ed: G[vertInicial - 1]){
            prim.push( { -ed.second, ed.first } );
        }

        int soma = 0;
        while (prim.size()) {
            // Pegando a menor aresta, levando ao topo e removendo
            pair<int,int> menor = prim.top();
            prim.pop();
            // Se eu ja visitei o vertice, continue e pegue outra aresta
            if(mark[menor.second] == true) continue;
            soma += -menor.first;
            //Marcando como visitado
            mark[menor.second] = true;
            //Pegando todas as arestas que estão saindo deste vertice e adicionando na fila de prioridade
            for(pair<int,int> ed: G[menor.second]){
                prim.push( { -ed.second, ed.first } );
            }
        }
        
        if (saida != "sem"){
            ofstream arquivoS;
            arquivoS.open("saida.txt");    
            arquivoS << soma;
            arquivoS.close();       
        }
        else {
            cout << soma << endl;
        }
    }

    return 0;
}