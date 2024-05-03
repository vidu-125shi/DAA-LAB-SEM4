#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

int main() {
    int n, m; 
    cin >> n >> m;

    vector<vector<Edge>> graph(n); 
    
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(Edge(v, w));
        graph[v].push_back(Edge(u, w)); 
    }

    int start=0;
  

    vector<int> dist; // To store the shortest distances from the starting vertex
 //   bellmanford(graph, start, dist);

    
    cout << "Shortest distances from vertex " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "Vertex " << i << ": ";
        if (dist[i] == INT_MAX) {
            cout << "INF";
        } else {
            cout << dist[i];
        }
        cout << endl;
    }

    return 0;
}