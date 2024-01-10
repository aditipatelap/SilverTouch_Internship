#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

// Structure to represent a graph
struct Graph {
    int numVertices;
    int** adjacencyMatrix;
};

// Function to create a new graph
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    // Allocate memory for the adjacency matrix
    graph->adjacencyMatrix = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyMatrix[i] = (int*)malloc(numVertices * sizeof(int));

        // Initialize the matrix with zero values
        for (int j = 0; j < numVertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    graph->adjacencyMatrix[src][dest] = weight;
    graph->adjacencyMatrix[dest][src] = weight;  // Assuming an undirected graph
}

// Function to find the vertex with the minimum key value
int minKey(int* key, int* mstSet, int numVertices) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < numVertices; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Function to print the minimum spanning tree
void printMST(int* parent, struct Graph* graph) {
    printf("Edge   Weight\n");
    for (int i = 1; i < graph->numVertices; i++) {
        printf("%d - %d    %d\n", parent[i], i, graph->adjacencyMatrix[i][parent[i]]);
    }
}

// Prim's algorithm
void prim(struct Graph* graph) {
    int numVertices = graph->numVertices;
    int* parent = (int*)malloc(numVertices * sizeof(int));
    int* key = (int*)malloc(numVertices * sizeof(int));
    int* mstSet = (int*)malloc(numVertices * sizeof(int));

    // Initialize key values and mstSet array
    for (int i = 0; i < numVertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Include the first vertex in the MST
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < numVertices - 1; count++) {
        int u = minKey(key, mstSet, numVertices);

        mstSet[u] = 1;

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < numVertices; v++) {
            if (graph->adjacencyMatrix[u][v] && !mstSet[v] && graph->adjacencyMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph->adjacencyMatrix[u][v];
            }
        }
    }

    // Print the minimum spanning tree
    printMST(parent, graph);

    // Free allocated memory
    free(parent);
    free(key);
    free(mstSet);
}

int main() {
    // Create a graph with 5 vertices
    struct Graph* graph = createGraph(5);

    // Add edges to the graph with their weights
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 2, 4);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 3, 7);
    addEdge(graph, 2, 4, 3);
    addEdge(graph, 3, 4, 1);

    // Perform Prim's algorithm
    prim(graph);

    // Free allocated memory
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjacencyMatrix[i]);
    }
    free(graph->adjacencyMatrix);
    free(graph);

    return 0;
}