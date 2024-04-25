    
#include <stdio.h>
#include <stdlib.h>

int V;
int** adj;
int isCyclicUtil(int v, int* visited, int* recStack);


int isCyclic() {
    int* visited = (int*)calloc(V, sizeof(int));
    int* recStack = (int*)calloc(V, sizeof(int));

    // Call the recursive helper function to detect cycle in different DFS trees
    for (int i = 0; i < V; i++)
        if (!visited[i] && isCyclicUtil(i, visited, recStack))
            return 1;

    free(visited);
    free(recStack);
    return 0;
}

// DFS function to find if a cycle exists
int isCyclicUtil(int v, int* visited, int* recStack) {
    if (!visited[v]) {
        // Mark the current node as visited and part of recursion stack
        visited[v] = 1;
        recStack[v] = 1;

        // Recur for all the vertices adjacent to this vertex
        for (int i = 0; i < V; i++) {
            if (adj[v][i]) {
                if (!visited[i] && isCyclicUtil(i, visited, recStack))
                    return 1;
                else if (recStack[i])
                    return 1;
            }
        }
    }
    recStack[v] = 0;
    return 0;
}

int main() {
    V = 4;
    adj = (int**)calloc(V, sizeof(int*));
    for (int i = 0; i < V; i++)
        adj[i] = (int*)calloc(V, sizeof(int));

    adj[0][1] = 1;
    adj[0][2] = 1;
    adj[1][3] = 1;
   
    adj[2][3] = 1;


    if (isCyclic())
        printf("Graph contains cycle\n");
    else
        printf("Graph doesn't contain cycle\n");

    for (int i = 0; i < V; i++)
        free(adj[i]);
    free(adj);

    return 0;
}

