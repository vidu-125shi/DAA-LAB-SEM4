#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX

// Structure to represent a node and its corresponding weight
struct Node {
    int vertex;
    int weight;
};

// Custom comparator for priority queue
struct CompareNode {
    bool operator()(const Node& n1, const Node& n2) {
        return n1.weight > n2.weight; // Min-heap based on weight
    }
};

// Function to perform Prim's algorithm and return the minimum cost
int primMST(const vector<vector<pair<int, int>>>& graph, int V) {
    vector<bool> inMST(V, false); // To keep track of vertices included in MST
    vector<int> key(V, INF); // To store key values used to pick the minimum weight edge
    int minCost = 0; // Initialize result

    // Priority queue to store vertices that are being considered for MST
    priority_queue<Node, vector<Node>, CompareNode> pq;

    // Start with vertex 0
    pq.push({0, 0}); // Vertex 0 has no incoming edge, so weight is 0
    key[0] = 0; // Key value of vertex 0 is 0

    while (!pq.empty()) {
        int u = pq.top().vertex;
        pq.pop();

        // Add vertex u to MST
        inMST[u] = true;
        minCost += key[u];

        // Update key values of adjacent vertices of u
        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // If v is not in MST and the weight of the edge is less than the current key of v
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({v, key[v]});
            }
        }
    }

    return minCost;
}

int main() {
    int V; // Number of vertices
    cout << "Enter the number of cities: ";
    cin >> V;

    vector<vector<pair<int, int>>> graph(V); // Graph representation as adjacency list

    int E; // Number of edges
    cout << "Enter the number of roads: ";
    cin >> E;

    cout << "Enter the edges and their weights (source destination weight):" << endl;
    for (int i = 0; i < E; ++i) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        // Assuming the vertices are 0-indexed
        graph[src].push_back({dest, weight});
        graph[dest].push_back({src, weight}); // For undirected graph
    }

    int minCost = primMST(graph, V);
    cout << "Minimum cost to connect cities: " << minCost << endl;

    return 0;
}
