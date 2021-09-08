typedef struct StackNode {
    struct StackNode *prev;
    void *val;
} StackNode;

typedef struct Stack {
    StackNode *top;
    int size;
} Stack;

void stack_init(Stack *stack);
void stack_destroy(Stack *stack);
void stack_push(Stack *stack, void *val);
void *stack_pop(Stack *stack);
void *stack_peek(Stack *stack);