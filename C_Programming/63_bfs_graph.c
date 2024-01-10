#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Queue structure for BFS
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// Function to create a new queue
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to add an item to the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Function to remove an item from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Graph structure
struct Graph {
    int numVertices;
    int** adjMatrix;
};

// Function to create a new graph
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    // Allocate memory for adjacency matrix
    graph->adjMatrix = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++) {
            graph->adjMatrix[i][j] = 0; // Initialize with 0
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

// Function to perform BFS on the graph
void BFS(struct Graph* graph, int startVertex) {
    // Create a queue for BFS
    struct Queue* queue = createQueue(MAX_VERTICES);

    // Array to keep track of visited vertices
    int visited[MAX_VERTICES];
    for (int i = 0; i < MAX_VERTICES; i++)
        visited[i] = 0;

    // Enqueue the start vertex and mark it as visited
    enqueue(queue, startVertex);
    visited[startVertex] = 1;

    printf("Breadth-First Search starting from vertex %d: ", startVertex);

    while (!isEmpty(queue)) {
        // Dequeue a vertex and print it
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        // Visit all adjacent vertices of the dequeued vertex
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                // Enqueue the adjacent vertex if not visited
                enqueue(queue, i);
                visited[i] = 1;
            }
        }
    }

    free(queue->array);
    free(queue);
}

int main() {
    // Create a graph with 5 vertices
    struct Graph* graph = createGraph(5);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);

    // Perform BFS starting from vertex 0
    BFS(graph, 0);

    // Free allocated memory
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);

    return 0;
}