#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graphStructs.h"

#define MAX_VERTICES 20

// Function to print the MST
void printMST(int parent[], int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    printf("Edge   Weight\n");
    for (int i = 1; i < numVertices; i++)
        printf("%c - %c   %d \n", (char)(65 + parent[i]), (char)(65+ i), graph[i][parent[i]]);
}

int minKey(int key[], int mstSet[], int numVertices) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < numVertices; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    int parent[numVertices]; // Array to store constructed MST
    int key[numVertices];    // Key values used to pick minimum weight edge in cut
    int mstSet[numVertices]; // To represent set of vertices not yet included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < numVertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Always include first vertex in MST.
    key[0] = 0; // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < numVertices - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet, numVertices);

        // Add the picked vertex to the MST Set
        mstSet[u] = 1;

        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < numVertices; v++) {
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            printf("BEFORE: graph[%c][%c]: %d || mstSet[v]: %d || parent[%c]: %d || key[v]: %d\n", (char)65+u, (char)65+v, graph[u][v], mstSet[v], (char)65+v, parent[v], key[v]);
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
            printf("AFTER: graph[%c][%c]: %d || mstSet[v]: %d || parent[%c]: %d || key[v]: %d\n\n", (char)65+u, (char)65+v, graph[u][v], mstSet[v], (char)65+v, parent[v], key[v]);

        }
    }

    // Print the constructed MST
    printMST(parent, graph, numVertices);
}