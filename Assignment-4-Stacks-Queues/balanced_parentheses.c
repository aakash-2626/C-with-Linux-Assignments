/*
 * Program that checks whether the sequence of brackets in the given string is balanced or not. 
 * Command for Compilation -> gcc -o balanced_parentheses balanced_parentheses.c
 * Command for Execution -> ./balanced_parentheses
 * Aakash Singla, (1910990070), 09/08/2021
 * Assignment 4 - Stacks and Queues
 */

#include<stdio.h>
#include<stdlib.h>


// ---Implementing Stack and its functions-----
// creating structure for a stack
typedef struct Stack {
    char* data;
    int top;
    int stack_size;
} Stack;

// initializes a stack and returns it.
Stack* initStack() {
    Stack* stk = (Stack*) malloc(sizeof(Stack));
    stk->data = (char*) calloc(20, sizeof(char));
    stk->top = -1;
    stk->stack_size = 20;

    return stk;
}

// checks if stack is empty or not. 
// param : Stack* st - stack pointer
// return : int - 1 if stack is empty else 0.
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
    st->data = (char*) realloc(st->data, st->stack_size * sizeof(char));
}

// pushes the given element to the stack
// param : stack pointer, char val to push
// return : void
void push(Stack* st, char val) {
    // if the size is full, firstly resize the stack
    if(st->top == st->stack_size - 1) {
        resize_stack(st);
    }
    st->data[++st->top] = val;
}

// pops the element from the stack
// param : stack pointer
// return : char value popped
char pop(Stack* st) {
    if(isEmpty(st) == 1) {
        return 0;
    }
    return st->data[st->top--];
}

// returns the peek element from the stack.
// param : stack pointer
// return : char value at the peek.
char peek(Stack* st) {
    if(isEmpty(st) == 1) {
        return 0;
    }
    return st->data[st->top];
}



// ----------------------------------------------------------
// checks whether the sequence of brackets in the given string is balanced or not. 
// param : char* str : input string
// return : int -> 1 if string is balanced else 0.
int check_balanced_str(char* str) {
    Stack* stack = initStack();

    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(stack, str[i]);
        } else {
            if(isEmpty(stack) == 1) {
                return 0;
            }
            char topChar = pop(stack);
            if((str[i] == ')' && topChar != '(') || (str[i] == ']' && topChar != '[') || (str[i] == '}' && topChar != '{')) {
                return 0;
            }
        }
    }

    if(isEmpty(stack) == 1) {
        return 1;
    }
    return 0;
}

int main() {
    char str[100];

    printf("Enter the String:\n");
    scanf("%[^\n]s",str);

    if(check_balanced_str(str) == 1) {
        printf("\ntrue\n");
    } else {
        printf("false\n");
    }

    return 0;
}
