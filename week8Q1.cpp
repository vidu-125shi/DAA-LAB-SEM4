#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int minKey(vector<int>& key, vector<bool>& inMST, int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!inMST[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

int primMST(vector<vector<int>>& graph, int V) {
    vector<int> parent(V);
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, inMST, V);
        inMST[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int minWeight = 0;
    for (int i = 1; i < V; i++) {
        minWeight += graph[i][parent[i]];
    }

    return minWeight;
}

int main() {

    int V;
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }

    int minWeight = primMST(graph, V);
    cout << "Minimum Spanning Weight: " << minWeight << endl;

    return 0;
}
