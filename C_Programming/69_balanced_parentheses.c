#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
void push(struct Stack* stack, char ch);
char pop(struct Stack* stack);
bool areParenthesesBalanced(char* expression);

int main() {
    char expression[MAX_SIZE];

    printf("Enter an expression: ");
    fgets(expression, MAX_SIZE, stdin);

    if (areParenthesesBalanced(expression)) {
        printf("Parentheses are balanced.\n");
    } else {
        printf("Parentheses are not balanced.\n");
    }

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
void push(struct Stack* stack, char ch) {
    stack->array[++stack->top] = ch;
}

// Function to check if parentheses are balanced in an expression
bool areParenthesesBalanced(char* expression) {
    struct Stack* stack = createStack(strlen(expression));
    int i = 0;

    while (expression[i] != '\0') {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(stack, expression[i]);
        } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (isEmpty(stack)) {
                return false; // Closing parenthesis with no corresponding opening parenthesis
            }

            char top = pop(stack);

            // Check if the closing parenthesis matches the corresponding opening parenthesis
            if ((expression[i] == ')' && top != '(') ||
                (expression[i] == ']' && top != '[') ||
                (expression[i] == '}' && top != '{')) {
                return false;
            }
        }

        i++;
    }

    // Check if there are any unmatched opening parentheses left
    return isEmpty(stack);
}