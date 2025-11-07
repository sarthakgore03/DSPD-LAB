//SarthakGore-IT-B-172
#include <stdio.h>
#define MAX 100
struct Edge {
    int u, v, w;
};

int findParent(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = findParent(parent, parent[i]);
}
void unionSet(int parent[], int rank[], int x, int y) {
    int xroot = findParent(parent, x);
    int yroot = findParent(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}
int main() {
    struct Edge edges[MAX];
    int n, e;
    int i, j, totalCost = 0, edgeCount = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter %d edges (u v w):\n", e);
    for (i = 0; i < e; i++) {
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    for (i = 0; i < e - 1; i++) {
        for (j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
    int parent[MAX], rank[MAX];
    for (i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    printf("\nEdges in the Minimum Spanning Tree:\n");

    for (i = 0; i < e && edgeCount < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        int setU = findParent(parent, u);
        int setV = findParent(parent, v);

        if (setU != setV) {
            printf("%d - %d : %d\n", u, v, w);
            totalCost += w;
            edgeCount++;
            unionSet(parent, rank, setU, setV);
        }
    }

    printf("\nTotal cost of Minimum Spanning Tree = %d\n", totalCost);

    return 0;
}
