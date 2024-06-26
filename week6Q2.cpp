#include <iostream>
#include <queue>
#define MAX_V 100  
using namespace std;

bool isBipartite(int G[][MAX_V], int V, int src)
{
    int colorArr[MAX_V];
    for (int i = 0; i < V; ++i)
        colorArr[i] = -1;

    colorArr[src] = 1;

    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (G[u][u] == 1)
            return false; 
        for (int v = 0; v < V; ++v)
        {
            if (G[u][v] && colorArr[v] == -1)
            {
               
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }
            else if (G[u][v] && colorArr[v] == colorArr[u])
                return false;
        }
    }

    return true;
}

int main()
{
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    int G[MAX_V][MAX_V];
    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> G[i][j];
        }
    }

    isBipartite(G, V, 0) ? cout << "Yes Bipartite" : cout << "Not Bipartite";
    return 0;
}
