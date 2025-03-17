#ifndef GRAFO_H 
#define GRAFO_H 
  
#include <iostream>  
#include <vector>
 
using namespace std; 
 
typedef int tipoItem; //Vertices são inteiros (eu acho) 
 
class Grafo{ 
private:  
    int arestaNula; //Número para representar a ausência de arestas na matriz de adjacencia. Tipo, como eu vou saber se não tem aresta ou se o peso dela seria o 0. Aí se o peso for 0, eu coloco a aresta como -1
    int maxVertices; //Número máximo de vértices. Quando eu for criar um grafo, eu crio um vetor e uma matriz, nessa matriz eu preciso saber qual o tamanho dela e o do vetor max
    int numVertices; //Importante para saber quantos tem e a sua posição: Ver se alcançou o max de vertices (cheio) e para ver em qual posição colocar no meu vetor de vertices, o primeiro vertice que eu acrescentar vai para a posição 0...
    tipoItem* vertices; //Vetor de vértices 
    int** matrizDeAdjacencias; //Dinamico para desalocar a memoria, primeiro cria um vetor que vai representar os vertices e dentro desse vetor terao os outros vetores

public:  
    //Construtor: máximo de vertices (tamanho da matriz de adjacencia)
    Grafo(int max, int valorArestaNula); //Quando eu criar a matriz, já adiciono o valorarestanula em todos os elementos, todos com -1 porque ainda não tem nenhuma aresta 
    //Destrutor
    ~Grafo();   

    //Informa o vertice e obtem o indice, se foi o primeiro a ser inserido, ele tem indice 0. 
    int obterIndice(tipoItem item);  
    bool estaCheio(); //Num max de grafos 
    bool estaVazio(); //Vai ser usado para remover vertices e todas suas arestas 
    void insereVertices(tipoItem); //Precisa só de um vertice
    void insereAresta(tipoItem noSaida, tipoItem noEntrada, int peso); //Aqui eu preciso de dois vertices. Não importa porque é não direcionado mas fica melhor de entender
    int obterPeso(tipoItem noSaida, tipoItem noEntrada); 
    int obterGrau(tipoItem item); //conta na linha a quantidade de números diferentes do valorArestaNula 
    void imprimirMatriz(); 
    void imprimirVertices(); 
     
}; 
 
#endif