#ifndef GRAFO_H
#define GRAFO_H
  
#include "grafo.h" 
#include <iostream> 
#include <queue> 
#include <vector>   // Para usar std::vector
#include <utility>  // Para usar std::pair 
#include <algorithm> // Para usar std::find
#include <list>
 
using namespace std;  
  
int main() {
    int max = 0, valorarestanula = 0;
    Grafo grafo1(max, valorarestanula);
    int item1, item2;
    int opcao, valor, peso;

    cout << "[ Boas-vindas! ]" << endl << endl;
    cout << "* Este e um programa de analise de implementacao de grafos..." << endl << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Trabalho desenvolvido por:" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Elyza Santos" << endl;
    cout << "--------------------------------------------" << endl;
    cout << endl << "Vamos iniciar! ..." << endl << endl << endl;

    do {
        cout << "Digite 0 para parar o algoritmo!\n";
        cout << "Digite 1 para receber o grafo pelo formalismo (g form).\n";
        cout << "Digite 2 para imprimir a representacao do grafo (g imprimir).\n";
        cout << "Digite 3 para converter formalismo em matriz de adjacencia (g form mAdj).\n";
        cout << "Digite 4 para converter formalismo em lista de adjacencia (g form lAdj).\n";
        cout << "Digite 5 para converter formalismo em matriz de incidencia (g form mInc).\n";
        cout << "Digite 6 para converter matriz de adjacencia em formalismo (g mAdj form).\n";
        cout << "Digite 7 para converter matriz de adjacencia em lista de adjacencia (g mAdj lAdj).\n";
        cout << "Digite 8 para converter matriz de adjacencia em matriz de incidencia (g mAdj mInc).\n";
        cout << "Digite 9 para converter matriz de incidencia em formalismo (g mInc form).\n";
        cout << "Digite 10 para converter matriz de incidencia em matriz de adjacencia (g mInc mAdj).\n";
        cout << "Digite 11 para converter matriz de incidencia em lista de adjacencia (g mInc lAdj).\n";
        cout << "Digite 12 para remover um vertice (v remover).\n";
        cout << "Digite 13 para incluir um vertice (v incluir).\n";
        cout << "Digite 14 para remover uma aresta (a remover).\n";
        cout << "Digite 15 para incluir uma aresta (a incluir).\n";
        cout << "Digite 16 para verificar se duas arestas sao adjacentes (a ehAdjacente).\n";
        cout << "Digite 17 para verificar se dois vertices são adjacentes (v ehAdjacente).\n";
        cout << "Digite 18 para imprimir a lista de adjacencia de um vertice (v lAdj).\n";
        cout << "Digite 19 para imprimir os vertices incidentes de uma aresta (a lInc).\n";
        cout << "Digite 20 para imprimir o grau de um vertice (v grau).\n";
        cout << "Digite 21 para verificar se o grafo e bipartido (g ehBipartido).\n";
        cout << "Digite 22 para verificar se o grafo e completo (g ehCompleto).\n";
        cout << "Digite 23 para verificar se o grafo e conexo (g ehConexo).\n";
        cout << "Digite 24 para verificar se o grafo e multigrafo (g ehMultigrafo).\n";
        cout << "Digite 25 para verificar se o grafo e regular (g ehRegular).\n";
        cin >> opcao;

        switch (opcao) {
            case 1:
                grafo1.g_form();
                break;
            case 2:
                grafo1.g_imprimir(opcao);
                break;
            case 3:
                grafo1.g_form_mAdj();
                cout << "Matriz de adjacência gerada.\n";
                break;
            case 4:
                grafo1.g_form_lAdj();
                cout << "Lista de adjacência gerada.\n";
                break;
            case 5:
                grafo1.g_form_mInc();
                cout << "Matriz de incidência gerada.\n";
                break;
            case 6:
                grafo1.g_mAdj_form();
                cout << "Formalismo gerado a partir da matriz de adjacência.\n";
                break;
            case 7:
                grafo1.g_mAdj_lAdj();
                cout << "Lista de adjacência gerada a partir da matriz de adjacência.\n";
                break;
            case 8:
                grafo1.g_mAdj_mInc();
                cout << "Matriz de incidência gerada a partir da matriz de adjacência.\n";
                break;
            case 9:
                grafo1.g_mInc_form();
                cout << "Formalismo gerado a partir da matriz de incidência.\n";
                break;
            case 10:
                grafo1.g_mInc_mAdj();
                cout << "Matriz de adjacência gerada a partir da matriz de incidência.\n";
                break;
            case 11:
                grafo1.g_mInc_lAdj();
                cout << "Lista de adjacência gerada a partir da matriz de incidência.\n";
                break;
            case 12:
                cout << "Digite o vértice que será removido:\n";
                cin >> item1;
                grafo1.v_remover(item1);
                break;
            case 13:
                cout << "Digite o vértice que será incluído:\n";
                cin >> item1;
                grafo1.v_incluir(item1);
                break;
            case 14:
                cout << "Digite o vértice de saída da aresta que será removida:\n";
                cin >> item1;
                cout << "Digite o vértice de entrada da aresta que será removida:\n";
                cin >> item2;
                grafo1.a_remover(item1, item2);
                break;
            case 15:
                cout << "Digite o vértice de saída da aresta que será incluída:\n";
                cin >> item1;
                cout << "Digite o vértice de entrada da aresta que será incluída:\n";
                cin >> item2;
                cout << "Digite o peso da aresta:\n";
                cin >> peso;
                grafo1.a_incluir(item1, item2, peso);
                break;
            case 16:
                cout << "Digite o primeiro vértice:\n";
                cin >> item1;
                cout << "Digite o segundo vértice:\n";
                cin >> item2;
                if (grafo1.a_ehAdjacente(item1, item2)) {
                    cout << "Os vértices são adjacentes!\n";
                } else {
                    cout << "Os vértices não são adjacentes.\n";
                }
                break;
            case 17:
                cout << "Digite o primeiro vértice:\n";
                cin >> item1;
                cout << "Digite o segundo vértice:\n";
                cin >> item2;
                if (grafo1.v_ehAdjacente(item1, item2)) {
                    cout << "Os vértices são adjacentes!\n";
                } else {
                    cout << "Os vértices não são adjacentes.\n";
                }
                break;
            case 18:
                cout << "Digite o vértice para imprimir sua lista de adjacência:\n";
                cin >> item1;
                grafo1.v_lAdj(item1);
                break;
            case 19:
                cout << "Digite o vértice de saída da aresta:\n";
                cin >> item1;
                cout << "Digite o vértice de entrada da aresta:\n";
                cin >> item2;
                grafo1.a_lInc(item1, item2);
                break;
            case 20:
                cout << "Digite o vértice para calcular o grau:\n";
                cin >> item1;
                valor = grafo1.v_grau(item1);
                cout << "O grau do vértice é: " << valor << endl;
                break;
            case 21:
                if (grafo1.g_ehBipartido()) {
                    cout << "O grafo é bipartido!\n";
                } else {
                    cout << "O grafo não é bipartido.\n";
                }
                break;
            case 22:
                if (grafo1.g_ehCompleto()) {
                    cout << "O grafo é completo!\n";
                } else {
                    cout << "O grafo não é completo.\n";
                }
                break;
            case 23:
                if (grafo1.g_ehConexo()) {
                    cout << "O grafo é conexo!\n";
                } else {
                    cout << "O grafo não é conexo.\n";
                }
                break;
            case 24:
                if (grafo1.g_ehMultigrafo()) {
                    cout << "O grafo é multigrafo!\n";
                } else {
                    cout << "O grafo não é multigrafo.\n";
                }
                break;
            case 25:
                if (grafo1.g_ehRegular()) {
                    cout << "O grafo é regular!\n";
                } else {
                    cout << "O grafo não é regular.\n";
                }
                break;
            case 0:
                cout << "Encerrando o programa...\n";
                break;
            default:
                cout << "Opção inválida! Tente novamente.\n";
                break;
        }
    } while (opcao != 0);

    return 0;
} 
 
 

