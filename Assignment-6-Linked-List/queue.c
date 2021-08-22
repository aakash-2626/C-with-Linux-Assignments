/**
* Program for implementing queue and its functions.
* Command for Compilation -> gcc -o queue queue.c
* Command for Execution -> ./queue
* Aakash Singla (1910990070), 20 August 2021
* Assignment 6 - Linked List
*/

#include <stdio.h>
#include <stdlib.h>

// -----------Implementation of Queue and its functions------------
typedef struct Node {
    int value;
    struct Node* next;
} Node;


Node* head = NULL;   // pointer pointing to the front of the queue.
Node* tail = NULL;   // pointer pointing to the rear of the queue.

// enqueues the val into the queue.
void enqueue(int val) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = val;
    node->next = NULL;

    if(head == NULL && tail == NULL) {
        head = tail = node;
        return;
    }

    tail->next = node;
    tail = tail->next;
}

// dequeues the element from the queue.
int dequeue() {
    if(head == NULL && tail == NULL) {
        return -1;
    }

    int val = head->value;
    if(head == tail) {
        head = tail = NULL;
        return val;
    }

    head = head->next;
    return val;
}

// returns 1 if queue is empty else 0.
int is_empty() {
    if(head == NULL && tail == NULL) {
        return 1;
    }
    
    return 0;
}

// returns the element at the front of the queue.
int peek() {
    if(head == NULL && tail == NULL) {
        return -1;
    }

    int val = head->value;
    return val;
}

int main() {
    while(1) {
        int choice = 0;
        int num = 0;

        printf("\nWhich operation do you want to do?\n");
        printf("1. Enqueue element in the queue\n");
        printf("2. Dequeue element from the queue\n");
        printf("3. Get Front element in the queue\n");
        printf("4. Chech if Queue is empty or not\n");
        printf("5. Exit\n\n");

        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("\nEnter the number to enqueue :\n");
                scanf("%d", &num);
                enqueue(num);
                break;
            case 2:
                printf("\nDequeued element from the Queue is %d\n", dequeue());
                break;
            case 3:
                printf("\nFront element in the queue is %d\n", peek());
                break;
            case 4:
                if(is_empty(num) == 1) {
                    printf("\nQueue is Empty.\n");
                } else {
                    printf("\n\nQueue is not Empty.\n\n");
                }
                break;
            case 5:
                exit(1);
        }
    }

    return 0;
}

