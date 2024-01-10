#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Stack structure
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Function prototypes
struct Stack* createStack(unsigned capacity);
int isEmpty(struct Stack* stack);
char peek(struct Stack* stack);
char pop(struct Stack* stack);
void push(struct Stack* stack, char op);
int isOperand(char ch);
int precedence(char op);
char* infixToPostfix(char* infix);

int main() {
    char infix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    char* postfix = infixToPostfix(infix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

// Function to create a stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to return the top element of the stack
char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$'; // The dollar sign acts as a placeholder for an empty stack
}

// Function to push an element onto the stack
void push(struct Stack* stack, char op) {
    stack->array[++stack->top] = op;
}

// Function to check if a character is an operand
int isOperand(char ch) {
    return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// Function to determine the precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to convert infix to postfix
char* infixToPostfix(char* infix) {
    struct Stack* stack = createStack(strlen(infix));
    char* postfix = (char*)malloc((strlen(infix) + 1) * sizeof(char));
    int i, j;
    i = j = 0;

    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        } else if (infix[i] == '(') {
            push(stack, infix[i++]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) != '(')
                return NULL; // Invalid expression
            else
                pop(stack);
            i++;
        } else {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack))) {
                postfix[j++] = pop(stack);
            }
            push(stack, infix[i++]);
        }
    }

    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';

    return postfix;
}