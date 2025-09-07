import networkx as nx #Biblioteca para grafos. Permite criar nós, arestas, e analisar estruturas de grafos.
import matplotlib.pyplot as plt #Usada para desenhar gráficos e visualizações, no caso retangulos
import xml.etree.ElementTree as ET #Biblioteca para ler arquivos XML.
from shapely.geometry import LineString, box #biblioteca para geometria importa linha entre dois pontos e box cria o retangulo. 
import math
 
#O SVG é baseado em XML, que é uma linguagem de marcação hierárquica (em árvore).
def extrair_retangulos(svg_file): 
    #Ler e manipular arquivos SVG
    tree = ET.parse(svg_file) #Transforma o arquivo em uma árvore de elementos. Cada tag vira um nó da árvore e pode navegar para baixo (filhos) ou para cima (pai). A vantagem é o acesso direto aos elementos.
    root = tree.getroot()

    viewBox = root.get('viewBox', '0 0 100 100')
    _, _, largura, altura = map(float, viewBox.split())

    obstaculos = [] #Lista para armazenar os retângulos.

    for rect in root.iter('{http://www.w3.org/2000/svg}rect'): 
         
        #Lê a posição (x, y) do canto superior esquerdo do retângulo.
        x = float(rect.get('x', 0))
        y = float(rect.get('y', 0))
 
        #Remove o %
        w_str = rect.get('width', '0').replace('%', '')
        h_str = rect.get('height', '0').replace('%', '')
 
        #Converte os valores para float.
        w = float(w_str) if w_str else 0.0
        h = float(h_str) if h_str else 0.0
        
        #Remove o retângulo fantasma
        if (x == 0.0 and y == 0.0 and w == 100.0 and h == 100.0):
            continue 
 
        #Adiciona o retângulo como uma tupla.
        obstaculos.append((x, y, w, h))

    return obstaculos, largura, altura #Retorna a lista de obstáculos e o tamanho da imagem.
  
def mostrar_obstaculos(svg_file): 
      
    retangulos, largura_svg, altura_svg = extrair_retangulos(svg_file) 

    fig, ax = plt.subplots(figsize=(12, 8))
    ax.set_xlim(0, largura_svg)
    ax.set_ylim(altura_svg, 0)  # Inverter Y como no SVG 

    for (x, y, w, h) in retangulos:
        rect = plt.Rectangle((x, y), w, h, edgecolor='black', facecolor='none')
        ax.add_patch(rect)

    plt.title(f"Visualização dos {len(retangulos)} Retângulos do SVG")
    plt.xlabel("Largura")
    plt.ylabel("Altura")
    plt.grid(True)
    plt.tight_layout()
    plt.show() 

#Verifica se dois pontos conseguem se ver, se nao tem nenhum objeto entre eles
def visibilidade(p1, p2, obstaculos):
    linha = LineString([p1, p2]) #Cria a linha
    for (x, y, w, h) in obstaculos: #Cria cada obstaculocomo um retangulo
        retangulo = box(x, y, x + w, y + h)
        if linha.crosses(retangulo) or retangulo.contains(linha): #Se a linha passa pelo retangulo ou o retangulo contem a linha
            return False
    return True # Se a linha não passa por nenhum retangulo, ela é visivel
   
#Calcula a distância euclidiana
def distancia(p1, p2):
    return math.dist(p1, p2)  # calcula a distância euclidiana entre dois pontos 

#Desenha os obstáculos e o grafo
def desenhar_grafo(grafo, obstaculos, altura, largura, id_inicio=None, id_final=None, caminho=None):
    plt.figure(figsize=(10, 8))
    plt.axis([0, largura, altura, 0])  # Inverte o eixo Y como no SVG 
     
    posicoes = nx.get_node_attributes(grafo, 'pos') #Pega a posição de cada nó no grafo. 
 
    # Define cores por tipo de nó
    cores_nos = []
    for node in grafo.nodes:
        if node == id_inicio:
            cores_nos.append('green')
        elif node == id_final:
            cores_nos.append('red')
        else:
            cores_nos.append('blue') 

    nx.draw(grafo, pos=posicoes, node_color=cores_nos, edge_color='gray', node_size=20) #Desenha o grafo com os nós e arestas.
   
    if caminho:
        edges = list(zip(caminho, caminho[1:]))
        nx.draw_networkx_edges(grafo, posicoes, edgelist=edges, edge_color='orange', width=2)
     
    #Desenha os obstáculos como retângulos cinzas 
    if obstaculos:
        ax = plt.gca()
        for (x, y, w, h) in obstaculos:
            rect = plt.Rectangle((x, y), w, h, color='grey', alpha=0.5)
            ax.add_patch(rect) 

    plt.title(f'Grafo de visibilidade com {len(obstaculos)} Obstáculos')
    plt.tight_layout()
    plt.show()
 
