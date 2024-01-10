#include <stdio.h>
#include <stdlib.h>

// Node structure for the priority queue
struct Node {
    int data;
    int priority;
    struct Node* next;
};

// Priority queue structure
struct PriorityQueue {
    struct Node* front;
};

// Function to initialize the priority queue
void initializePriorityQueue(struct PriorityQueue* pq) {
    pq->front = NULL;
}

// Function to check if the priority queue is empty
int isEmpty(struct PriorityQueue* pq) {
    return (pq->front == NULL);
}

// Function to create a new node with given data and priority
struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    return newNode;
}

// Function to enqueue an element into the priority queue
void enqueue(struct PriorityQueue* pq, int data, int priority) {
    struct Node* newNode = createNode(data, priority);

    // If the priority queue is empty or the new node has higher priority
    if (isEmpty(pq) || priority > pq->front->priority) {
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        // Traverse the list to find the correct position for the new node
        struct Node* current = pq->front;
        while (current->next != NULL && priority <= current->next->priority) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    printf("Enqueued: (%d, %d)\n", data, priority);
}

// Function to dequeue the highest priority element from the priority queue
void dequeue(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority queue is empty. Cannot dequeue.\n");
        return;
    }

    struct Node* temp = pq->front;
    pq->front = pq->front->next;

    printf("Dequeued: (%d, %d)\n", temp->data, temp->priority);

    free(temp);
}

// Function to display the elements of the priority queue
void display(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority queue is empty.\n");
        return;
    }

    struct Node* current = pq->front;
    printf("Priority Queue elements:\n");

    while (current != NULL) {
        printf("(%d, %d) ", current->data, current->priority);
        current = current->next;
    }

    printf("\n");
}

// Function to free the memory allocated for the priority queue
void freePriorityQueue(struct PriorityQueue* pq) {
    while (pq->front != NULL) {
        struct Node* temp = pq->front;
        pq->front = pq->front->next;
        free(temp);
    }
}

int main() {
    struct PriorityQueue pq;
    initializePriorityQueue(&pq);

    enqueue(&pq, 1, 3);
    enqueue(&pq, 2, 1);
    enqueue(&pq, 3, 2);

    display(&pq);

    dequeue(&pq);

    display(&pq);

    enqueue(&pq, 4, 5);
    enqueue(&pq, 5, 4);

    display(&pq);

    freePriorityQueue(&pq);

    return 0;
}