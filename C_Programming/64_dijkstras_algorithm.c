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

        // Initialize the matrix with infinity values
        for (int j = 0; j < numVertices; j++) {
            graph->adjacencyMatrix[i][j] = INT_MAX;
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    graph->adjacencyMatrix[src][dest] = weight;
    graph->adjacencyMatrix[dest][src] = weight;  // Assuming an undirected graph
}

// Function to find the vertex with the minimum distance value
int minDistance(int* distance, int* visited, int numVertices) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < numVertices; v++) {
        if (!visited[v] && distance[v] <= min) {
            min = distance[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Function to print the result
void printSolution(int* distance, int numVertices) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%d \t\t %d\n", i, distance[i]);
    }
}

// Dijkstra's algorithm
void dijkstra(struct Graph* graph, int startVertex) {
    int numVertices = graph->numVertices;
    int* distance = (int*)malloc(numVertices * sizeof(int));
    int* visited = (int*)malloc(numVertices * sizeof(int));

    // Initialize distance values and visited array
    for (int i = 0; i < numVertices; i++) {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }

    // Distance from the source to itself is always 0
    distance[startVertex] = 0;

    for (int count = 0; count < numVertices - 1; count++) {
        int u = minDistance(distance, visited, numVertices);

        visited[u] = 1;

        // Update distance value of adjacent vertices
        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && graph->adjacencyMatrix[u][v] != INT_MAX &&
                distance[u] != INT_MAX &&
                distance[u] + graph->adjacencyMatrix[u][v] < distance[v]) {
                distance[v] = distance[u] + graph->adjacencyMatrix[u][v];
            }
        }
    }

    // Print the solution
    printSolution(distance, numVertices);

    // Free allocated memory
    free(distance);
    free(visited);
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

    // Perform Dijkstra's algorithm starting from vertex 0
    dijkstra(graph, 0);

    // Free allocated memory
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjacencyMatrix[i]);
    }
    free(graph->adjacencyMatrix);
    free(graph);

    return 0;
}