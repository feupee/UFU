import networkx as nx
import matplotlib.pyplot as plt

# Função para ler o grafo do arquivo e criar o grafo direcionado ponderado
def ler_grafo(nome_arquivo):
    G = nx.DiGraph()
    with open(nome_arquivo, 'r') as file:
        num_vertices, num_arestas = map(int, file.readline().split())
        for _ in range(num_arestas):
            origem, destino, peso = map(int, file.readline().split())
            G.add_edge(origem, destino, weight=peso)
    return G

# Função para plotar o grafo
def plotar_grafo(G):
    pos = nx.spring_layout(G)  # Posições dos nós
    labels = nx.get_edge_attributes(G, 'weight')  # Rótulos das arestas

    # Desenhar nós e arestas
    nx.draw(G, pos, with_labels=True, node_size=900, node_color='skyblue', font_size=20, font_weight='bold')
    nx.draw_networkx_edge_labels(G, pos, edge_labels=labels, font_color='red')

    # Exibir o gráfico
    plt.title("Grafo Ponderado Direcionado")
    plt.show()

# Ler o grafo do arquivo
nome_arquivo = "AreaCentral.txt"  # Altere para o nome do seu arquivo
G = ler_grafo(nome_arquivo)

# Plotar o grafo
plotar_grafo(G)
