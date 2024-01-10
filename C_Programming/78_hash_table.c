#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Node structure for the linked list at each index of the hash table
struct Node {
    char key[50];
    int value;
    struct Node* next;
};

// Hash table structure
struct HashTable {
    struct Node* table[TABLE_SIZE];
};

// Hash function to map a key to an index in the hash table
unsigned int hashFunction(const char* key) {
    unsigned int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = (hash * 31) + key[i];
    }
    return hash % TABLE_SIZE;
}

// Function to initialize the hash table
void initializeHashTable(struct HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
}

// Function to insert a key-value pair into the hash table
void insert(struct HashTable* ht, const char* key, int value) {
    unsigned int index = hashFunction(key);

    // Create a new node for the key-value pair
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    // Copy the key and set the value
    strcpy(newNode->key, key);
    newNode->value = value;
    newNode->next = NULL;

    // Insert the new node at the beginning of the linked list at the specified index
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

// Function to retrieve the value associated with a key from the hash table
int get(struct HashTable* ht, const char* key) {
    unsigned int index = hashFunction(key);
    struct Node* current = ht->table[index];

    // Traverse the linked list at the specified index
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value; // Key found, return the associated value
        }
        current = current->next;
    }

    return -1; // Key not found
}

// Function to display the contents of the hash table
void display(struct HashTable* ht) {
    printf("Hash Table contents:\n");

    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Node* current = ht->table[i];

        while (current != NULL) {
            printf("[%d] Key: %s, Value: %d\n", i, current->key, current->value);
            current = current->next;
        }
    }
}

// Function to free the memory allocated for the hash table
void freeHashTable(struct HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Node* current = ht->table[i];

        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main() {
    struct HashTable ht;
    initializeHashTable(&ht);

    // Insert key-value pairs into the hash table
    insert(&ht, "John", 25);
    insert(&ht, "Alice", 30);
    insert(&ht, "Bob", 22);
    insert(&ht, "Eve", 28);

    // Display the contents of the hash table
    display(&ht);

    // Retrieve values associated with keys
    printf("Value for key 'Alice': %d\n", get(&ht, "Alice"));
    printf("Value for key 'Bob': %d\n", get(&ht, "Bob"));
    printf("Value for key 'Charlie': %d\n", get(&ht, "Charlie")); // Not found

    // Free the memory allocated for the hash table
    freeHashTable(&ht);

    return 0;
}