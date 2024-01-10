#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function prototypes
int find(struct Subset subsets[], int i);
void Union(struct Subset subsets[], int x, int y);
void kruskalMST(struct Edge edges[], int V, int E);

// Driver program
int main() {
    // Example graph represented by the edge list
    int V = 4;  // Number of vertices
    int E = 5;  // Number of edges

    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskalMST(edges, V, E);

    return 0;
}

// A utility function to find set of an element i
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// A utility function to perform union of two subsets
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// The main function to construct MST using Kruskal's algorithm
void kruskalMST(struct Edge edges[], int V, int E) {
    // Allocate memory for subsets
    struct Subset *subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

    // Initialize subsets
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // Sort edges in non-decreasing order by weight
    qsort(edges, E, sizeof(edges[0]), [](const void* a, const void* b) {
        return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
    });

    // Initialize result
    struct Edge result[V - 1];
    int e = 0;  // Index for the result array

    // Iterate through all sorted edges
    for (int i = 0; e < V - 1 && i < E; i++) {
        struct Edge next_edge = edges[i];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge doesn't cause a cycle, include it in the result and increment the index for the result array
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    // Print the result
    printf("Edges in the constructed MST:\n");
    for (int i = 0; i < e; i++) {
        printf("(%d, %d) -> %d\n", result[i].src, result[i].dest, result[i].weight);
    }

    // Free allocated memory
    free(subsets);
}