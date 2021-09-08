#include <graph.h>
#include <list.h>
#include <stdlib.h>

void graph_init(Graph *graph) {
    graph->arclst = (List *)malloc(sizeof(List));
    ll_init(graph->arclst);
}

void graph_destroy(Graph *graph) {
    (graph->arclst->destroy)(graph->arclst);
}

void graph_mst(Graph *graph) {
    char in[graph->arclst->len];
    List nodes;
    al_init(&nodes, 10);
    // initialise in array and discover nodes
    for(int i = 0; i < graph->arclst->len; i++) {
        Arc *arc = (Arc *)(graph->arclst->get)(graph->arclst, i);
        if(!(nodes.ismem)(&nodes, arc->nfrom)) {
            (nodes.add)(&nodes, arc->nfrom);
        }
        if(!(nodes.ismem)(&nodes, arc->nto)) {
            (nodes.add)(&nodes, arc->nto);
        }
        in[i] = 0;
    }
}