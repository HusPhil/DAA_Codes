#include <limits.h>

#define MAX_VERTICES 100
#define MAX_EDGES (MAX_VERTICES * (MAX_VERTICES - 1) / 2)

void printMST(int parent[], int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    int total_w = 0;

    printf("Edge   Weight\n");
    for (int i = 1; i < numVertices; i++){
        total_w += graph[i][parent[i]];
        printf("%c - %c   %d \n", (char)(65 + parent[i]), (char)(65+ i), graph[i][parent[i]]);
    }
    printf("\nTotal weight: %d\n", total_w);

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
    int parent[numVertices]; 
    int key[numVertices]; 
    int mstSet[numVertices];

    for (int i = 0; i < numVertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    
    key[0] = 0; 
    parent[0] = -1; 

  
    for (int count = 0; count < numVertices - 1; count++) {
        int u = minKey(key, mstSet, numVertices);
        printf("MIN KEY or Vertex with MIN_WEIGHT: %c\n\n", (char)(65+u));

        mstSet[u] = 1;
        for (int v = 0; v < numVertices; v++) {

            printf("BEFORE: graph[%c][%c]: %d || mstSet[%d]: %d || parent[%d]: %d || key[%d]: %d\n", (char)65+u, (char)65+v, graph[u][v], v, mstSet[v], v, parent[v], v, key[v]);
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
            printf("AFTER: graph[%c][%c]: %d || mstSet[%d]: %d || parent[%d]: %d || key[%d]: %d\n\n", (char)65+u, (char)65+v, graph[u][v], v, mstSet[v], v, parent[v], v, key[v]);

        }
    }
    printMST(parent, graph, numVertices);
}