/*
 * Program to return the area of the largest rectangle in the histogram.
 * To Check -> Run on Leetcode Question 84.
 * Aakash Singla, 1910990070 (12 August, 2021)
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

int largestRectangleArea(int* heights, int n){
    Stack* stk = createStack();
    int maxArea = 0;

    for(int i = 0; i <= n; i++) {
        while(isEmpty(stk) == 0 && (i == n || heights[peek(stk)] > heights[i])) {
            int height = heights[pop(stk)];
            int leftSmaller = isEmpty(stk) == 0 ? peek(stk) : -1;
            int width = i - leftSmaller - 1;

            int area = height * width;
            maxArea = area > maxArea ? area : maxArea;
        }

        push(stk, i);
    }

    return maxArea;
}
