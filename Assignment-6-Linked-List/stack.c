/**
* Program for implementing stack and its functions.
* Command for Compilation -> gcc -o stack stack.c
* Command for Execution -> ./stack
* Aakash Singla (1910990070), 20 August 2021
* Assignment 6 - Linked List
*/

#include <stdio.h>
#include <stdlib.h>

// -----------Implementation of Stack and its functions------------
typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;


Node* head = NULL;   // pointer pointing to the element at the last of the stack.
Node* tail = NULL;   // pointer pointing to the element at the top of the stack.

// pushes the val into the stack.
void push(int val) {
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

// pops the element from the stack.
int pop() {
    if(head == NULL && tail == NULL) {
        return -1;
    }

    int val = tail->value;
    if(head == tail) {
        head = tail = NULL;
        return val;
    }

    tail = tail->prev;
    head->next = NULL;

    return val;
}

// returns 1 if stack is empty else 0.
int is_empty() {
    if(head == NULL && tail == NULL) {
        return 1;
    }
    
    return 0;
}

// returns the element at the top of the stack.
int peek() {
    if(head == NULL && tail == NULL) {
        return -1;
    }

    int val = tail->value;
    return val;
}

int main() {
    while(1) {
        int choice = 0;
        int num = 0;

        printf("\nWhich operation do you want to do?\n");
        printf("1. Push element on the stack\n");
        printf("2. Pop element from the stack\n");
        printf("3. Get Peek element of the stack\n");
        printf("4. Chech if Stack is empty or not\n");
        printf("5. Exit\n\n");

        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("\nEnter the number to push :\n");
                scanf("%d", &num);
                push(num);
                break;
            case 2:
                printf("\nPopped element from the stack is %d\n", pop());
                break;
            case 3:
                printf("\nPeek element at the stack is %d\n", peek());
                break;
            case 4:
                if(is_empty(num) == 1) {
                    printf("\nStack is Empty.\n");
                } else {
                    printf("\n\nStack is not Empty.\n\n");
                }
                break;
            case 5:
                exit(1);
        }
    }

    return 0;
}

