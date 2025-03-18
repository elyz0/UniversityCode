#include <vector>   // Para usar std::vector
#include <utility>  // Para usar std::pair 
  
struct Aresta {
    int u, v, peso;
    Aresta(int u, int v, int peso) : u(u), v(v), peso(peso) {}
};

class Grafo {
private: 
    int numVertices;
    int arestaNula;
    std::vector<int> vertices;
    std::vector<Aresta> arestas;
    std::vector<std::vector<int>> matrizAdj;
    std::vector<std::vector<int>> matrizInc;
    std::vector<std::vector<std::pair<int, int>>> listaAdj;

public:
    Grafo(int numVertices, int valorArestaNula = 0);

    void g_form();
    void g_imprimir(int tipo);
    void g_form_mAdj();
    void g_form_lAdj();
    void g_form_mInc(); 
    void g_mAdj_form();
    void g_mAdj_lAdj();
    void g_mAdj_mInc();
    void g_mInc_form();
    void g_mInc_mAdj();
    void g_mInc_lAdj();
    void v_remover(int v);
    void v_incluir(int v);
    void a_remover(int u, int v);
    void a_incluir(int u, int v, int peso);
    bool a_ehAdjacente(int u, int v);
    bool v_ehAdjacente(int u, int v); 
    void v_lAdj(int v);
    void a_lInc(int u, int v);
    int v_grau(int v);
    bool g_ehBipartido();
    bool g_ehCompleto();
    bool g_ehConexo();
    bool g_ehMultigrafo();
    bool g_ehRegular(); 
     
    int obterIndice(int item); 
    bool estaCheio(); 
    bool estaVazio();
    int obterPeso(int noSaida, int noEntrada); 
     
    void imprimirMatrizAdjacencia();  
    void imprimirMatrizIncidencia();
    void imprimirFormalismo(); 
    void imprimirListaAdjacencia(); 

};
