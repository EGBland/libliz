#include <stdio.h>
#include <stdlib.h>
#include <list.h>
#include <graph.h>
#include <time.h>

bool_t eqfn_i(void *i1ptr, void *i2ptr) {
    int i1 = *((int*)i1ptr);
    int i2 = *((int*)i2ptr);
    //printf("comparing %d and %d (%d)\n", i1, i2, i1==i2);
    return i1 == i2;
}

#define LIST_TEST 0
#define LIST_BIG_REMOVE_TEST 1
#define GRAPH_TEST 0

#if LIST_TEST
void list_test(List *lst) {
    printf("Adding to list\n");
    int myarr[6];
    for(int i = 0; i < 4; i++) {
        myarr[i] = i+20;
        (lst->add)(lst, myarr+i);
    }

    printf("Removing second element\n");
    (lst->remove)(lst, 1);

    printf("Reading from list\n");
    for(int i = 0; i < lst->len; i++) {
        int *val = (int *)(lst->get)(lst, i);
        printf("%d\n", *val);
    }

    int myint = 22;
    printf("Is %d a member? %d\n", myint, (lst->ismemby)(lst, &myint, &eqfn_i));

    printf("Clearing list\n");
    (lst->clear)(lst);

    printf("Refilling list\n");
    for(int i = 0; i < 6; i++) {
        myarr[i] = i+2;
        (lst->add)(lst, myarr+i);
    }

    printf("Reading from list\n");
    for(int i = 0; i < lst->len; i++) {
        int *val = (int *)(lst->get)(lst, i);
        printf("%d\n", *val);
    }

    printf("Destroying list\n");
    (lst->destroy)(lst);
}

int main() {
    printf("===ARRAY LIST===\n");
    printf("Creating array list\n");
    List *mylist = (List *)malloc(sizeof(List));
    al_init(mylist, 2);
    list_test(mylist);

    printf("===LINKED LIST===\n");
    printf("Creating linked list\n");
    ll_init(mylist);
    list_test(mylist);
    
}

#elif LIST_BIG_REMOVE_TEST
#define LIST_SIZE (1<<20)
#define REMOVE_AMT (1<<12)
void occupylist(List *lst) {
    int myarr[LIST_SIZE];
    for(int i = 0; i < LIST_SIZE; i++) {
        myarr[i] = i;
        (lst->add)(lst, myarr+i);
    }
}

void removefromlist(List *lst) {
    for(int i = 0; i < REMOVE_AMT; i++) {
        int myrand = (int)((lst->len) * (rand()/(float)RAND_MAX));
        (lst->remove)(lst, myrand);
    }
}

int main() {
    clock_t start, end;
    time_t t;
    srand((unsigned int)time(&t));

    List mylist;
    al_init(&mylist, 10);
    start = clock();
    occupylist(&mylist);
    end = clock();
    printf("Add to array list (w/ resizing):\t%.3f\n", (end-start)/(float)CLOCKS_PER_SEC);

    start = clock();
    removefromlist(&mylist);
    end = clock();
    printf("Remove from array list (w/ resizing):\t%.3f\n", (end-start)/(float)CLOCKS_PER_SEC);
}

#elif GRAPH_TEST
int main() {
    printf("Creating graph\n");
}
#endif