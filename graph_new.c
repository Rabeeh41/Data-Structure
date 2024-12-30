#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES] = {0};
int visited[MAX_VERTICES] = {0};
int vertices;

void bfs(int start) {
    int queue[MAX_VERTICES], front = -1, rear = -1;
    visited[start] = 1;
    queue[++rear] = start;
    
    printf("BFS: ");
    while (front != rear) {
        front++;
        int node = queue[front];
        printf("%d ", node);

        for (int i = 0; i < vertices; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
    printf("\n");
}

void dfs(int node) {
    printf("%d ", node);
    visited[node] = 1;
    
    for (int i = 0; i < vertices; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

void dfs_start(int start) {
    memset(visited, 0, sizeof(visited)); // Reset visited array
    printf("DFS: ");
    dfs(start);
    printf("\n");
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    for (int i = 0; i < vertices; i++) {
        int v;
        printf("\nFor vertex %d, choose vertices to connect to:\n", i);
        while (1) {
            printf("Enter vertex index to connect (or -1 to stop): ");
            scanf("%d", &v);

            if (v == -1) break;

            if (v >= 0 && v < vertices) {
                graph[i][v] = 1;
                printf("Edge added from %d to %d.\n", i, v);
            } else {
                printf("Invalid vertex index! Please enter a valid index.\n");
            }
        }
    }

    // Display the adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    while (1) {
        int choice;
        printf("\nChoose an operation:\n");
        printf("1. BFS\n");
        printf("2. DFS (from a specific vertex)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Exiting program.\n");
            break;
        }

        switch (choice) {
            case 1: {
                int start;
                printf("Enter starting vertex index for BFS: ");
                scanf("%d", &start);
                if (start >= 0 && start < vertices) {
                    memset(visited, 0, sizeof(visited)); // Reset visited array
                    bfs(start);
                } else {
                    printf("Invalid starting vertex index.\n");
                }
                break;
            }
            case 2: {
                int start;
                printf("Enter starting vertex index for DFS: ");
                scanf("%d", &start);
                if (start >= 0 && start < vertices) {
                    dfs_start(start);
                } else {
                    printf("Invalid starting vertex index.\n");
                }
                break;
            }
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
