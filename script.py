import networkx as nx
import matplotlib.pyplot as plt
import xml.etree.ElementTree as ET
from shapely.geometry import LineString, box
 
#O SVG é baseado em XML, que é uma linguagem de marcação hierárquica (em árvore).
def extrair_retangulos(svg_file): 
    #Ler e manipular arquivos SVG
    tree = ET.parse(svg_file) #Transforma o arquivo em uma árvore de elementos. Cada tag vira um nó da árvore e pode navegar para baixo (filhos) ou para cima (pai). A vantagem é o acesso direto aos elementos.
    root = tree.getroot()

    viewBox = root.get('viewBox', '0 0 100 100')
    _, _, largura, altura = map(float, viewBox.split())

    obstacles = []

    for rect in root.iter('{http://www.w3.org/2000/svg}rect'):
        x = float(rect.get('x', 0))
        y = float(rect.get('y', 0))
 
        #Remove o % 
        w_str = rect.get('width', '0').replace('%', '')
        h_str = rect.get('height', '0').replace('%', '')

        w = float(w_str) if w_str else 0.0
        h = float(h_str) if h_str else 0.0

        obstacles.append((x, y, w, h))

    return obstacles, largura, altura

#Verifica se dois pontos conseguem se ver, se nao tem nenhum objeto entre eles
def visibilidade(p1, p2, obstaculos):
    linha = LineString([p1, p2])
    for (x, y, w, h) in obstaculos:
        retangulo = box(x, y, x + w, y + h)
        if linha.crosses(retangulo) or retangulo.contains(linha):
            return False
    return True
 
#Desenha os obstáculos e o grafo
def desenhar_grafo(grafo, obstaculos, altura, largura):
    plt.figure(figsize=(10, 8))
    plt.axis([0, largura, altura, 0])  # Inverte o eixo Y como no SVG 
     
    posicoes = nx.get_node_attributes(grafo, 'pos')
    nx.draw(grafo, pos=posicoes, node_color='red', edge_color='gray', node_size=20) 

    ax = plt.gca()
    for (x, y, w, h) in obstaculos:
        rect = plt.Rectangle((x, y), w, h, color='grey', alpha=0.5)
        ax.add_patch(rect) 

    plt.title(f'Grafo de visibilidade com {len(obstaculos)} Obstáculos')
    plt.tight_layout()
    plt.show()
 
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
     
    #Adiciona os pontos ao grafo
    for i, ponto in enumerate(pontos):
        grafo.add_node(i, pos=ponto)
 
    #Liga os pontos visíveis entre si
    for i, p1 in enumerate(pontos):
        for j in range(i + 1, len(pontos)):
            p2 = pontos[j]
            if visibilidade(p1, p2, obstaculos):
                grafo.add_edge(i, j)

    desenhar_grafo(grafo, obstaculos, altura, largura)

if __name__ == "__main__":
    main('input.svg')