// Construtor da classe Grafo
Grafo::Grafo(int numVertices, int valorArestaNula) : numVertices(numVertices), arestaNula(valorArestaNula) {
    vertices.resize(numVertices);
    matrizAdj.resize(numVertices, std::vector<int>(numVertices, arestaNula));
    matrizInc.resize(numVertices);
    listaAdj.resize(numVertices);
}
  
 

// **1. Recebe o grafo pelo formalismo: G(V,(A, w)). Ele vai lê o número de vértices e inicializar a estrutura do grafo.**
void Grafo::g_form() {

    cout << "Digite o número de vértices: ";
    cin >> numVertices;  

    if (numVertices <= 0) {
        cout << "Erro: Número de vértices inválido!" << endl;
        return;
    } 

    //Redimensiona os vetores internos (estruturas)
    vertices.resize(numVertices);
    matrizAdj.resize(numVertices, vector<int>(numVertices, arestaNula));  
    listaAdj.resize(numVertices);
    matrizInc.resize(numVertices);
      
    //Preenche os vértices {1, 2, ..., n}
    for (int i = 0; i < numVertices; i++) {
        vertices[i] = i + 1 ;  //Preenche V com os vértices {1, 2, ..., n}
    }  
    
    //Entrada de arestas 
    int numArestas;
    cout << "Digite o número de arestas: ";
    cin >> numArestas;  
  
    //Lê as arestas
    cout << "Digite as arestas no formato (verticeInicio verticeFinal peso):" << endl;
    for (int i = 0; i < numArestas; i++) {
        int verticeInicio, verticeFim, peso;
        cout << "Aresta " << i + 1 << ": ";
        cin >> verticeInicio >> verticeFim >> peso;  
         
        //Verifica se os vértices estão dentro dos limites
        if (verticeInicio < 1 || verticeInicio > numVertices || verticeFim < 1 || verticeFim > numVertices) {
            cout << "Erro: Vértice fora dos limites!" << endl;
            i--; //Repetir a entrada para esta aresta
            continue;
        } 

        arestas.emplace_back(verticeInicio, verticeFim, peso); //Antes com push_back(Aresta(u, v, peso)), o objeto Aresta era criado e depois copiado/movido para o vetor arestas. Com emplace_back(u, v, peso)O objeto Aresta é criado diretamente dentro do vetor arestas, sem a necessidade dessa cópia.
        matrizAdj[verticeInicio - 1][verticeFim - 1] = peso;
        matrizAdj[verticeFim - 1][verticeInicio - 1] = peso; // Grafo não direcionado
    }    
} 
  
 

