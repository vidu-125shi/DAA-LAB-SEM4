#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Edge {
    int src, dest, weight;
};
void bellmanFord(const vector<Edge>& edges, int V, int src) {
    // Initialize distance array with infinity
    vector<int> distance(V, numeric_limits<int>::max());
    distance[src] = 0; // Distance from source to itself is 0

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; ++i) {
        for (const auto& edge : edges) {
            int u = edge.src;
            int v = edge.dest;
            int weight = edge.weight;
            if (distance[u] != numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }


    for (const auto& edge : edges) {
        int u = edge.src;
        int v = edge.dest;
        int weight = edge.weight;
        if (distance[u] != numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
            cout << "Graph contains negative weight cycle\n";
            return;
        }
    }

    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": Distance = " << distance[i] << endl;
    }
}

int main() {
    int V; 
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<Edge> edges;


    cout << "Enter the adjacency matrix (enter -1 for no edge):\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            int weight;
            cin >> weight;
            if (weight != -1) {
                edges.push_back({i, j, weight});
            }
        }
    }

    int src; 
    cout << "Enter the source vertex number: ";
    cin >> src;

    bellmanFord(edges, V, src);

    return 0;
}
