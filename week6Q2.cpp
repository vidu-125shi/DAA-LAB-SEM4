

#include <iostream>
#include <queue>
#define V 4

using namespace std;
bool isBipartite(int G[][V], int src)
{
	
	int colorArr[V];
	for (int i = 0; i < V; ++i)
		colorArr[i] = -1;

	colorArr[src] = 1;

	
	queue <int> q;//creating a queue and inserting source vertex
	q.push(src);


	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		if (G[u][u] == 1)
		return false; //for self loop

	
		for (int v = 0; v < V; ++v)
		{
			
			if (G[u][v] && colorArr[v] == -1)
			{
				// Assign alternate color to this adjacent v of u
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
	int G[][V] = {{0, 1, 1, 1},
		{1, 0, 1, 0},
		{1, 1, 0, 1},
		{1, 0, 1, 0}
	};

	isBipartite(G, 0) ? cout << "Yes Bipartite" : cout << "Not Bipartite";
	return 0;
}
