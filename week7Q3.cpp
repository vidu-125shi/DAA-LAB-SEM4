#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int main() {
    int V;
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }

    int source, destination, k;
    cin >> source >> destination >> k;

    vector<vector<vector<int>>> dp(V, vector<vector<int>>(V, vector<int>(k + 1, INF)));

    for (int i = 0; i < V; ++i) {
        dp[i][i][0] = 0;
    }

    for (int e = 1; e <= k; ++e) {
        for (int u = 0; u < V; ++u) {
            for (int v = 0; v < V; ++v) {
                if (graph[u][v] != 0) {
                    for (int i = 0; i < V; ++i) {
                        if (dp[u][i][e - 1] != INF && graph[i][v] != 0) {
                            dp[u][v][e] = min(dp[u][v][e], dp[u][i][e - 1] + graph[i][v]);
                        }
                    }
                }
            }
        }
    }

    if (dp[source][destination][k] == INF) {
        cout << "no path of length " << k << " is available" << endl;
    } else {
        cout << "Weight of shortest path from (" << source << ", " << destination << ") with " << k << " edges: " << dp[source][destination][k] << endl;
    }

    return 0;
}
