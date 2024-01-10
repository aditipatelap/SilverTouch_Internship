#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Define a structure for the queue
struct Queue {
    int array[MAX_SIZE];
    int front, rear;
};

// Function to initialize the queue
void initializeQueue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Function to enqueue (push) an element into the queue
void enqueue(struct Queue* queue, int element) {
    if (isFull(queue)) {
        printf("Queue overflow. Cannot enqueue element %d.\n", element);
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;  // Set front to 0 for the first element
        }
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->array[queue->rear] = element;
        printf("Enqueued %d into the queue.\n", element);
    }
}

// Function to dequeue (pop) an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow. Cannot dequeue element.\n");
        return -1;
    } else {
        int dequeuedElement = queue->array[queue->front];
        if (queue->front == queue->rear) {
            // Reset front and rear to -1 for the last element
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
        printf("Dequeued %d from the queue.\n", dequeuedElement);
        return dequeuedElement;
    }
}

// Function to print the elements of the queue
void printQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Elements of the queue: ");
        int i = queue->front;
        while (i != queue->rear) {
            printf("%d ", queue->array[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d\n", queue->array[queue->rear]);
    }
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printQueue(&queue);

    dequeue(&queue);
    dequeue(&queue);

    printQueue(&queue);

    enqueue(&queue, 4);
    enqueue(&queue, 5);

    printQueue(&queue);

    return 0;
}