// **2. Para imprimir todos os tipos de **
void Grafo::g_imprimir(int tipo) { 
    if (tipo == 2) { 
        imprimirFormalismo();
    } else if (tipo == 3) {
        imprimirMatrizAdjacencia();
    } else if (tipo == 4) {
        imprimirListaAdjacencia();
    } 
    else if (tipo == 5) {
        imprimirMatrizIncidencia();
    } 
    else if (tipo == 6) {
        imprimirFormalismo();
    } 
    else if (tipo == 7) {
        imprimirListaAdjacencia();
    } 
    else if (tipo == 8) {
        imprimirMatrizIncidencia();
    } 
    else if (tipo == 9) {
        imprimirFormalismo();
    } 
    else if (tipo == 10) {
        imprimirMatrizAdjacencia();
    } 
    else if (tipo == 11) {
        imprimirListaAdjacencia();
    }
} 
    
 

//Imprime a matriz de adjacência
void Grafo::imprimirMatrizAdjacencia() {
    cout << "Matriz de adjacência gerada:" << endl;
    for (const auto& linha : matrizAdj) {
        for (int valor : linha) {
            cout << valor << " ";  // Imprime cada valor na linha
        }
        cout << endl;
    }
}   
  
 

//Imprime a matriz de incidência
void Grafo::imprimirMatrizIncidencia() { 

    cout << "Matriz de Incidência gerada:" << endl; 
  
    if (arestas.empty()) { //Empty verifica se um vetor, lista ou matriz está vazia. Retorna true se não houver elementos e false caso contrário.
        cout << "O grafo não possui arestas." << endl;
        return;
    } 

    //Inicializa a matriz de incidência (numVertices x numArestas)
    matrizInc.assign(numVertices, vector<int>(arestas.size(), 0)); //O resize redimensionava, o assign apaga tudo e faz do zero
         
    //Preenche a matriz de incidência com base nas arestas
    for (size_t i = 0; i < arestas.size(); i++) { //size_t é um tipo de dado sem sinal (unsigned) usado para representar tamanhos de objetos em memória.
        int u = arestas[i].u - 1; //Convertendo para índice 0-based (arrays começando do zero)
        int v = arestas[i].v - 1; 
        int peso = arestas[i].peso; // Obtém o peso da aresta

        matrizInc[u][i] = peso; // O vértice u está na aresta i
        matrizInc[v][i] = peso; // O vértice v está na aresta i
    }
         
    //Exibe a matriz de incidência
    for (int i = 0; i < numVertices; i++) {
        for (size_t j = 0; j < arestas.size(); j++) {
            cout << matrizInc[i][j] << " ";
        }
        cout << endl;
    }
}
   
 

