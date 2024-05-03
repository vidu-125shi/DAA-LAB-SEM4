#include <iostream>
#include <vector>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max()

void shortestPathKEdges(vector<vector<vector<int>>>& graph, int V, int K) {
    vector<vector<vector<int>>> dist(V, vector<vector<int>>(V, vector<int>(K + 1, INF)));

    // Initialize distance for source to destination with 0 edges
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            dist[i][j][0] = graph[i][j][0];
        }
    }

    // Compute shortest path using exactly k edges
    for (int e = 1; e <= K; ++e) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                dist[i][j][e] = dist[i][j][e - 1];
                for (int x = 0; x < V; ++x) {
                    if (dist[i][x][e - 1] != INF && dist[x][j][0] != INF) {
                        dist[i][j][e] = min(dist[i][j][e], dist[i][x][e - 1] + dist[x][j][0]);
                    }
                }
            }
        }
    }

    int shortestDist = dist[0][V - 1][K];
    if (shortestDist == INF)
        cout << "No path with exactly " << K << " edges exists.\n";
    else
        cout << "Shortest distance from source to destination with " << K << " edges: " << shortestDist << endl;
}

int main() {
    int V; 
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<vector<int>>> graph(V, vector<vector<int>>(V, vector<int>(1, INF)));
    cout << "Enter the adjacency matrix (enter -1 for no edge):\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            int weight;
            cin >> weight;
            if (weight != -1) {
                graph[i][j][0] = weight;
            }
        }
    }

    int K; 
    cout << "Enter the number of edges to consider: ";
    cin >> K;

    shortestPathKEdges(graph, V, K);

    return 0;
}
