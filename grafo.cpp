//uma matriz para guardar os pesos, um vetor para os vertices 
  
#include "grafo.h" 
#include <iostream> 
#include <queue>
 
using namespace std; 


    Grafo::Grafo(int max, int valorArestaNula){  
        int arestaNula = valorArestaNula; 
        int maxVertices = max; 
        int numVertices = 0; 
         
        vertices = new tipoItem[maxVertices]; 
        matrizDeAdjacencias = new int*[maxVertices]; 

        for(int i=0; i<maxVertices; i++){ 
            matrizDeAdjacencias[i] = new int[maxVertices]; 
        } 
         
        for(int i=0; i<maxVertices; i++){ 
            for(int j=0; j<maxVertices; j++){ 
                matrizDeAdjacencias[i][j] = arestaNula;
            }
        } 
    } 

    Grafo::~Grafo(){  
        delete [] vertices; 
        for(int i=0; i<maxVertices; i++){   
            delete [] matrizDeAdjacencias[i];
        } 
        delete [] matrizDeAdjacencias;
    }  

    int Grafo::obterIndice(tipoItem item){  
        int indice = 0; 
        while(item !=vertices[indice]){  
            indice++;
        }  
        if(item == vertices[indice]){
            return indice; 
        } 
        else{ 
            return -1; //Não encontrado. Lembrar: Sempre que usar obterIndice testar se é -1
        }
    }  

    bool Grafo::estaCheio(){ //Retorna verdadeiro se estiver cheio 
        return (numVertices == maxVertices);
    }  

    bool Grafo::estaVazio(){  
        return (numVertices == arestaNula);
    }  

    void Grafo::insereVertices(tipoItem item){  

        if(estaCheio()){ 
            cout << "Grafo está cheio. Não é possível inserir mais vertices.\n";
        } else{ 
            vertices[numVertices] = item; 
            numVertices++;
        }
    }  

    void Grafo::insereAresta(tipoItem noSaida, tipoItem noEntrada, int peso){   
         
        int linha = obterIndice(noSaida); 
        int coluna = obterIndice(noEntrada); 
         
        if (linha != -1 && coluna != -1) {
            matrizDeAdjacencias[linha][coluna] = peso;
            matrizDeAdjacencias[coluna][linha] = peso; // Grafo não direcionado
        }
    }  

    int Grafo::obterPeso(tipoItem noSaida, tipoItem noEntrada){  
        int linha = obterIndice(noSaida); 
        int coluna = obterIndice(noEntrada);  

        if (linha != -1 && coluna != -1) {
            return matrizDeAdjacencias[linha][coluna];
        }
    }  

    int Grafo::obterGrau(tipoItem item){   //Se fosse direcionado, teria que percorrer a linha, ver quantos elementos são diferentes do valor aresta nula, para saber o grau de saida e ver a coluna para saber o grau de entrada e depois somar os dois
        int linha = obterIndice(item); 
        int grau = 0;   
 
        if (linha != -1) {
            for(int i = 0; i < maxVertices; i++){  
                if(matrizDeAdjacencias[linha][i] != arestaNula){ //Se o elemento da linha existir
                    grau++;
                } 
            }  
        }
        return grau;
    }  
     
    void Grafo::imprimirMatriz() {
        cout << "\nMatriz de adjacência:\n"; 
        
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << matrizDeAdjacencias[i][j] << " ";
            }
            cout << "\n";
        }
    }
     
    void Grafo::imprimirVertices(){  
         
        cout << "Vertices: \n"; 
        for( int i = 0; i < numVertices; i++){  //Pode ser que não tenha adicionado todos os vertices ainda
            cout << i << ": " << vertices[i] << endl;
        } 

    }  