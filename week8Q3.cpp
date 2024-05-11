#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Comparator function to sort edges in descending order based on weight
bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight > e2.weight;
}

// Structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

// Find operation for union-find
int find(vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union operation for union-find
void unionSets(vector<Subset>& subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to find maximum budget required for the project
int maxBudget(vector<Edge>& edges, int V) {
    int maxBudget = 0;

    // Sort edges in descending order of weight
    sort(edges.begin(), edges.end(), compareEdges);

    vector<Subset> subsets(V);
    for (int i = 0; i < V; ++i) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // Iterate through sorted edges and add them to the MST
    for (auto& edge : edges) {
        int x = find(subsets, edge.src);
        int y = find(subsets, edge.dest);

        if (x != y) {
            maxBudget += edge.weight;
            unionSets(subsets, x, y);
        }
    }

    return maxBudget;
}

int main() {
    int V; // Number of vertices
    cout << "Enter the number of cities: ";
    cin >> V;

    int E; // Number of edges
    cout << "Enter the number of roads: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter the edges and their weights (source destination weight):" << endl;
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    int maxBudgetRequired = maxBudget(edges, V);
    cout << "Maximum budget required for the project: " << maxBudgetRequired << endl;

    return 0;
}
