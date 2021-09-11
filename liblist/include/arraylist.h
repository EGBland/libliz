#ifndef __ARRAYLIST_H_DEFINED
#define __ARRAYLIST_H_DEFINED 1

typedef union ListValue {
    char c;
    unsigned char cu;
    short s;
    unsigned short su;
    int i;
    unsigned int iu;
    long l;
    unsigned long lu;
    void *ptr;
} ListValue;

typedef struct ArrayList {
    ListValue **arr;
    int len;
    int maxlen;
} ArrayList;

void al_init(ArrayList *al);
void al_destroy(ArrayList *al);
void al_resize(ArrayList *al, int newsize);

void al_addc  (ArrayList *al, char c);
void al_addcu (ArrayList *al, unsigned char cu);
void al_adds  (ArrayList *al, short s);
void al_addsu (ArrayList *al, unsigned short su);
void al_addi  (ArrayList *al, int i);
void al_addiu (ArrayList *al, unsigned int iu);
void al_addl  (ArrayList *al, long l);
void al_addlu (ArrayList *al, unsigned long lu);
void al_addptr(ArrayList *al, void *ptr);

char al_getc(ArrayList *al, int pos);
unsigned char al_getcu(ArrayList *al, int pos);
short al_gets(ArrayList *al, int pos);
unsigned short al_getsu(ArrayList *al, int pos);
int al_geti(ArrayList *al, int pos);
unsigned int al_getiu(ArrayList *al, int pos);
long al_getl(ArrayList *al, int pos);
unsigned long al_getlu(ArrayList *al, int pos);
void *al_getptr(ArrayList *al, int pos);

void al_remove(ArrayList *al, int pos);
void al_clear(ArrayList *al);

#endif