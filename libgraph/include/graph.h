#ifndef __GRAPH_H_DEFINED
#define __GRAPH_H_DEFINED 1

#include <list.h>

#define ARC_INT (1)
#define ARC_DOUBLE (1<<1)

#define arcwt_i(arcptr) (if (arcptr->typeid==ARC_INT) (arcptr->weight->vInt) else ((int)(arcptr->weight->vDouble)))
#define arcwt_d(arcptr) (if (arcptr->typeid==ARC_DOUBLE) (arcptr->weight->vDouble) else ((double)(arcptr->weight->vInt)))
#define arcwt(arcptr) (if (arcptr->typeid==ARC_INT) (arcptr->weight->vInt) else (arcptr->weight->vDouble))

typedef union Num {
    int vInt;
    double vDouble;
} Num;

typedef struct Arc {
    void *nfrom;
    void *nto;
    Num *weight;
    int typeid;
} Arc;

typedef struct Graph {
    List *arclst;
} Graph;


void graph_init(Graph *gptr);
void graph_destroy(Graph *gptr);

void graph_mst(Graph *gptr);
#endif