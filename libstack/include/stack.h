#ifndef __STACK_H_DEFINED
#define __STACK_H_DEFINED 1

typedef union StackValue {
    char c;
    unsigned char cu;
    short s;
    unsigned short su;
    int i;
    unsigned int iu;
    long l;
    unsigned long lu;
    void *ptr;
} StackValue;

typedef struct StackNode {
    struct StackNode *prev;
    StackValue *val;
} StackNode;

typedef struct Stack {
    StackNode *top;
    int size;
} Stack;

void stack_init   (Stack *stack);
void stack_destroy(Stack *stack);

void stack_pushc  (Stack *stack,          char    c);
void stack_pushcu (Stack *stack, unsigned char   cu);
void stack_pushs  (Stack *stack,          short   s);
void stack_pushsu (Stack *stack, unsigned short  su);
void stack_pushi  (Stack *stack,          int     i);
void stack_pushiu (Stack *stack, unsigned int    iu);
void stack_pushl  (Stack *stack,          long    l);
void stack_pushlu (Stack *stack, unsigned long   lu);
void stack_pushptr(Stack *stack,          void *ptr);

         char  stack_popc  (Stack *stack);
unsigned char  stack_popcu (Stack *stack);
         short stack_pops  (Stack *stack);
unsigned short stack_popsu (Stack *stack);
         int   stack_popi  (Stack *stack);
unsigned int   stack_popiu (Stack *stack);
         long  stack_popl  (Stack *stack);
unsigned long  stack_poplu (Stack *stack);
         void *stack_popptr(Stack *stack);

         char  stack_peekc  (Stack *stack);
unsigned char  stack_peekcu (Stack *stack);
         short stack_peeks  (Stack *stack);
unsigned short stack_peeksu (Stack *stack);
         int   stack_peeki  (Stack *stack);
unsigned int   stack_peekiu (Stack *stack);
         long  stack_peekl  (Stack *stack);
unsigned long  stack_peeklu (Stack *stack);
         void *stack_peekptr(Stack *stack);

#endif