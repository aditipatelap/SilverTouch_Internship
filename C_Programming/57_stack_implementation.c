#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Define a structure for the stack
struct Stack {
    int array[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int element) {
    if (isFull(stack)) {
        printf("Stack overflow. Cannot push element %d.\n", element);
    } else {
        stack->array[++stack->top] = element;
        printf("Pushed %d onto the stack.\n", element);
    }
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop element.\n");
        return -1;
    } else {
        int poppedElement = stack->array[stack->top--];
        printf("Popped %d from the stack.\n", poppedElement);
        return poppedElement;
    }
}

// Function to get the top element of the stack without removing it
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1;
    } else {
        return stack->array[stack->top];
    }
}

// Function to print the elements of the stack
void printStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Elements of the stack: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->array[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack;
    initializeStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printStack(&stack);

    pop(&stack);
    pop(&stack);

    printStack(&stack);

    push(&stack, 4);
    push(&stack, 5);

    printStack(&stack);

    printf("Top element: %d\n", peek(&stack));

    return 0;
}