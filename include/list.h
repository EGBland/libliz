#ifndef __LIST_H_DEFINED
#define __LIST_H_DEFINED 1

#define LIST_ARRAY (1)
#define LIST_LINKED (1<<1)

typedef unsigned char bool_t;
#define TRUE  (1)
#define FALSE (0)

typedef struct List {
    void   (*add)    (struct List *self, void *val);
    void * (*get)    (struct List *self, int pos);
    void   (*remove) (struct List *self, int pos);
    bool_t (*ismem)  (struct List *self, void *val);
    bool_t (*ismemby)(struct List *self, void *val, bool_t (*eqfn)(void *, void *));
    void   (*clear)  (struct List *self);
    void   (*destroy)(struct List *self);

    int typeid;
    int len;
    void *data;
} List;


/********** array list **********/
struct ALData {
    void **arr;
    int maxlen;
};

void al_init(List *alptr, int maxlen);

void al_add(List *al, void *val);
void *al_get(List *al, int pos);
void al_remove(List *al, int pos);
void al_clear(List *al);
void al_destroy(List *al);
bool_t al_ismem(List *al, void *val);
bool_t al_ismemby(List *al, void *val, bool_t (*eqfn)(void *, void *));

void al_resize(List *al, int newsize);

/********** linked list *********/
struct LLNode {
    void *val;
    struct LLNode *next;
};

struct LLData {
    struct LLNode *first;
    struct LLNode *head;
};

void ll_init(List *llptr);

void ll_add(List *ll, void *val);
void *ll_get(List *ll, int pos);
void ll_remove(List *ll, int pos);
void ll_clear(List *ll);
void ll_destroy(List *ll);
bool_t ll_ismem(List *ll, void *val);
bool_t ll_ismemby(List *ll, void *val, bool_t (*eqfn)(void *, void *));

struct LLNode *ll_getnode(List *ll, int pos);
#endif