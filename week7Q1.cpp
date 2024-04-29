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

void dijkstra(vector<vector<Edge>>& graph, int start, vector<int>& dist) {
    int n = graph.size(); // Number of vertices in the graph
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist.assign(n, INT_MAX); // Initialize distances to infinity
    dist[start] = 0; 
    pq.push({0, start}); // Push the start node into the priority queue

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        // If this node has already been visited with a shorter distance, continue
        if (d > dist[u]) continue;

        // Explore neighbors of the current node
        for (const Edge& e : graph[u]) {
            int v = e.to;
            int weight = e.weight;
           
            if (dist[u] + weight < dist[v]) {//relax
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m; // Number of vertices and edges respectively
    cin >> n >> m;

    vector<vector<Edge>> graph(n); // Adjacency list representation of graph

    // Input the edges of the graph
    for (int i = 0; i < m; ++i) {
        int u, v, w; // Edge from u to v with weight w
        cin >> u >> v >> w;
        graph[u].push_back(Edge(v, w));
        graph[v].push_back(Edge(u, w)); // If the graph is undirected
    }

    int start=0;
  

    vector<int> dist; // To store the shortest distances from the starting vertex
    dijkstra(graph, start, dist);

    
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