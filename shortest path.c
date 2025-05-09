#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MAX 100

int minDistance(int dist[], int visited[], int V) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printSolution(int dist[], int V, int src) {
    printf("\nShortest distances from vertex %d:\n", src);
    for (int i = 0; i < V; i++)
        printf("To %d \t-> %d\n", i, dist[i]);
}

void dijkstra(int **graph, int V, int src) {
    int dist[MAX], visited[MAX];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, visited[i] = 0;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        if (u == -1) break; 
        visited[u] = 1;

        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist, V, src);
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    
    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        graph[i] = (int *)calloc(V, sizeof(int));

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges in format: source destination weight\n");
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        
    }

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, V, src);

   
    for (int i = 0; i < V; i++)
        free(graph[i]);
    free(graph);

    return 0;
}