//Imprime em lista de adjacencia
void Grafo::imprimirListaAdjacencia() {  
     
    cout << "Lista de adjacência:" << endl;  

    if (arestas.empty()) {
        cout << "O grafo não possui arestas." << endl;
        return;
    }

    for (int i = 0; i < listaAdj.size(); i++) { //.size() retorna o número de elementos no vetor listaAdj
        cout << "Vértice " << i + 1 << ": "; //Imprimindo 1-indexed 
    
        for (const auto& adj : listaAdj[i]) { //A palavra-chave auto permite que o compilador deduza automaticamente o tipo da variável adj 
            cout << "(" << adj.first << ", peso " << adj.second << ") ";
        }
        cout << endl;
    }
} 
   
 

//Imprime o formalismo (arestas)
void Grafo::imprimirFormalismo() {
    cout << "Formalismo do grafo G(V, (A, w)):" << endl; 
     
         //Imprime os vértices
        cout << "Vértices: { ";
        for (int i = 0; i < numVertices; i++) {
            cout << vertices[i] << " ";
        }
        cout << "}" << endl;
 
         //Imprime as arestas
        cout << "Arestas: { ";
        for (auto& aresta : arestas) {
            cout << "(" << aresta.u << ", " << aresta.v << ", peso " << aresta.peso << ") ";
        }
        cout << "}" << endl;
}
 
 

    // **3. Converte formalismo em Matriz de Adjacência**
    void Grafo::g_form_mAdj() {
        
        matrizAdj.assign(numVertices, vector<int>(numVertices, arestaNula)); 
        
        for (const auto& aresta : arestas) {
            int i = aresta.u - 1, j = aresta.v - 1; 
            matrizAdj[i][j] = matrizAdj[j][i] = aresta.peso;
        }  

        imprimirMatrizAdjacencia(); 
    } 
  
 

// **4. Converte formalismo em Lista de Adjacência**
void Grafo::g_form_lAdj() {   

    cout << "Convertendo formalismo para lista de adjacência..." << endl; 

    //Redefine a lista de adjacência
    listaAdj.assign(numVertices, vector<pair<int, int>>());

    //Preencher a lista de adjacência
    for (const auto& aresta : arestas) {  

        // Adiciona as arestas à lista de adjacência de ambos os vértices
        listaAdj[aresta.u - 1].emplace_back(aresta.v, aresta.peso);
        listaAdj[aresta.v - 1].emplace_back(aresta.u, aresta.peso);
    }
    imprimirListaAdjacencia();  // Após a conversão, imprime a lista de adjacência
}
  
 

// **5. Converte formalismo em Matriz de Incidência**
void Grafo::g_form_mInc() {
    int m = arestas.size();
    matrizInc.assign(numVertices, vector<int>(m, 0));
    for (int i = 0; i < m; i++) {
        matrizInc[arestas[i].u - 1][i] = arestas[i].peso;
        matrizInc[arestas[i].v - 1][i] = arestas[i].peso; // Para grafos não direcionados
    } 
    imprimirMatrizIncidencia();
} 
  
// **6. Converte matriz de adjacência para formalismo**
void Grafo::g_mAdj_form() {  

    arestas.clear(); 
     
    //Percorre a matriz para extrair as arestas
    for (int i = 0; i < numVertices; i++) {
        for (int j = i+1; j < numVertices; j++) { //Evita duplicação no grafo não direcionado
            if (matrizAdj[i][j] != arestaNula) {
                arestas.emplace_back(i + 1, j + 1, matrizAdj[i][j]);
            }
        }
    }  
    imprimirFormalismo();
}

