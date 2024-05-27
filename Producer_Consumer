#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_QUEUE_SIZE 5

pthread_mutex_t mutex;
int queue[MAX_QUEUE_SIZE];
int front = -1, rear = -1;

void enqueue(int item) {
    pthread_mutex_lock(&mutex);
    if ((front == 0 && rear == MAX_QUEUE_SIZE - 1) || (rear == (front - 1) % (MAX_QUEUE_SIZE - 1))) {
        printf("\nQueue is Full!!\n");
        pthread_mutex_unlock(&mutex);
        return;
    } else if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX_QUEUE_SIZE - 1 && front != 0) {
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = item;
    pthread_mutex_unlock(&mutex);
}

int dequeue() {
    pthread_mutex_lock(&mutex);
    if (front == -1) {
        printf("\nQueue is Empty!!\n");
        pthread_mutex_unlock(&mutex);
        return -1;
    }
    int data = queue[front];
    queue[front] = -1;
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX_QUEUE_SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
    pthread_mutex_unlock(&mutex);
    return data;
}

void* producer(void *arg) {
    int item = 1;
    while (1) {
        enqueue(item);
        printf("\nProduced item: %d", item);
        item++;
        sleep(1);
    }
}

void* consumer(void *arg) {
    int item;
    while (1) {
        item = dequeue();
        if (item != -1) {
            printf("\nConsumed item: %d", item);
        }
        sleep(2);
    }
}

int main() {
    pthread_t producer_thread, consumer_thread;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}
