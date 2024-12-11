#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int n; // Number of vertices
int adj[MAX][MAX]; // Adjacency matrix
int visited[MAX]; // Visited array

void DFS1(int v, int *stack, int *top) {
    visited[v] = 1;
    for (int i = 1; i <= n; i++) {
        if (adj[v][i] && !visited[i]) {
            DFS1(i, stack, top);
        }
    }
    stack[(*top)++] = v;
}

void DFS2(int v, int transpose[MAX][MAX]) {
    printf("%d ", v);
    visited[v] = 1;
    for (int i = 1; i <= n; i++) {
        if (transpose[v][i] && !visited[i]) {
            DFS2(i, transpose);
        }
    }
}

void findSCCs() {
    int stack[MAX], top = 0;
    int transpose[MAX][MAX];

    // Step 1: Perform a DFS to fill the stack with finishing times
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            DFS1(i, stack, &top);
        }
    }

    // Step 2: Transpose the graph
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            transpose[i][j] = adj[j][i];
        }
    }

    // Step 3: Perform a DFS on the transposed graph in the order of decreasing finishing times
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }
    
    printf("Strongly Connected Components:\n");
    while (top > 0) {
        int v = stack[--top];
        if (!visited[v]) {
            DFS2(v, transpose);
            printf("\n");
        }
    }
}

void printAdjacencyMatrix() {
    printf("Adjacency Matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