def criar_grafo(svg_file):
    obstaculos, largura_svg, altura_svg = extrair_retangulos(svg_file)

    grafo = nx.Graph()
    pontos = []
 
    #Adiciona os cantos dos retângulos na lista pontos
    for (x, y, w, h) in obstaculos:
        pontos.extend([
            (x, y),             # canto superior esquerdo
            (x + w, y),         # canto superior direito
            (x, y + h),         # canto inferior esquerdo
            (x + w, y + h)      # canto inferior direito
        ])

    ponto_inicial = (25, 235)
    ponto_final = (750, 235)

    id_inicio = len(pontos)
    id_final = len(pontos) + 1

    grafo.add_node(id_inicio, pos=ponto_inicial)
    grafo.add_node(id_final, pos=ponto_final)

    pontos.append(ponto_inicial)
    pontos.append(ponto_final)

    for i, ponto in enumerate(pontos):
        grafo.add_node(i, pos=ponto)
 
    # Monta a lista das arestas proibidas (bordas dos retângulos)
    arestas_proibidas = set()
    idx = 0 
    total_obstaculos = len(obstaculos)
    for (x, y, w, h) in obstaculos:
        # Cada retângulo tem 4 cantos na ordem:
        # idx, idx+1, idx+2, idx+3
        # Definimos as arestas do retângulo (bordas) entre esses cantos:
        # superior: idx - idx+1
        # esquerda: idx - idx+2
        # direita: idx+1 - idx+3
        # inferior: idx+2 - idx+3
        arestas_proibidas.add( (idx, idx+1) )
        arestas_proibidas.add( (idx+1, idx+3) )
        arestas_proibidas.add( (idx+3, idx+2) )
        arestas_proibidas.add( (idx+2, idx) )
        # também adiciona as arestas inversas, pois o grafo é não-direcional
        arestas_proibidas.add( (idx+1, idx) )
        arestas_proibidas.add( (idx+3, idx+1) )
        arestas_proibidas.add( (idx+2, idx+3) )
        arestas_proibidas.add( (idx, idx+2) )
        idx += 4 
          
    print(f"[DEBUG] Total de obstáculos: {total_obstaculos}, Total de cantos esperados: {total_obstaculos * 4}, Cantos contados: {idx}") 

    #Agora adiciona as arestas, pulando as proibidas
    for i in range(len(pontos)):
        for j in range(i + 1, len(pontos)): 
            if (i, j) in arestas_proibidas or (j, i) in arestas_proibidas:
                print(f"[DEBUG] Ignorando aresta proibida: ({i}, {j})")
                continue 

            p1 = grafo.nodes[i]['pos']
            p2 = grafo.nodes[j]['pos'] 
            
            if visibilidade(p1, p2, obstaculos):
                peso = distancia(p1, p2)
                grafo.add_edge(i, j, weight=peso)   

    return grafo, obstaculos, largura_svg, altura_svg, id_inicio, id_final, pontos

def mostrar_grafo(grafo, obstaculos, altura_svg, largura_svg, id_inicio, id_final, pontos):
    print(f"Total de obstáculos (retângulos): {len(obstaculos)}")
    print(f"Total de pontos (cantos + inicial/final): {len(pontos)}")  # contando que ainda não adicionou os pontos extras  

    print("Lista de adjacência com pesos (arestas visíveis):")
    for u in grafo.nodes:
        vizinhos = grafo[u]
        print(f"Nó {u} ->", end=" ")
        for v, dados in vizinhos.items():
            peso = dados.get('weight', 1)  # default 1 se não tiver peso
            print(f"(destino: {v}, peso: {peso:.2f})", end="; ")
        print()  # quebra de linha após cada nó  

    desenhar_grafo(grafo, obstaculos, altura_svg, largura_svg, id_inicio, id_final)
 
# Calcula o caminho mínimo usando Dijkstra 
def calcular_rota(grafo, id_inicio, id_final):
    caminho = nx.dijkstra_path(grafo, source=id_inicio, target=id_final, weight='weight') 
    print(f"Caminho mínimo (Dijkstra): {caminho}")
    return caminho
 
def menu():
    print("\n===== MENU PRINCIPAL =====")
    print("1. Mapeamento inicial (listar obstáculos)")
    print("2. Modelagem do grafo com obstaculos de visibilidade") 
    print("3. Modelagem do grafo sem obstaculos de visibilidade") 
    print("4. Mostrar grafo com rota")
    print("5. Sair")
    return input("Escolha uma opção: ") 
    
if __name__ == "__main__":
    svg_file = 'input1.svg' 

    # Criar o grafo na inicialização para garantir que ele exista
    grafo, obstaculos, largura, altura, id_inicio, id_final, pontos = criar_grafo(svg_file)
    caminho = None

    while True:
        opcao = menu()

        if opcao == '1':
            mostrar_obstaculos(svg_file)

        elif opcao == '2':
            mostrar_grafo(grafo, obstaculos, altura, largura, id_inicio, id_final, pontos)
            print("✅ Grafo de visibilidade com obstaculos criado.")
 
        elif opcao == '3':
            mostrar_grafo(grafo, [] , altura, largura, id_inicio, id_final, pontos)
            print("✅ Grafo de visibilidade criado (SEM obstáculos).")  

        elif opcao == '4':
                caminho = calcular_rota(grafo, id_inicio, id_final)
                desenhar_grafo(grafo, obstaculos, altura, largura, id_inicio, id_final, caminho)

        elif opcao == '5':
            print("👋 Encerrando o programa.")
            break

        else:
            print("Opção inválida. Tente novamente.")

    


