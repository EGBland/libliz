#include <list.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********** array list **********/
void al_init(List *al, int maxlen) {
    struct ALData *data = (struct ALData *)malloc(sizeof(struct ALData));
    data->arr = (void **)malloc(maxlen*sizeof(void *));
    data->maxlen = maxlen;

    al->data = data;
    al->typeid = LIST_ARRAY;
    al->len = 0;
    al->add = &al_add;
    al->get = &al_get;
    al->remove = &al_remove;
    al->ismem = &al_ismem;
    al->ismemby = &al_ismemby;
    al->clear = &al_clear;
    al->destroy = &al_destroy;
}

void al_add(List *al, void *val) {
    struct ALData *data = (struct ALData *)(al->data);
    if(al->len >= data->maxlen) {
        printf("Resizing to %d\n", 2*data->maxlen);
        al_resize(al, 2*data->maxlen);
    }
    data->arr[al->len] = val;
    al->len++;
}

void *al_get(List *al, int pos) {
    struct ALData *data = (struct ALData *)(al->data);
    //printf("Checking %d against %d\n", pos, al->len);
    if(pos >= al->len) return 0; // TODO return result/error union?
    return data->arr[pos];
}

void al_remove(List *al, int pos) {
    if(pos >= al->len) return; // TODO error
    struct ALData *data = (struct ALData *)(al->data);
    if(pos < al->len-1) { // not the last element
        memmove(data->arr+pos, data->arr+pos+1, sizeof(void *)*(al->len-pos-1));
    }
    al->len--;
}

bool_t al_ismem(List *al, void *val) {
    struct ALData *data = (struct ALData *)(al->data);
    for(int i = 0; i < al->len; i++) {
        if(data->arr + i == val) return TRUE;
    }
    return FALSE;
}

bool_t al_ismemby(List *al, void *val, bool_t (*eqfn)(void *, void *)) {
    struct ALData *data = (struct ALData *)(al->data);
    for(int i = 0; i < al->len; i++) {
        if(eqfn(*(data->arr+i), val)) return TRUE;
    }
    return FALSE;
}

void al_resize(List *al, int newsize) {
    struct ALData *data = (struct ALData *)(al->data);
    if(newsize <= data->maxlen) return;
    void **arrnew = (void **)malloc(newsize*sizeof(void *));
    memcpy(arrnew, data->arr, sizeof(void *)*data->maxlen);
    free(data->arr);
    data->arr = arrnew;
    data->maxlen = newsize;
}

void al_clear(List *al) {
    struct ALData *data = (struct ALData *)(al->data);
    free(data->arr);
    data->arr = (void **)malloc(10*sizeof(void *)); // TODO restore first len
    al->len = 0;
    data->maxlen = 10;
}

void al_destroy(List *al) {
    struct ALData *data = (struct ALData *)(al->data);
    free(data->arr);
    free(data);
}


/********** linked list *********/
void ll_init(List *ll) {
    struct LLData *data = (struct LLData *)malloc(sizeof(struct LLData));
    data->first = 0;

    ll->data = data;
    ll->typeid = LIST_LINKED;
    ll->len = 0;
    ll->add = &ll_add;
    ll->get = &ll_get;
    ll->remove = &ll_remove;
    ll->ismem = &ll_ismem;
    ll->ismemby = &ll_ismemby;
    ll->clear = &ll_clear;
    ll->destroy = &ll_destroy;
}

void ll_add(List *ll, void *val) {
    struct LLData *data = (struct LLData *)(ll->data);
    struct LLNode *newnode = (struct LLNode *)malloc(sizeof(struct LLNode));
    newnode->val = val;
    newnode->next = 0;
    if(ll->len == 0) {
        data->first = newnode;
        data->head = newnode;
    }
    else {
        data->head->next = newnode;
        data->head = newnode;
    }
    ll->len++;
}

void *ll_get(List *ll, int pos) {
    struct LLNode *node = ll_getnode(ll, pos);
    return node->val;
}

struct LLNode *ll_getnode(List *ll, int pos) {
    // TODO implement access strategies; default is starting from tail
    if(pos >= ll->len) return 0; // TODO see al_get
    struct LLData *data = (struct LLData *)(ll->data);
    struct LLNode *current = data->first;
    for(int i = 0; i < pos; i++) {
        current = current->next;
    }
    return current;
}

void ll_remove(List *ll, int pos) {
    if(pos >= ll->len) return;
    struct LLData *data = (struct LLData *)(ll->data);
    if(pos == 0) {
        struct LLNode *oldfirst = data->first;
        data->first = oldfirst->next;
        free(oldfirst);
    }
    else {
        struct LLNode *prev = ll_getnode(ll, pos-1);
        struct LLNode *del = prev->next;
        prev->next = del->next;
        free(del);
    }
    ll->len--;
}

void ll_clear(List *ll) {
    if(ll->len == 0) return;
    struct LLData *data = (struct LLData *)(ll->data);
    struct LLNode *current = data->first;
    struct LLNode *next;
    while(current->next != 0) {
        next = current->next;
        free(current);
        current = next;
    }
    free(current);
    data->first = 0;
    data->head = 0;
    ll->len = 0;
}

void ll_destroy(List *ll) {
    ll_clear(ll);
    free(ll->data);
}

bool_t ll_ismem(List *ll, void *val) {
    if(ll->len == 0) return FALSE;
    struct LLData *data = (struct LLData *)(ll->data);
    struct LLNode *current = data->first;
    while(current->next != 0) {
        if(current->val == val) return TRUE;
        current = current->next;
    }
    return current->val == val;
}

bool_t ll_ismemby(List *ll, void *val, bool_t (*eqfn)(void *, void *)) {
    if(ll->len == 0) return FALSE;
    struct LLData *data = (struct LLData *)(ll->data);
    struct LLNode *current = data->first;
    while(current->next != 0) {
        if(eqfn(current->val, val)) return TRUE;
        current = current->next;
    }
    return eqfn(current->val, val);
}