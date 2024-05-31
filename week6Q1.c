#include <stdio.h>
#include <stdbool.h>

#define MAX 100 

bool DFS(int graph[MAX][MAX], int numVertices, int src, int dest, bool visited[MAX]) {
    if (src == dest) {
        return true;
    }

    visited[src] = true;

    for (int i = 0; i < numVertices; i++) {
        if (graph[src][i] == 1 && !visited[i]) {
            if (DFS(graph, numVertices, i, dest, visited)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int numVertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    int graph[MAX][MAX];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int src, dest;
    printf("Enter the source vertex: ");
    scanf("%d", &src);
    printf("Enter the destination vertex: ");
    scanf("%d", &dest);

    bool visited[MAX] = { false };

    if (DFS(graph, numVertices, src, dest, visited)) {
        printf("A path exists between vertex %d and vertex %d.\n", src, dest);
    } else {
        printf("No path exists between vertex %d and vertex %d.\n", src, dest);
    }

    return 0;
}
