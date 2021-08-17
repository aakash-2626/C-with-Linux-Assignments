/*
 * Program that converts an arithmetic expression from infix notation to postfix notation.
 * Command for Compilation -> gcc -o infix_to_postfix infix_to_postfix.c
 * Command for Execution -> ./infix_to_postfix
 * Aakash Singla, (1910990070), 10/08/2021
 * Assignment 4 - Stacks and Queues
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// -----Implementation of Stack and its functions-------
typedef struct Stack{
    char* data;
    int top;
    int stack_size;
} Stack;

// creates and initializes stack.
// return : Stack* -> pointer to the stack structure
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (char*)calloc(100, sizeof(char));
    stack->top = -1;
    stack->stack_size = 100;

    return stack;
}

// checks if stack is empty or not.
// param : Stack* st -> stack pointer
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
    st->data = (char*)realloc(st->data,st->stack_size * sizeof(char));
}

// pushes the given element to the stack
// param : stack pointer, char val to push
// return : void
void push(Stack* st, char val) {
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


// ---------------------------------------------------------
int isOperand(char ch) {
    if(ch >= 48 && ch <= 57) {
        return 1;
    }

    return 0;
}

int precedence(char ch) {
    switch(ch) {
        case '+':
        case '-':
                return 1;
        case '*':
        case '/':
                return 2;
    }

    return -1;
}
char* getPostfix(char* str) {
    char* res = (char*) malloc(strlen(str) * sizeof(char));
    Stack* stack = createStack();
    int k = -1;

    for(int i = 0; str[i] != '\0' ; i++) {
        if(isOperand(str[i]) == 1) {
            res[++k] = str[i];
        }
        else if(str[i] == '(') {
            push(stack, str[i]);
        }
        else if(str[i] == ')') {
            while(!isEmpty(stack) && peek(stack) != '(') {
                res[++k] = pop(stack);
            }
            if(isEmpty(stack) == 1) {
                return NULL;
            }
            else {
                pop(stack);
            }
        }
        else {
            if(isEmpty(stack) == 0) {
                char top = peek(stack);
                while(!isEmpty(stack) && precedence(top) >= precedence(str[i])) {
                    res[++k] = pop(stack);
                    if(!isEmpty(stack)) {
                        top = peek(stack);
                    }
                }
            }
            push(stack, str[i]);
        }
    }

    while(isEmpty(stack) == 0) {
        char popped = pop(stack);
        if(popped == '(') {
            return NULL;
        }
        res[++k] = popped;
    }

    res[++k] = '\0';
    free(stack);
    return res;
}

int main() {
    char str[1000];

    printf("\nEnter the String :\n");
    scanf("%[^\n]s",str);

    char* postfixExp = getPostfix(str);
    if(postfixExp != NULL) {
        printf("\nPostfix Expression :\n%s\n", postfixExp);
    } else {
        printf("\nInvalid Expression\n");
    }

    free(postfixExp);
    return 0;
}
