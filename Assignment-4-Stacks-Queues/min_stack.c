/*
 * Program to design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * To Check -> Run on Leetcode Question 155.
 * Aakash Singla, 1910990070 (13 August, 2021)
 * Assignment 4 - Stacks and Queues
 */
 
// -----Implementation of Stack and its functions-----
// structure for the stack
typedef struct Stack {
    int* data;
    int top;
    int stack_size;
} Stack;

// creates and initialzes the stack and returns it.
// return : pointer to the stack structure
Stack* createStack() {
    Stack* stk = (Stack*) malloc(sizeof(Stack));
    stk->data = (int*) calloc(20, sizeof(int));
    stk->top = -1;
    stk->stack_size = 20;

    return stk;
}

// checks if stack is empty or not.
// param : Stack* st - stack pointer
// return : int -> 1 if stack is empty else 0.
int isEmpty(Stack* st) {
    if(st->top == - 1) {
        return 1;
    }
    return 0;
}

// resizes the stack to double of the current size.
// param : stack pointer
// return : void
void resize_stack(Stack* st) {
    st->stack_size *= 2;
    st->data = (int*) realloc(st->data,st->stack_size * sizeof(int));
}

// pushes the given element to the stack
// param : stack pointer, int val to push
// return : void
void push(Stack* st, int val) {
    if(st->top == st->stack_size - 1) {
        resize_stack(st);
    }
    st->data[++st->top] = val;
}

// pops the element from the stack
// param : stack pointer
// return : int value popped
int pop(Stack* st) {
    if(isEmpty(st) == 1) {
        printf("Stack is Empty\n");
        return -1;
    }
    return st->data[st->top--];
}

// returns the peek element from the stack.
// param : stack pointer
// return : int value at the peek.
int peek(Stack* st) {
    if(isEmpty(st) == 1) {
        printf("Stack is Empty\n");
        return -1;
    }
    return st->data[st->top];
}

// structure to store data of minstack.
typedef struct {
    Stack* stack;
    Stack* min;
} MinStack;

/** initialize your data structure here. */

// creates and initializes minstack
// return : MinStack* -> pointer to the minstack structure.
MinStack* minStackCreate() {
    MinStack* minStack = (MinStack*) malloc(sizeof(MinStack));
    minStack->stack = createStack();
    minStack->min = createStack();

    return minStack;
}

// pushes the data data to given minStack.
// param : MinStack* obj -> pointer to MinStack, int val: value to be inserted
// return : void
void minStackPush(MinStack* obj, int val) {	
    push(obj->stack, val);
    if(isEmpty(obj->min) == 1) {
        push(obj->min,val);
    }
    else {
        int top = peek(obj->min);
        if(val <= top) {
            push(obj->min, val);
        }
    }
}

// pops the element from given minStack.
// param : MinStack* obj -> pointer to MinStack
// return : void
void minStackPop(MinStack* obj) {
    int val = pop(obj->stack);
    if(peek(obj->min) == val) {
	pop(obj->min);
    }
}

// returns the top element of the stack.
// param : MinStack* obj -> pointer to MinStack
// return int : top element
int minStackTop(MinStack* obj) {
    return peek(obj->stack);
}

// returns minimum value from given minStack.
// param : MinStack* obj -> pointer to MinStack
// return : int -> minimum value in stack
int minStackGetMin(MinStack* obj) {
    return peek(obj->min);
}

// free the memory assigned to given minStack.
// param : MinStack* obj -> pointer to MinStack
// return : void
void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/
