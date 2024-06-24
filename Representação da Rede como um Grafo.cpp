#include <iostream>
#include <vector>

using namespace std;

// Estrutura para representar uma aresta do grafo
struct Edge {
    int dest;
    int weight;

    Edge(int d, int w) : dest(d), weight(w) {}
};

// Função para adicionar uma aresta ao grafo
void addEdge(vector<vector<Edge>>& graph, int src, int dest, int weight) {
    graph[src].push_back(Edge(dest, weight));
    graph[dest].push_back(Edge(src, weight)); // Se for um grafo direcionado, remover esta linha
}

// Função para imprimir o grafo
void printGraph(vector<vector<Edge>>& graph) {
    for (int i = 0; i < graph.size(); ++i) {
        cout << "Nó " << i << " conectado a:\n";
        for (auto& edge : graph[i]) {
            cout << "  Nó " << edge.dest << " com peso " << edge.weight << "\n";
        }
        cout << "\n";
    }
}

int main() {
    int numNodes = 5; // Número de nós na rede
    vector<vector<Edge>> graph(numNodes);

    // Exemplo de adição de arestas (configuração do grafo)
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 2, 1);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 1, 3, 5);
    addEdge(graph, 2, 3, 2);
    addEdge(graph, 2, 4, 1);
    addEdge(graph, 3, 4, 3);

    // Exibir o grafo para verificação
    cout << "Representação do Grafo:\n";
    printGraph(graph);

    return 0;
}
