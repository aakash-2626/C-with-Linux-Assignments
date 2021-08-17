/*
 * Program to max sliding window.
 * To run -> Test on Leetcode Question No. 239. 
 * Aakash Singla, (1910990070), 14/08/2021
 * Assignment 4 - Stacks and Queues
 */

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

// checks if the deque is empty.
// return : int -> 1 if deque is empty else 0.
int isEmpty() {
    if(head == NULL && tail == NULL) {
        return 1;
    }

    return 0;
}


// -------------------------------------------------------------
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {

    *returnSize = numsSize - k + 1;
    int* res = (int*) malloc(*returnSize * sizeof(int));
    int ind = 0;

    for(int i = 0; i < numsSize; i++) {
        if(isEmpty() == 0 && getFirst() == i - k)
            removeFirst();

        while(isEmpty() == 0 && nums[getLast()] < nums[i])
            removeLast();

        addLast(i);
        if(i >= k - 1)
            res[ind++] = nums[getFirst()];
    }

    head = NULL;
    tail = NULL;

    return res;
}
