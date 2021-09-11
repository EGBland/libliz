#include <stdlib.h>
#include <stack.h>

// helper functions
void stack_push(Stack *, StackValue *);
StackValue *stack_pop(Stack *);
StackValue *stack_peek(Stack *);

void stack_push(Stack *stack, StackValue *val) {
    StackNode *next = (StackNode *)malloc(sizeof(StackNode));
    next->prev = stack->top;
    next->val = val;
    stack->top = next;
    stack->size++;
}

StackValue *stack_pop(Stack *stack) {
    StackValue *val = stack_peek(stack);

    StackNode *prev = stack->top->prev;
    free(stack->top);
    stack->top = prev;
    stack->size--;
    return val;
}

StackValue *stack_peek(Stack *stack) {
    if(stack->top == 0) return 0;
    return stack->top->val;
}

// header implementations
void stack_init(Stack *stack) {
    stack->top = 0;
    stack->size = 0;
}

void stack_destroy(Stack *stack) {
    StackNode *top = stack->top;
    StackNode *prev;
    while(top) {
        free(top->val);
        prev = top->prev;
        free(top);
        top = prev;
    }
}

void stack_pushc  (Stack *stack,          char    c) {
    StackValue *val = (StackValue *)malloc(sizeof(StackValue));
    val->c = c;
    stack_push(stack, val);
}

void stack_pushcu (Stack *stack, unsigned char   cu) {
    StackValue *val = (StackValue *)malloc(sizeof(StackValue));
    val->cu = cu;
    stack_push(stack, val);
}

void stack_pushs  (Stack *stack,          short   s) {
    StackValue *val = (StackValue *)malloc(sizeof(StackValue));
    val->s = s;
    stack_push(stack, val);
}

void stack_pushsu (Stack *stack, unsigned short  su) {
    StackValue *val = (StackValue *)malloc(sizeof(StackValue));
    val->su = su;
    stack_push(stack, val);
}

void stack_pushi  (Stack *stack,          int     i) {
    StackValue *val = (StackValue *)malloc(sizeof(StackValue));
    val->i = i;
    stack_push(stack, val);
}

void stack_pushiu (Stack *stack, unsigned int    iu) {
    StackValue *val = (StackValue *)malloc(sizeof(StackValue));
    val->iu = iu;
    stack_push(stack, val);
}

void stack_pushl  (Stack *stack,          long    l) {
    StackValue *val = (StackValue *)malloc(sizeof(StackValue));
    val->l = l;
    stack_push(stack, val);
}

void stack_pushlu (Stack *stack, unsigned long   lu) {
    StackValue *val = (StackValue *)malloc(sizeof(StackValue));
    val->lu = lu;
    stack_push(stack, val);
}

void stack_pushptr(Stack *stack,          void *ptr) {
    StackValue *val = (StackValue *)malloc(sizeof(StackValue));
    val->ptr = ptr;
    stack_push(stack, val);
}

char stack_popc(Stack *stack) {
    StackValue *val = stack_pop(stack);
    char c = val->c;
    free(val);
    return c;
}

unsigned char stack_popcu(Stack *stack) {
    StackValue *val = stack_pop(stack);
    unsigned char cu = val->cu;
    free(val);
    return cu;
}

short stack_pops(Stack *stack) {
    StackValue *val = stack_pop(stack);
    short s = val->s;
    free(val);
    return s;
}

unsigned short stack_popsu(Stack *stack) {
    StackValue *val = stack_pop(stack);
    unsigned short su = val->su;
    free(val);
    return su;
}

int stack_popi(Stack *stack) {
    StackValue *val = stack_pop(stack);
    int i = val->i;
    free(val);
    return i;
}

unsigned int stack_popiu(Stack *stack) {
    StackValue *val = stack_pop(stack);
    unsigned int iu = val->iu;
    free(val);
    return iu;
}

long stack_popl(Stack *stack) {
    StackValue *val = stack_pop(stack);
    long l = val->l;
    free(val);
    return l;
}

unsigned long stack_poplu(Stack *stack) {
    StackValue *val = stack_pop(stack);
    unsigned long lu = val->lu;
    free(val);
    return lu;
}

void *stack_popptr(Stack *stack) {
    StackValue *val = stack_pop(stack);
    void *ptr = val->ptr;
    free(val);
    return ptr;
}

char stack_peekc(Stack *stack) {
    StackValue *val = stack_peek(stack);
    char c = val->c;
    return c;
}

unsigned char stack_peekcu(Stack *stack) {
    StackValue *val = stack_peek(stack);
    unsigned char cu = val->cu;
    return cu;
}

short stack_peeks(Stack *stack) {
    StackValue *val = stack_peek(stack);
    short s = val->s;
    return s;
}

unsigned short stack_peeksu(Stack *stack) {
    StackValue *val = stack_peek(stack);
    unsigned short su = val->su;
    return su;
}

int stack_peeki(Stack *stack) {
    StackValue *val = stack_peek(stack);
    int i = val->i;
    return i;
}

unsigned int stack_peekiu(Stack *stack) {
    StackValue *val = stack_peek(stack);
    unsigned int iu = val->iu;
    return iu;
}

long stack_peekl(Stack *stack) {
    StackValue *val = stack_peek(stack);
    long l = val->l;
    return l;
}

unsigned long stack_peeklu(Stack *stack) {
    StackValue *val = stack_peek(stack);
    unsigned long lu = val->lu;
    return lu;
}

void *stack_peekptr(Stack *stack) {
    StackValue *val = stack_peek(stack);
    void *ptr = val->ptr;
    return ptr;
}