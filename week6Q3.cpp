#include <iostream>
#include <vector>

using namespace std;

bool isCyclicUtil(int v, vector<bool>& visited, vector<bool>& recStack, vector<vector<int>>& adj) {
    if (!visited[v]) {
        visited[v] = true;
        recStack[v] = true;

        for (int neighbor : adj[v]) {
            if (!visited[neighbor] && isCyclicUtil(neighbor, visited, recStack, adj))
                return true;
            else if (recStack[neighbor])
                return true;
        }
    }

    recStack[v] = false;
    return false;
}

bool isCyclic(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for (int i = 0; i < V; i++) {
        if (isCyclicUtil(i, visited, recStack, adj))
            return true;
    }

    return false;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter the edges (source destination pairs):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    if (isCyclic(V, adj))
        cout << "Graph contains a cycle" << endl;
    else
        cout << "Graph does not contain a cycle" << endl;

    return 0;
}
