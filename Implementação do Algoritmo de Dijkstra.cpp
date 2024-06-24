#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX // Valor infinito para distâncias

typedef pair<int, int> pii; // Pair para armazenar distância e nó

// Função para calcular caminho mais curto usando Dijkstra
void dijkstra(vector<vector<Edge>>& graph, int start, vector<int>& dist, vector<int>& parent) {
    int n = graph.size();
    dist.assign(n, INF);
    parent.assign(n, -1);
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto& edge : graph[u]) {
            int v = edge.dest;
            int weight = edge.weight;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

// Exemplo de uso do algoritmo de Dijkstra
int main() {
    int n = 5; // Número de nós na rede
    vector<vector<Edge>> graph(n);

    // Exemplo de adição de arestas (configuração do grafo)
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 2, 1);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 1, 3, 5);
    addEdge(graph, 2, 3, 2);
    addEdge(graph, 2, 4, 1);
    addEdge(graph, 3, 4, 3);

    vector<int> dist, parent;
    int start_node = 0; // Nó de origem para calcular caminhos
    dijkstra(graph, start_node, dist, parent);

    // Exibindo os caminhos mais curtos a partir do nó de origem
    cout << "Caminhos mais curtos a partir do nó " << start_node << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "Para o nó " << i << ": Distância = " << dist[i] << ", Caminho = ";
        int p = i;
        while (p != -1) {
            cout << p << " ";
            p = parent[p];
        }
        cout << "\n";
    }

    return 0;
}
