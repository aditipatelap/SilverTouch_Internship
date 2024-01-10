#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// Stack structure
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// Function prototypes
struct Stack* createStack(unsigned capacity);
int isEmpty(struct Stack* stack);
int pop(struct Stack* stack);
void push(struct Stack* stack, int operand);
int evaluatePostfix(char* postfix);

int main() {
    char postfix[MAX_SIZE];

    printf("Enter a postfix expression: ");
    fgets(postfix, MAX_SIZE, stdin);

    int result = evaluatePostfix(postfix);

    printf("Result: %d\n", result);

    return 0;
}

// Function to create a stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return -1; // The value -1 acts as an error code for an empty stack
}

// Function to push an element onto the stack
void push(struct Stack* stack, int operand) {
    stack->array[++stack->top] = operand;
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* postfix) {
    struct Stack* stack = createStack(strlen(postfix));
    int i = 0;

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            push(stack, postfix[i] - '0'); // Convert character to integer
        } else {
            int operand2 = pop(stack);
            int operand1 = pop(stack);

            switch (postfix[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    push(stack, operand1 / operand2);
                    break;
            }
        }

        i++;
    }

    return pop(stack);
}