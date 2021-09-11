#include <arraylist.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_LIST_START_SIZE 10

// helper functions
void al_add(ArrayList *al, ListValue *lv);
ListValue *al_get(ArrayList *al, int pos);

void al_add(ArrayList *al, ListValue *lv) {
    if(al->len >= al->maxlen) {
        al_resize(al, 2*al->maxlen);
    }
    al->arr[al->len] = lv;
    al->len++;
}

ListValue *al_get(ArrayList *al, int pos) {
    if(pos >= al->len) return 0;
    return al->arr[pos];
}

// header implementations
void al_init(ArrayList *al) {
    al->arr = (ListValue **)malloc(ARRAY_LIST_START_SIZE * sizeof(ListValue *));
    al->len = 0;
    al->maxlen = ARRAY_LIST_START_SIZE;
}

void al_destroy(ArrayList *al) {
    for(int i = 0; i < al->len; i++) {
        free(al->arr[i]);
    }
    free(al->arr);
}

void al_resize(ArrayList *al, int newsize) {
    if(newsize <= al->maxlen) return;
    ListValue **newarr = (ListValue **)malloc(newsize * sizeof(ListValue *));
    memcpy(newarr, al->arr, sizeof(ListValue *)*al->maxlen);
    free(al->arr);
    al->arr = newarr;
    al->maxlen = newsize;
}

void al_addc  (ArrayList *al, char c) {
    ListValue *lv = (ListValue *)malloc(sizeof(ListValue));
    lv->c = c;
    al_add(al, lv);
}

void al_addcu (ArrayList *al, unsigned char cu) {
    ListValue *lv = (ListValue *)malloc(sizeof(ListValue));
    lv->cu = cu;
    al_add(al, lv);
}

void al_adds  (ArrayList *al, short s) {
    ListValue *lv = (ListValue *)malloc(sizeof(ListValue));
    lv->s = s;
    al_add(al, lv);
}

void al_addsu (ArrayList *al, unsigned short su) {
    ListValue *lv = (ListValue *)malloc(sizeof(ListValue));
    lv->su = su;
    al_add(al, lv);
}

void al_addi  (ArrayList *al, int i) {
    ListValue *lv = (ListValue *)malloc(sizeof(ListValue));
    lv->i = i;
    al_add(al, lv);
}

void al_addiu (ArrayList *al, unsigned int iu) {
    ListValue *lv = (ListValue *)malloc(sizeof(ListValue));
    lv->iu = iu;
    al_add(al, lv);
}

void al_addl  (ArrayList *al, long l) {
    ListValue *lv = (ListValue *)malloc(sizeof(ListValue));
    lv->l = l;
    al_add(al, lv);
}

void al_addlu (ArrayList *al, unsigned long lu) {
    ListValue *lv = (ListValue *)malloc(sizeof(ListValue));
    lv->lu = lu;
    al_add(al, lv);
}

void al_addptr(ArrayList *al, void *ptr) {
    ListValue *lv = (ListValue *)malloc(sizeof(ListValue));
    lv->ptr = ptr;
    al_add(al, lv);
}

char al_getc(ArrayList *al, int pos) {
    ListValue *lv = al_get(al, pos);
    if(lv) return lv->c; else return 0; // TODO error stuff
}

unsigned char al_getcu(ArrayList *al, int pos) {
    ListValue *lv = al_get(al, pos);
    if(lv) return lv->cu; else return 0;
}

short al_gets(ArrayList *al, int pos) {
    ListValue *lv = al_get(al, pos);
    if(lv) return lv->s; else return 0;
}

unsigned short al_getsu(ArrayList *al, int pos) {
    ListValue *lv = al_get(al, pos);
    if(lv) return lv->su; else return 0;
}

int al_geti(ArrayList *al, int pos) {
    ListValue *lv = al_get(al, pos);
    if(lv) return lv->i; else return 0;
}

unsigned int al_getiu(ArrayList *al, int pos) {
    ListValue *lv = al_get(al, pos);
    if(lv) return lv->iu; else return 0;
}

long al_getl(ArrayList *al, int pos) {
    ListValue *lv = al_get(al, pos);
    if(lv) return lv->l; else return 0;
}

unsigned long al_getlu(ArrayList *al, int pos) {
    ListValue *lv = al_get(al, pos);
    if(lv) return lv->lu; else return 0;
}

void *al_getptr(ArrayList *al, int pos) {
    ListValue *lv = al_get(al, pos);
    if(lv) return lv->ptr; else return 0;
}

void al_remove(ArrayList *al, int pos) {
    if(pos >= al->len) return;
    if(pos < al->len-1) {
        memmove(al->arr+pos, al->arr+pos+1, sizeof(ListValue *)*(al->len-pos-1));
    }
}

void al_clear(ArrayList *al) {
    for(int i = 0; i < al->len; i++) {
        free(al->arr[i]);
    }
    free(al->arr);
    al_init(al);
}