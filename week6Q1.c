
#include <stdio.h>
#include<stdlib.h>
#define MAX 100

int visited[MAX];
int graph[MAX][MAX];
int vertices;

void DFS(int source, int destination) {
    visited[source] = 1;
     int f=0;
    for (int i = 0; i < vertices; i++) { 

        if (graph[source][i] == 1 && !visited[i]) {
           
            if (i == destination) {
                printf("Yes, Path Exists\n");
                f=1;
                break;
            }
            DFS(i, destination);
        }
    }
    if(f == 0){
        printf("No sych path exists\n");
    }
}

int main() {
    int source, destination;
    
    printf("Enter the number of vertices \n");
    scanf("%d", &vertices);
  
    printf("Enter the adjacency matrix\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("Enter source vertex number: ");
    scanf("%d", &source);
    
    printf("Enter destination vertex number: ");
    scanf("%d", &destination);
    
    
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }
    
    DFS(source, destination);
    
    
    
    return 0;
}
