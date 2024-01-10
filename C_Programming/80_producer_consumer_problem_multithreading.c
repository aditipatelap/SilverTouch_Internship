#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5
#define NUM_PRODUCERS 2
#define NUM_CONSUMERS 2

int buffer[BUFFER_SIZE];
int itemCount = 0;
int in = 0;
int out = 0;

sem_t empty, full, mutex;

void* producer(void* arg) {
    int item;
    int producerID = *(int*)arg;

    while (1) {
        item = rand() % 100 + 1;  // Produce an item

        sem_wait(&empty);
        sem_wait(&mutex);

        // Critical section: add item to the buffer
        buffer[in] = item;
        printf("Producer %d produced item %d\n", producerID, item);
        in = (in + 1) % BUFFER_SIZE;
        itemCount++;

        sem_post(&mutex);
        sem_post(&full);

        // Simulate some time for the producer to do other work
        sleep(1);
    }

    pthread_exit(NULL);
}

void* consumer(void* arg) {
    int item;
    int consumerID = *(int*)arg;

    while (1) {
        sem_wait(&full);
        sem_wait(&mutex);

        // Critical section: remove item from the buffer
        item = buffer[out];
        printf("Consumer %d consumed item %d\n", consumerID, item);
        out = (out + 1) % BUFFER_SIZE;
        itemCount--;

        sem_post(&mutex);
        sem_post(&empty);

        // Simulate some time for the consumer to process the item
        sleep(2);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t producers[NUM_PRODUCERS], consumers[NUM_CONSUMERS];
    int producerIDs[NUM_PRODUCERS], consumerIDs[NUM_CONSUMERS];

    // Initialize semaphores
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    // Create producer threads
    for (int i = 0; i < NUM_PRODUCERS; i++) {
        producerIDs[i] = i + 1;
        pthread_create(&producers[i], NULL, producer, &producerIDs[i]);
    }

    // Create consumer threads
    for (int i = 0; i < NUM_CONSUMERS; i++) {
        consumerIDs[i] = i + 1;
        pthread_create(&consumers[i], NULL, consumer, &consumerIDs[i]);
    }

    // Wait for threads to finish (this won't happen in this example)
    for (int i = 0; i < NUM_PRODUCERS; i++) {
        pthread_join(producers[i], NULL);
    }

    for (int i = 0; i < NUM_CONSUMERS; i++) {
        pthread_join(consumers[i], NULL);
    }

    // Destroy semaphores
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}