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

    obstacles = [] #Lista para armazenar os retângulos.

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
 
        #Adiciona o retângulo como uma tupla.
        obstacles.append((x, y, w, h))

    return obstacles, largura, altura #Retorna a lista de obstáculos e o tamanho da imagem.

#Verifica se dois pontos conseguem se ver, se nao tem nenhum objeto entre eles
def visibilidade(p1, p2, obstaculos):
    linha = LineString([p1, p2]) #Cria a linha
    for (x, y, w, h) in obstaculos: #Cria cada obstaculocomo um retangulo
        retangulo = box(x, y, x + w, y + h)
        if linha.crosses(retangulo) or retangulo.contains(linha): #Se a linha passa pelo retangulo ou o retangulo contem a linha
            return False
    return True # Se a linha não passa por nenhum retangulo, ela é visivel
 
#Desenha os obstáculos e o grafo
def desenhar_grafo(grafo, obstaculos, altura, largura, id_inicio=None, id_final=None):
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
  
    #Desenha os obstáculos como retângulos cinzas
    ax = plt.gca()
    for (x, y, w, h) in obstaculos:
        rect = plt.Rectangle((x, y), w, h, color='grey', alpha=0.5)
        ax.add_patch(rect) 

    plt.title(f'Grafo de visibilidade com {len(obstaculos)} Obstáculos')
    plt.tight_layout()
    plt.show()
  
def distancia(p1, p2):
    return math.dist(p1, p2)  # calcula a distância euclidiana entre dois pontos

#Main
def main(arquivo_svg):
    obstaculos, largura, altura = extrair_retangulos(arquivo_svg) 

    grafo = nx.Graph()
    pontos = [] 
 
    #Pega os 4 cantos de cada retângulo
    for (x, y, w, h) in obstaculos:
        pontos.extend([ 
            (x, y),             # canto superior esquerdo
            (x + w, y),         # canto superior direito
            (x, y + h),         # canto inferior esquerdo
            (x + w, y + h)      # canto inferior direito
        ]) 
      
    ponto_inicial = (25, 235) 
    ponto_final = (750, 235)  
     
    id_inicio = len(pontos) # Cada nó tem um id que é o número de pontos que ele representa
    id_final = len(pontos) + 1  
     
    #adicionar eles ao grafo 
    grafo.add_node(id_inicio, pos=ponto_inicial) #adiciona o nó inicial 
    grafo.add_node(id_final, pos=ponto_final) #adiciona o nó final
 
    pontos.append(ponto_inicial) #adiciona o ponto inicial ao array de pontos
    pontos.append(ponto_final) 

    #Adiciona os pontos ao grafo
    for i, ponto in enumerate(pontos):
        grafo.add_node(i, pos=ponto) 
        
    # Liga os pontos visíveis entre si
    for i in range(len(pontos)):
        for j in range(i + 1, len(pontos)):
            p1 = grafo.nodes[i]['pos']
            p2 = grafo.nodes[j]['pos']
            if visibilidade(p1, p2, obstaculos):
                peso = distancia(p1, p2)
                grafo.add_edge(i, j, weight=peso)
     
    print("Lista de adjacência com pesos (arestas visíveis):")
    for u in grafo.nodes:
        vizinhos = grafo[u]
        print(f"Nó {u} ->", end=" ")
        for v, dados in vizinhos.items():
            peso = dados.get('weight', 1)  # default 1 se não tiver peso
            print(f"(destino: {v}, peso: {peso:.2f})", end="; ")
        print()  # quebra de linha após cada nó

    desenhar_grafo(grafo, obstaculos, altura, largura, id_inicio, id_final) #funçãoque desenha o grafo final

if __name__ == "__main__":
    main('input1.svg')
