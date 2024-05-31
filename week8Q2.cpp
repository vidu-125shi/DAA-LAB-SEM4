#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

int find(vector<int>& parent, int i) {
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]);
    }
    return parent[i];
}

void unionSets(vector<int>& parent, vector<int>& rank, int u, int v) {
    int rootU = find(parent, u);
    int rootV = find(parent, v);
    if (rank[rootU] < rank[rootV]) {
        parent[rootU] = rootV;
    } else if (rank[rootU] > rank[rootV]) {
        parent[rootV] = rootU;
    } else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}

int kruskalMST(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end(), compareEdges);

    vector<int> parent(V);
    vector<int> rank(V, 0);
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int minWeight = 0;
    for (Edge edge : edges) {
        int u = find(parent, edge.u);
        int v = find(parent, edge.v);
        if (u != v) {
            minWeight += edge.weight;
            unionSets(parent, rank, u, v);
        }
    }

    return minWeight;
}

int main() {
    int V;
    cin >> V;

    vector<Edge> edges;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            int weight;
            cin >> weight;
            if (weight != 0) {
                edges.push_back(Edge(i, j, weight));
            }
        }
    }

    int minWeight = kruskalMST(edges, V);
    cout << "Minimum Spanning Weight: " << minWeight << endl;

    return 0;
}
