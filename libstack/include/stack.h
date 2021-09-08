typedef struct StackNode {
    struct StackNode *prev;
    void *val;
} StackNode;

typedef struct Stack {
    StackNode *top;
    int size;
} Stack;

Stack *stack_new();
void stack_destroy(Stack *stack);
void stack_push(Stack *stack, void *val);
void *stack_pop(Stack *stack);
void *stack_peek(Stack *stack);