#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the circular linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        newNode->next = newNode;  // Point to itself for the first node
        return newNode;
    }

    newNode->next = head->next;
    head->next = newNode;

    return head;
}

// Function to insert a node at the end of the circular linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        newNode->next = newNode;  // Point to itself for the first node
        return newNode;
    }

    newNode->next = head->next;
    head->next = newNode;
    head = newNode;  // Update head to the new last node

    return head;
}

// Function to print the elements of the circular linked list
void printCircularLinkedList(struct Node* head) {
    if (head == NULL) {
        printf("Circular Linked List is empty.\n");
        return;
    }

    struct Node* current = head->next;  // Start from the first actual node
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head->next);
    printf("(head)\n");
}

// Function to free the memory allocated for the circular linked list
void freeCircularLinkedList(struct Node* head) {
    if (head == NULL) {
        return;
    }

    struct Node* current = head->next;
    struct Node* nextNode;

    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != head->next);
}

int main() {
    struct Node* head = NULL;

    // Insert elements at the beginning
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 1);

    // Print the circular linked list
    printf("Circular Linked List after inserting at the beginning: ");
    printCircularLinkedList(head);

    // Insert elements at the end
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);

    // Print the circular linked list
    printf("Circular Linked List after inserting at the end: ");
    printCircularLinkedList(head);

    // Free the memory allocated for the circular linked list
    freeCircularLinkedList(head);

    return 0;
}