/*
    1655 - 106 Miles To Chicago
    author: rodrig-crzz
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct _edge {
    int vertex;
    double weight;
    struct _edge* next;
} edge;
typedef struct {
    edge* head;
} vertex;
typedef struct _dijkstraSet {
    int vertex;
    double percent;
    struct _dijkstraSet* next;
} dijkstraSet;

vertex* initializeGraph(int n);
void addEdge(vertex* graph, int vertex1, int vertex2, double weight);
void freeGraph(vertex* graph, int n);
double dijkstraWithPercentage(vertex* graph, int src, int dest, int n);
dijkstraSet* initializeSet(int n);
void relax(dijkstraSet* set, edge* edges, double currentPercent);
dijkstraSet extractMax(dijkstraSet** set);
dijkstraSet removeFromSet(dijkstraSet** set, int index);

int main(void) {
    int intersections;
    int streets;

    while (1) {
        scanf("%d", &intersections);
        if (intersections == 0)
            break;
        scanf("%d", &streets);
        
        vertex* graph = initializeGraph( intersections );
        for (int i = 0 ; i < streets ; i++) {
            int a;
            int b;
            double p;
            scanf("%d %d %lf", &a, &b, &p);
            addEdge(graph, a-1, b-1, p/100);
            addEdge(graph, b-1, a-1, p/100);
        }

        printf("%.6f percent\n", dijkstraWithPercentage(graph, 0, intersections-1, intersections));
    }
    return 0;
}

vertex* initializeGraph(int n) {
    vertex* new = (vertex*) malloc(n * sizeof(vertex));
    for (int i = 0 ; i < n ; i++)
        new[i].head = NULL;
    return new;
}
void addEdge(vertex* graph, int vertex1, int vertex2, double weight) {
    edge* new = (edge*) malloc(sizeof(edge));
    new->vertex = vertex2;
    new->weight = weight;
    new->next = graph[ vertex1 ].head;
    graph[ vertex1 ].head = new;
}
void freeGraph(vertex* graph, int n)  {
    for (int i = 0 ; i < n ; i++) {
        while (graph[i].head) {
            edge* temp = graph[i].head;
            graph[i].head = graph[i].head->next;
            free(temp);
        }
    }
}
double dijkstraWithPercentage(vertex* graph, int src, int dest, int n) {
    dijkstraSet* set = NULL;
    set = initializeSet(n);

    dijkstraSet index = removeFromSet(&set, src);
    index.percent = 1;
    while ( index.vertex != dest ) {
        relax(set, graph[ index.vertex ].head, index.percent);
        index = extractMax(&set);
    }

    return index.percent*100;
}
dijkstraSet* initializeSet(int n) {
    dijkstraSet* set = NULL;
    for (int i = 0 ; i <= n ; i++) {
        dijkstraSet* new = (dijkstraSet*) malloc(sizeof(dijkstraSet));
        new->vertex = i;
        new->percent = -1;
        new->next = set;
        set = new;
    }
    return set;
}
void relax(dijkstraSet* set, edge* edges, double currentPercent) {
    edge* currEdge = edges;
    while (currEdge) {
        dijkstraSet* currSet = set;
        while (currSet && currSet->vertex != currEdge->vertex)
            currSet = currSet->next;
        double newPercent = currEdge->weight * currentPercent;
        if (currSet && currSet->percent < newPercent)
            currSet->percent = newPercent;
        currEdge = currEdge->next;
    }
}
dijkstraSet extractMax(dijkstraSet** set) {
    dijkstraSet max;
    max.percent = -1;

    dijkstraSet* curr = *set;
    while (curr) {
        if (curr->percent > max.percent) {
            max.percent = curr->percent;
            max.vertex = curr->vertex;
        }
        curr = curr->next;
    }

    return removeFromSet(set, max.vertex);
}
dijkstraSet removeFromSet(dijkstraSet** set, int index) {
    dijkstraSet* prev = NULL;
    dijkstraSet* curr = *set;

    while (curr && curr->vertex != index) {
        prev = curr;
        curr = curr->next;
    }

    if (prev == NULL)
        *set = (*set)->next;
    
    dijkstraSet vertex;
    vertex.vertex = curr->vertex;
    vertex.percent = curr->percent;
    vertex.next = NULL;

    prev->next = curr->next;

    free(curr);

    return vertex;
}