#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Define a structure for an adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Define a structure for an adjacency list
struct AdjList {
    struct Node* head;
};

// Define a structure for a graph
struct Graph {
    int numVertices;
    struct AdjList* array;
};

// Function to create a new adjacency list node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (graph == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    graph->numVertices = numVertices;

    graph->array = (struct AdjList*)malloc(numVertices * sizeof(struct AdjList));
    if (graph->array == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < numVertices; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since the graph is undirected, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to perform Depth-First Search (DFS) on the graph
void DFS(struct Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* current = graph->array[vertex].head;
    while (current != NULL) {
        if (!visited[current->vertex]) {
            DFS(graph, current->vertex, visited);
        }
        current = current->next;
    }
}

int main() {
    int numVertices = 5;
    struct Graph* graph = createGraph(numVertices);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);

    // Initialize an array to track visited vertices
    int* visited = (int*)malloc(numVertices * sizeof(int));
    if (visited == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Initialize visited array to 0 (not visited)
    for (int i = 0; i < numVertices; ++i) {
        visited[i] = 0;
    }

    // Perform DFS starting from vertex 0
    printf("Depth-First Search (DFS) starting from vertex 0: ");
    DFS(graph, 0, visited);
    printf("\n");

    // Free the memory allocated for the graph and visited array
    free(graph->array);
    free(graph);
    free(visited);

    return 0;
}