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

void dijkstra(vector<vector<Edge>>& graph, int start, vector<int>& dist, vector<int>& prev) {
    int n = graph.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist.assign(n, INT_MAX);
    prev.assign(n, -1);

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (const Edge& e : graph[u]) {
            int v = e.to;
            int weight = e.weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

void printShortestPath(int source, int destination, const vector<int>& prev, const vector<int>& dist) {
    if (dist[destination] == INT_MAX) {
        cout << "No path from " << source << " to " << destination << endl;
        return;
    }

    vector<int> path;
    for (int v = destination; v != -1; v = prev[v]) {
        path.push_back(v);
    }

    for (int i = path.size() - 1; i >= 0; --i) {
        cout << path[i];
        if (i != 0) cout << " -> ";
    }
    cout << ", Distance: " << dist[destination] << endl;
}

int main() {
    int V, source;
    cin >> V >> source;

    vector<vector<Edge>> graph(V);

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            int weight;
            cin >> weight;
            if (weight != 0) {
                graph[i].push_back(Edge(j, weight));
            }
        }
    }

    vector<int> dist, prev;
     cout<<endl<<"OUTPUT"<<endl;
    for (int i = 0; i < V; ++i) {
        dijkstra(graph, i, dist, prev);
          
        printShortestPath(i, source, prev, dist);
    }

    return 0;
}
