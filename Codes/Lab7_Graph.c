//SarthakGore-IT-B-172
#include <stdio.h>
#include <stdlib.h>

#define N 9

int graph[N+1][N+1] = {0}; 
int visited[N+1];

int queue[100], front = 0, rear = 0;
void enqueue(int x) { queue[rear++] = x; }
int dequeue() { return queue[front++]; }

int stack[100], top = -1;
void push(int x) { stack[++top] = x; }
int pop() { return stack[top--]; }

void add_edge(int u, int v) {
    graph[u][v] = graph[v][u] = 1;
}

void BFS(int start) {
    int i;
    for(i=1;i<=N;i++) visited[i] = 0;
    enqueue(start);
    visited[start] = 1;
    printf("BFS Order: ");
    while(front < rear) {
        int node = dequeue();
        printf("%d ", node);
        for(i=1;i<=N;i++) {
            if(graph[node][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

void DFS(int start) {
    int i;
    for(i=1;i<=N;i++) visited[i] = 0;
    
    push(start);
    
    printf("DFS Order: ");
    while(top >= 0) {
        int node = pop();
        if(!visited[node]) {
            visited[node] = 1;
            printf("%d ", node);
            for(i=N;i>=1;i--) {
                if(graph[node][i] && !visited[i]) {
                    push(i);
                }
            }
        }
    }
    printf("\n");
}
int main() {
    add_edge(1,2); add_edge(2,3);
    add_edge(4,5); add_edge(5,6);
    add_edge(7,8); add_edge(8,9);
    add_edge(1,4); add_edge(2,5); add_edge(3,6);
    add_edge(4,7); add_edge(5,8); add_edge(6,9)
    BFS(1);
    DFS(1);
    return 0;
}