// **7. Converte matriz de adjacência para lista de adjacência**
void Grafo::g_mAdj_lAdj() { 

    listaAdj.assign(numVertices, vector<pair<int, int>>());

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            // Se houver uma aresta entre os vértices i e j (peso diferente de arestaNula)
            if (matrizAdj[i][j] != arestaNula) {
                // Adiciona o par (vértice adjacente, peso da aresta) à lista de adjacência
                listaAdj[i].emplace_back(j + 1, matrizAdj[i][j]);
                // Como é um grafo não direcionado, adicionar também a aresta inversa
                listaAdj[j].emplace_back(i + 1, matrizAdj[i][j]);
            }
        }
    } 

    imprimirListaAdjacencia();  
}
 
 

//  **8. Converter matriz de Adj. em matriz de Inc.**
void Grafo::g_mAdj_mInc() {
    int numArestas = 0; 
     
    //Conta quantas arestas existem (evitando contagem duplicada)
    for (int i = 0; i < numVertices; i++) {
        for (int j = i+1; j < numVertices; j++) {
            if (matrizAdj[i][j] != arestaNula) {
                numArestas++;
            }
        }
    }
 
    //Redimensiona a matriz de incidência
    matrizInc.assign(numVertices, vector<int>(numArestas, 0)); 

    int arestaIndex = 0;
    for (int i = 0; i < numVertices; i++) {
        for (int j = i + 1; j < numVertices; j++) { // Evita repetição
            if (matrizAdj[i][j] != arestaNula) {
                matrizInc[i][arestaIndex] = matrizAdj[i][j];
                matrizInc[j][arestaIndex] = matrizAdj[i][j];
                arestaIndex++;
            }
        }
    } 
    imprimirMatrizIncidencia(); 
}
 
 

//  **9. Converter matriz de Incidenncia em formalismo**
void Grafo::g_mInc_form() {  //Lembrar que na matriz de incidencia as linhas representam os vértices e colunas representam as arestas

    arestas.clear(); 

    for (size_t j = 0; j < matrizInc[0].size(); j++) {  //Percorre cada aresta na matriz de incidência
        int verticeInicio = -1, verticeFinal = -1, peso = 0;

        for (int i = 0; i < numVertices; i++) { 
            if (matrizInc[i][j] != 0) { //Verifica se o vértice faz parte da aresta (Se um vértice participa de uma determinada aresta, a matriz contém um valor diferente de zero nessa posição.)
                if (verticeInicio == -1) { // -1 para indicar que nenhum vértice foi encontrado ainda e assim que um vértice for encontrado, atualizamos o valor para a posição correta na matriz.
                    verticeInicio = i + 1; //Primeiro vértice da aresta
                    peso = matrizInc[i][j]; //Armazena o peso da aresta
                } else {
                    verticeFinal = i + 1; //Segundo vértice da aresta
                    break; //Já temos os dois vértices, saímos do loop. Isso aqui evitou que passe por vertices desnecessarios igual meu for antigo 
             
                } 
            }
        }   
        // Agora que temos ambos os vértices e o peso, adicionamos a aresta
        if (verticeInicio != -1 && verticeFinal != -1) {  // Verifica se encontrou dois vértices
            arestas.push_back({verticeInicio, verticeFinal, peso}); // Adiciona a aresta com seus vértices e peso 
        }
    }
    imprimirFormalismo();
}
 
 

//  **10. Converter matriz de Inc. em matriz de Adjacencia**
void Grafo::g_mInc_mAdj() { 

    matrizAdj.assign(numVertices, vector<int>(numVertices, 0)); 
     
    for (size_t j = 0; j < matrizInc[0].size(); j++) { //Percorre cada aresta
        int u = -1, v = -1, peso = 0;

        for (int i = 0; i < numVertices; i++) {
            if (matrizInc[i][j] != 0) {
                if (u == -1) { 
                    u = i; 
                    peso = matrizInc[i][j]; 
                } else { 
                    v = i;
                    break;
                }
            }
        } 
         
        //Preenche a matriz de adjacência (grafo não direcionado)
        if (u != -1 && v != -1) {
            matrizAdj[u][v] = peso;
            matrizAdj[v][u] = peso;
        }
    } 
    imprimirMatrizAdjacencia(); //Exibe a matriz de adjacência gerada
}
 
 

