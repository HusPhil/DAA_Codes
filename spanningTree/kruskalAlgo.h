// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for disjoint set
struct Subset {
    int parent;
    int rank;
};


struct Edge edges[MAX_EDGES];
int parent[MAX_VERTICES];
int rank[MAX_VERTICES];


// Function to create a new subset
void makeSet(int v) {
    parent[v] = v;
    rank[v] = 0;
}

// Function to find the subset of an element 'v'
int find(int v) {
    if (parent[v] != v)
        parent[v] = find(parent[v]);
    return parent[v];
}

// Function to perform union of two subsets
void unionSets(int x, int y) {
    int xroot = find(x);
    int yroot = find(y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

// Function to compare two edges based on their weights
int compareEdges(const void *a, const void *b) {
    struct Edge *edge1 = (struct Edge *)a;
    struct Edge *edge2 = (struct Edge *)b;
    return edge1->weight - edge2->weight;
}

// Kruskal's algorithm to find Minimum Spanning Tree
void kruskalMST(int graph[MAX_VERTICES][MAX_VERTICES]) {
    int numEdges = 0;
    struct Edge result[MAX_VERTICES];
    
    // Step 1: Initialize disjoint sets
    for (int i = 0; i < MAX_VERTICES; i++)
        makeSet(i);

    // Step 2: Store all the edges in a list
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = i + 1; j < MAX_VERTICES; j++) {
            if (graph[i][j] != 0) {
                edges[numEdges].src = i;
                edges[numEdges].dest = j;
                edges[numEdges].weight = graph[i][j];
                numEdges++;
            }
        }
    }

    // Step 3: Sort all the edges in non-decreasing order of their weight
    qsort(edges, numEdges, sizeof(edges[0]), compareEdges);

    // Step 4: Iterate through all the edges in sorted order
    int e = 0; // Index variable for result[]
    for (int i = 0; i < numEdges; i++) {
        int x = find(edges[i].src);
        int y = find(edges[i].dest);
        
        // If including this edge does not cause cycle, include it in result and union the sets
        if (x != y) {
            result[e++] = edges[i];
            unionSets(x, y);
        }
    }

    // Step 5: Print the MST
    int total_w = 0;
    printf("Edges in MST:\n");
    for (int i = 0; i < e; i++) {
        total_w += result[i].weight;
        printf("%c - %c: %d\n", (char)(65+result[i].src), (char)(65+result[i].dest), result[i].weight);
    }
    printf("Total weight: %d\n", total_w);

}