#include <stdio.h>
#include <stack.h>

int main() {
    printf("Creating stack\n");
    Stack *mystack = stack_new();
    printf("Pushing to stack\n");
    int myarr[5];
    for(int i = 12; i < 12+5; i++) {
        myarr[i-12] = i;
        stack_push(mystack, myarr+i-12);
    }
    printf("Popping from stack\n");
    while(mystack->size > 0) {
        int *myval = (int *)stack_pop(mystack);
        printf("%d\n",*myval);
    }
}