//  **11. Converter matriz de Inc. em lista de Adjacencia**
void Grafo::g_mInc_lAdj() { 

    listaAdj.assign(numVertices, vector<pair<int, int>>()); //Inicializa a lista de adjacência

    for (size_t j = 0; j < matrizInc[0].size(); j++) { //Percorre cada aresta 
        int verticeInicio = -1, verticeFinal = -1, peso = 0; 

        for (int i = 0; i < numVertices; i++) {
            if (matrizInc[i][j] != 0) {
                if (verticeInicio == -1){ 
                    verticeInicio = i;  
                    peso = matrizInc[i][j];
                }
                else{ 
                    verticeFinal = i; 
                    break;
                }
            }
        } 
         
        // Adiciona a aresta à lista de adjacência, garantindo que seja válida
        if (verticeInicio != -1 && verticeFinal != -1) {
            listaAdj[verticeInicio].emplace_back(verticeFinal + 1, peso);
            listaAdj[verticeFinal].emplace_back(verticeInicio + 1, peso); // Grafo não direcionado
        }
    } 
    imprimirListaAdjacencia(); 
}
 
 

//  **12. Remove o vertice**
void Grafo::v_remover(int v) {
    // Verifica se o vértice existe
    auto it = find(vertices.begin(), vertices.end(), v); //Esse find é de algorithm e foi a melhor opção para procurar algo em um vetor
     
    if (it == vertices.end()) {
        cout << "Erro: Vértice " << v << " não encontrado!" << endl;
        return;
    }

    // Remove o vértice da lista de vértices
    vertices.erase(it);

    // Remove todas as arestas associadas ao vértice
    arestas.erase(
        remove_if(arestas.begin(), arestas.end(), [v](const Aresta& a) {
            return a.u == v || a.v == v;
        }),
        arestas.end()
    );

    // Atualiza a matriz de adjacência
    int index = v - 1; // Índice do vértice na matriz (0-based)
    matrizAdj.erase(matrizAdj.begin() + index); // Remove a linha do vértice
    for (auto& linha : matrizAdj) {
        linha.erase(linha.begin() + index); // Remove a coluna do vértice
    }

    // Atualiza a lista de adjacência
    listaAdj.erase(listaAdj.begin() + index); // Remove a lista do vértice
    for (auto& lista : listaAdj) {
        lista.erase(
            remove_if(lista.begin(), lista.end(), [v](const pair<int, int>& adj) {
                return adj.first == v;
            }),
            lista.end()
        );
    }

    // Atualiza a matriz de incidência
    matrizInc.erase(matrizInc.begin() + index); // Remove a linha do vértice

    // Atualiza o número de vértices
    numVertices--;

    cout << "Vértice " << v << " removido com sucesso!" << endl;
}
  
 

//  **13.Inclue um v´ertice;
void Grafo::v_incluir(int v) {
    if (find(vertices.begin(), vertices.end(), v) == vertices.end()) {
        vertices.push_back(v);
        numVertices++;
    }
}
 
//
void Grafo::a_remover(int u, int v) {
    arestas.erase(remove_if(arestas.begin(), arestas.end(), [u, v](const Aresta& a) {
        return (a.u == u && a.v == v) || (a.u == v && a.v == u);
    }), arestas.end());
}
 
//
void Grafo::a_incluir(int u, int v, int peso) {
    arestas.push_back(Aresta(u, v, peso));
}
 
//Verificar se duas arestas são adjacentes
bool Grafo::a_ehAdjacente(int u, int v) {
    for (auto &a : arestas) {
        if ((a.u == u && a.v == v) || (a.u == v && a.v == u)) {
            return true;
        }
    }
    return false;
}

//Verifica se dois vértices são adjacentes
bool Grafo::v_ehAdjacente(int u, int v) {
    return a_ehAdjacente(u, v);
}

