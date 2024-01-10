#include <stdio.h>

#define MAX_SIZE 5

struct CircularQueue {
    int front, rear;
    int array[MAX_SIZE];
};

// Function to initialize the circular queue
void initializeQueue(struct CircularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue *queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Function to enqueue (insert) an element into the circular queue
void enqueue(struct CircularQueue *queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0; // If the queue is empty, initialize front
    }

    queue->rear = (queue->rear + 1) % MAX_SIZE; // Circular increment
    queue->array[queue->rear] = element;

    printf("%d enqueued to the queue.\n", element);
}

// Function to dequeue (remove) an element from the circular queue
void dequeue(struct CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    printf("%d dequeued from the queue.\n", queue->array[queue->front]);

    if (queue->front == queue->rear) {
        // If only one element is left, reset front and rear
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE; // Circular increment
    }
}

// Function to display the elements of the circular queue
void display(struct CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Circular Queue elements: ");
    int i = queue->front;

    do {
        printf("%d ", queue->array[i]);
        i = (i + 1) % MAX_SIZE; // Circular increment
    } while (i != (queue->rear + 1) % MAX_SIZE);

    printf("\n");
}

int main() {
    struct CircularQueue queue;
    initializeQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);

    display(&queue);

    dequeue(&queue);

    display(&queue);

    enqueue(&queue, 6);

    display(&queue);

    return 0;
}