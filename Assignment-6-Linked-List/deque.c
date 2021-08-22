/**
* Program for implementing Deque and its functions.
* Command for Compilation -> gcc -o deque deque.c
* Command for Execution -> ./deque
* Aakash Singla (1910990070), 20 August 2021
* Assignment 6 - Linked List
*/

#include <stdio.h>
#include <stdlib.h>

// -----------Implementation of Deque and its functions------------
typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;


Node* head = NULL;   // pointer pointing to the element at the starting of the deque.
Node* tail = NULL;   // pointer pointing to the element at the last of the deque.

// adds the node with value val at the last of the deque.
void addLast(int val) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = val;
    node->next = NULL;
    node->prev = NULL;

    if(head == NULL && tail == NULL) {
        head = tail = node;
        return;
    }

    tail->next = node;
    node->prev = tail;
    tail = node;
}

// adds the node with value val at the starting of the deque.
void addFirst(int val) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = val;
    node->next = NULL;
    node->prev = NULL;

    if(head == NULL && tail == NULL) {
        head = tail = node;
        return;
    }

    head->prev = node;
    node->next = head;
    head = node;
}

// removes and returns the last element of the deque.
int removeLast() {
    if(head == NULL && tail == NULL) {
        return -1;
    }

    int val = tail->value;
    if(head == tail) {
        head = tail = NULL;
        return val;
    }

    tail = tail->prev;
    tail->next = NULL;

    return val;
}

// removes and returns the first element of the deque.
int removeFirst() {
    if(head == NULL && tail == NULL) {
        return -1;
    }

    int val = head->value;
    if(head == tail) {
        head = tail = NULL;
        return val;
    }

    head = head->next;
    head->prev = NULL;

    return val;
}

// returns the last element of the deque.
int getLast() {
    if(head == NULL && tail == NULL) {
        return -1;
    }

    int val = tail->value;
    return val;
}

// returns the first element of the deque.
int getFirst() {
    if(head == NULL && tail == NULL) {
        return -1;
    }

    int val = head->value;
    return val;
}

// checks if given value val is present in deque or not
// return : int -> 1 if val is present else 0.
int search(int val) {
    Node* temp = head;
    while(temp != NULL) {
        if(temp->value == val) {
            return 1;
        }
        temp = temp->next;
    }
    
    return 0;
}

int main() {
    while(1) {
        int choice = 0;
        int num = 0;

        printf("\nWhich operation do you want to do?\n");
        printf("1. Add element at the head\n");
        printf("2. Add element at the tail\n");
        printf("3. Remove and Get element at the head\n");
        printf("4. Remove and Get element at the tail\n");
        printf("5. Get element at the head\n");
        printf("6. Get element at the tail\n");
        printf("7. Search an element in the dequeue\n");
        printf("8. Exit\n\n");

        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("\nEnter the number to add at the head :\n");
                scanf("%d", &num);
                addFirst(num);
                break;
            case 2:
                printf("\nEnter the number to add at the tail :\n");
                scanf("%d", &num);
                addLast(num);
                break;
            case 3:
                printf("\nNumber removed from the head is %d\n", removeFirst());
                break;
            case 4:
                printf("\nNumber removed from the tail is %d\n", removeLast());
                break;
            case 5:
                printf("\nNumber present at the head is %d\n", getFirst());
                break;
            case 6:
                printf("\nNumber present at the tail is %d\n", getLast());
                break;
            case 7:
                printf("\nEnter the number to search :\n");
                scanf("%d", &num);
                int res = search(num);
                if(res == 1) {
                    printf("\n%d is present in the dequeue.\n", num);
                } else {
                    printf("\n%d is not present in the dequeue.\n", num);
                }
                break;
            case 8:
                exit(1);
        }
    }

    return 0;
}

