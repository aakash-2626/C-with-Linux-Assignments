/*
 * Program to implement stack using only two queues. 
 * To Test -> Run on Leetcode Question No. 225
 * Aakash Singla, 1910990070 (10 Aug 2021)
 * Assignment 4 - Stacks and Queues
 */

// ------Implementation of Queue and its Functions------
typedef struct {
    int* data;
    int front;
    int rear;
    int queue_size;
    int count;
} Queue;

// creates and initializes the queue
// return : Queue* -> pointer to the queue structure
Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->data = (int*) calloc(100, sizeof(int));
    queue->front = queue->rear = -1;
    queue->queue_size = 100;
    queue->count = 0;

    return queue;
}

// checks if queue is empty or not.
// param : Queue* q -> pointer to queue.
// return : int -> 1 if queue is empty else 0.
int isEmpty(Queue* q) {
    if(q->front == - 1) {
        return 1;
    }
    return 0;
}

// adds element to the queue.
// param : Queue* q -> pointer to queue, int val -> value to be added in queue.
// return : void.
void enqueue(Queue* q, int val) {
    if(q->count == q->queue_size) {
        return;
    }
    if(q->front == -1) {
        q->data[++q->front] = val;
        q->rear++;
        q->count++;

        return;
    }
    q->rear = (q->rear + 1) % q->queue_size;
    q->data[q->rear] = val;
    q->count++;
}

// removes the first element from queue.
// parameter : Queue* q -> pointer to queue.
// return : int -> value removed
int dequeue(Queue* q) {
    if(isEmpty(q) == 1) {
        return -1;
    }
    int val = q->data[q->front];
    q->front = (q->front + 1) % q->queue_size;
    q->count--;
    if(q->count == 0) {
        q->front = q->rear = -1;
    }

    return val;
}

// returns first element from queue.
// param : Queue* q -> pointer to queue.
// return : int -> first element value.
int peek(Queue* q) {
    if(isEmpty(q) == 1) {
        return -1;
    }
    return q->data[q->front];
}

//structure to implement stack
typedef struct {
    Queue* q1;
    Queue* q2;
} MyStack;

/** Initialize your data structure here. */

//function to create and initialize  stack.
MyStack* myStackCreate() {
    MyStack* stack = (MyStack*) malloc(sizeof(MyStack));
    stack->q1 = createQueue();
    stack->q2 = createQueue();
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if(isEmpty(obj->q1) == 1) {
        enqueue(obj->q1, x);
        shiftElements(obj->q2, obj->q1);
    }
    else {
        enqueue(obj->q2, x);
        shiftElements(obj->q1, obj->q2);
    }
}

//shifts elements from first queue to second queue
void shiftElements(Queue* q1, Queue* q2) {
    while(isEmpty(q1) != 1) {
        enqueue(q2, dequeue(q1));
    }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if(isEmpty(obj->q1) == 1) {
        return dequeue(obj->q2);
    }
    else {
        return dequeue(obj->q1);
    }
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if(isEmpty(obj->q1) == 1) {
        return peek(obj->q2);
    }
    else {
        return peek(obj->q1);
    }
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return (isEmpty(obj->q1) && isEmpty(obj->q2));
}

void myStackFree(MyStack* obj) {
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/
