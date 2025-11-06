//SarthakGore-IT-B-172
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100
#define INF INT_MAX

void dijkstra(int graph[MAX][MAX], int n, int start) {
    int distance[MAX];      
    bool visited[MAX];    
    int parent[MAX];       
    int i, count, u, v;

   
    for (i = 1; i <= n; i++) {
        distance[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }

    distance[start] = 0;

    
    for (count = 1; count <= n - 1; count++) {
        int min = INF;
    
        for (i = 1; i <= n; i++) {
            if (!visited[i] && distance[i] <= min) {
                min = distance[i];
                u = i;
            }
        }

        visited[u] = true;

       
        for (v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] && distance[u] != INF &&
                distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    
    printf("\nShortest distances from node %d:\n", start);
    for (i = 1; i <= n; i++) {
        if (distance[i] == INF)
            printf("Node %d : -1 (unreachable)\n", i);
        else
            printf("Node %d : %d\n", i, distance[i]);
    }

    
    printf("\nShortest Path Tree (Parent -> Child edges):\n");
    for (i = 1; i <= n; i++) {
        if (parent[i] != -1)
            printf("%d -> %d (weight %d)\n", parent[i], i, graph[parent[i]][i]);
    }
}

int main() {
    int graph[MAX][MAX];
    int n, e, i;
    int u, v, w;
    int start;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v w):\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;  
    }

    printf("Enter starting node: ");
    scanf("%d", &start);

    dijkstra(graph, n, start);

    return 0;
}
