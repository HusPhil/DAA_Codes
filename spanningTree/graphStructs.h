// struct Edge {
//     int source, dest, weight;
// };

// struct Graph {
//     int numVertices;
//     int numEdges;
//     struct Edge* edges;
// };

// struct Graph* createGraph(int numVertices, int numEdges) {
//     struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
//     graph->numVertices = numVertices;
//     graph->numEdges = numEdges;
//     graph->edges = (struct Edge*)malloc(numEdges * sizeof(struct Edge));
//     return graph;
// }

// void addEdge(struct Graph* graph, int source, int dest, int weight) {
//     graph->edges[source].source = source;
//     graph->edges[source].dest = dest;
//     graph->edges[source].weight = weight;
// }

