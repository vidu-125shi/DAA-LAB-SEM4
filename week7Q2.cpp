#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int from;
    int to;
    int weight;
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};

void bellmanFord(int V, int start, const vector<Edge>& edges, vector<int>& dist, vector<int>& prev) {
    dist.assign(V, INT_MAX);
    prev.assign(V, -1);

    dist[start] = 0;

    for (int i = 0; i < V - 1; ++i) {
        for (const Edge& e : edges) {
            if (dist[e.from] != INT_MAX && dist[e.from] + e.weight < dist[e.to]) {
                dist[e.to] = dist[e.from] + e.weight;
                prev[e.to] = e.from;
            }
        }
    }

    for (const Edge& e : edges) {
        if (dist[e.from] != INT_MAX && dist[e.from] + e.weight < dist[e.to]) {
            cout << "Graph contains a negative-weight cycle" << endl;
            return;
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

    vector<Edge> edges;

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            int weight;
            cin >> weight;
            if (weight != 0) {
                edges.emplace_back(i, j, weight);
            }
        }
    }

    vector<int> dist, prev;
    cout << endl << "OUTPUT" << endl;
    for (int i = 0; i < V; ++i) {
        bellmanFord(V, i, edges, dist, prev);
        printShortestPath(i, source, prev, dist);
    }

    return 0;
}
