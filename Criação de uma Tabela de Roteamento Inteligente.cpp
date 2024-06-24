#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define INF INT_MAX // Valor infinito para distâncias

// Estrutura para representar um nó na tabela de roteamento
struct RoutingEntry {
    int next_hop;
    int distance;

    RoutingEntry() : next_hop(-1), distance(INF) {}
};

// Função para atualizar a tabela de roteamento usando Dijkstra
void updateRoutingTable(vector<vector<Edge>>& graph, vector<RoutingEntry>& routingTable, int start) {
    int n = graph.size();
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);
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

    // Preencher a tabela de roteamento com os resultados de Dijkstra
    for (int i = 0; i < n; ++i) {
        routingTable[i].distance = dist[i];
        if (parent[i] != -1)
            routingTable[i].next_hop = parent[i];
    }
}

// Exemplo de uso da tabela de roteamento
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
    addEdge(graph, 3,
