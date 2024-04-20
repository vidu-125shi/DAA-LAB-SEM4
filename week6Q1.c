// QUESTION 1
/*Given a (directed/undirected) graph, design an algorithm and implement it using a program to
find if a path exists between two given vertices or not. (Hint: use DFS)
Input Format:
Input will be the graph in the form of adjacency matrix or adjacency list.
Source vertex number and destination vertex number is also provided as an input.
Output Format:
Output will be 'Yes Path Exists' if path exists, otherwise print 'No Such Path Exists'.
*/
//Q2
//biparted graph,divide the graph in 2parts,vertices in part 1 must connect to vertices in part but not eachother
//

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
