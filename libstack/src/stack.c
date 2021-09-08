#include <stdlib.h>
#include <stack.h>

void stack_init(Stack *stack) {
    stack->size = 0;
}

void stack_destroy(Stack *stack) {
    StackNode *top = stack->top;
    StackNode *prev;
    while(top->prev) {
        prev = top->prev;
        free(top);
        top = prev;
    }
    free(top);
}

void stack_push(Stack *stack, void *val) {
    StackNode *next = (StackNode *)malloc(sizeof(StackNode));
    next->prev = stack->top;
    next->val = val;
    stack->top = next;
    stack->size++;
}

void *stack_pop(Stack *stack) {
    void *val = stack_peek(stack);

    StackNode *prev = stack->top->prev;
    free(stack->top);
    stack->top = prev;
    stack->size--;
    return val;
}

void *stack_peek(Stack *stack) {
    if(stack->top == 0) return 0;
    return stack->top->val;
}