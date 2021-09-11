#include <stdio.h>
#include <stack.h>

int main() {
    printf("Creating stack\n");
    Stack mystack;
    stack_init(&mystack);

    printf("Pushing to stack\n");
    for(int i = 12; i < 12+8; i++) {
        stack_pushi(&mystack, i);
    }

    printf("Popping from stack\n");
    while(mystack.size > 2) {
        int myval = stack_popi(&mystack);
        printf("%d\t%d\n",myval,mystack.size);
    }

    printf("Destroying stack\n");
    stack_destroy(&mystack);
}