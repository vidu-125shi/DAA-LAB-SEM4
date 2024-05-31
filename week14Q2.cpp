#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int v, vector<bool>& visited, const vector<vector<int>>& adjMatrix, stack<int>& stk) {
    visited[v] = true;
    for (int u = 0; u < adjMatrix[v].size(); ++u) {
        if (adjMatrix[v][u] && !visited[u]) {
            dfs(u, visited, adjMatrix, stk);
        }
    }
    stk.push(v);
}

int findMotherVertex(const vector<vector<int>>& adjMatrix) {
    int V = adjMatrix.size();
    vector<bool> visited(V, false);
    stack<int> stk;

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            dfs(i, visited, adjMatrix, stk);
        }
    }

    fill(visited.begin(), visited.end(), false);
    int mother = stk.top();
    dfs(mother, visited, adjMatrix, stk);

    for (bool visit : visited) {
        if (!visit) {
            return -1;
        }
    }

    return mother;
}

bool isPathExists(int src, int dest, const vector<vector<int>>& adjMatrix) {
    vector<bool> visited(adjMatrix.size(), false);
    stack<int> stk;
    dfs(src, visited, adjMatrix, stk);
    return visited[dest];
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> adjMatrix(V, vector<int>(V, 0));
    cout << "Enter the edges:\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
    }

    int motherVertex = findMotherVertex(adjMatrix);

    if (motherVertex != -1) {
        cout << "Mother vertex found: " << motherVertex << endl;
    } else {
        cout << "No mother vertex found" << endl;
    }

    int src, dest;
    cout << "Enter the source and destination vertices to check if a path exists: ";
    cin >> src >> dest;

    if (isPathExists(src, dest, adjMatrix)) {
        cout << "There exists a path from vertex " << src << " to vertex " << dest << endl;
    } else {
        cout << "There is no path from vertex " << src << " to vertex " << dest << endl;
    }

    return 0;
}