//Imprime a lista de adjacência de um vértice
void Grafo::v_lAdj(int v) {
    int indice = v - 1; // Ajuste para índice base 0
    if (indice < 0 || indice >= numVertices) {
        cout << "Vértice inválido!" << endl;
        return;
    }

    cout << "Lista de adjacência do vértice " << v << ": ";
    for (auto &a : arestas) {
        if (a.u == v) {
            cout << a.v << " ";
        } else if (a.v == v) {
            cout << a.u << " ";
        }
    }
    cout << endl;
}

// a lInc: imprimir os vértices incidentes de uma aresta
void Grafo::a_lInc(int u, int v) {
    bool arestaEncontrada = false;
    for (auto &a : arestas) {
        if ((a.u == u && a.v == v) || (a.u == v && a.v == u)) {
            cout << "Vértices incidentes à aresta (" << u << ", " << v << "): " << u << " e " << v << endl;
            arestaEncontrada = true;
            break;
        }
    }
    if (!arestaEncontrada) {
        cout << "Aresta (" << u << ", " << v << ") não encontrada!" << endl;
    }
}
 
//Obtém o grau de um vértice
int Grafo::v_grau(int v) {
    int grau = 0;
    for (auto &a : arestas) {
        if (a.u == v || a.v == v) {
            grau++;
        }
    }
    return grau;
} 

bool Grafo::g_ehBipartido() {
    vector<int> cor(numVertices, -1);
    queue<int> fila;
    
    for (int i = 0; i < numVertices; i++) {
        if (cor[i] == -1) {
            cor[i] = 0;
            fila.push(i);
    
            while (!fila.empty()) {
                int u = fila.front();
                fila.pop();
    
                for (int v = 0; v < numVertices; v++) {
                    if (matrizAdj[u][v] != arestaNula) {
                        if (cor[v] == -1) {
                            cor[v] = 1 - cor[u];
                            fila.push(v);
                        } else if (cor[v] == cor[u]) {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

bool Grafo::g_ehCompleto() {
    for (int i = 0; i < numVertices; i++) {
        for (int j = i + 1; j < numVertices; j++) {
            if (matrizAdj[i][j] == arestaNula) {
                return false;
            }
        }
    }
    return true;
}

bool Grafo::g_ehConexo() {
    vector<bool> visitado(numVertices, false);
    queue<int> fila;
    fila.push(0);
    visitado[0] = true;

    while (!fila.empty()) {
        int u = fila.front();
        fila.pop();

        for (int v = 0; v < numVertices; v++) {
            if (matrizAdj[u][v] != arestaNula && !visitado[v]) {
                visitado[v] = true;
                fila.push(v);
            }
        }
    }

    for (bool v : visitado) {
        if (!v) return false;
    }
    return true;
}

bool Grafo::g_ehMultigrafo() {
    for (int i = 0; i < numVertices; i++) {
        for (int j = i + 1; j < numVertices; j++) {
            if (matrizAdj[i][j] != arestaNula && matrizAdj[j][i] != arestaNula) {
                return true;
            }
        }
    }
    return false;
}

bool Grafo::g_ehRegular() {
    int grau = v_grau(vertices[0]);
    for (int i = 1; i < numVertices; i++) {
        if (v_grau(vertices[i]) != grau) {
            return false;
        }
    }
    return true;
}


// Obtém o índice de um vértice no vetor de vértices
int Grafo::obterIndice(int item) {
    for (int i = 0; i < numVertices; i++) {
        if (vertices[i] == item) {
            return i; // Retorna o índice do vértice
        }
    }
    return -1; // Vértice não encontrado
}

// Verifica se o grafo está cheio
bool Grafo::estaCheio() {
    return (static_cast<size_t>(numVertices) == vertices.size());

}

// Verifica se o grafo está vazio
bool Grafo::estaVazio() {
    return (numVertices == 0);
}

// Obtém o peso de uma aresta
int Grafo::obterPeso(int noSaida, int noEntrada) {
    int linha = obterIndice(noSaida);
    int coluna = obterIndice(noEntrada);

    if (linha != -1 && coluna != -1) {
        return matrizAdj[linha][coluna]; // Retorna o peso da aresta
    }
    return arestaNula; // Retorna o valor de aresta nula se a aresta não existir
} 
 
#endif // GRAFO_H
 

     

