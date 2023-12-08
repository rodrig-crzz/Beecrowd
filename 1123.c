/*
    1123 - Route Change
    author: rodrig-crzz
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef enum {false, true} bool;
typedef struct _edge {
    int vertex;
    int weight;
    struct _edge* next;
} edge;
typedef struct {
    edge* head;
} vertex;
typedef struct {
    bool relax;
    int distance;
} vertexDijkstra;

vertex* initializeVertex(const int n);
void addEdge(vertex* graph, int vertexSrc, int vertexDest, int weight);
void freeGraph(vertex* graph, int n);
int modifiedDijkstra(vertex* graph, int n, int src, int dest);
int extractMin(vertexDijkstra set[], int n);

int main(void) {
    while (1) {
        int n;
        int m;
        int c;
        int k;

        scanf ("%d %d %d %d", &n, &m, &c, &k);

        if (n == 0 && m == 0 && c == 0 && k == 0)
            return 0;
        
        vertex* graph = initializeVertex(n);

        for (int i = 0 ; i < m ; i++) {
            int u;
            int v;
            int p;
            scanf ("%d %d %d", &u, &v, &p);
            addEdge(graph, u, v, p);
            addEdge(graph, v, u, p);
        }

        printf ("%d\n", modifiedDijkstra(graph, n, k, c-1));

        freeGraph(graph, n);
    }
}

vertex* initializeVertex(const int n) {
    vertex* new = (vertex*) malloc(n * sizeof(vertex));
    for (int i = 0 ; i < n ; i++)
        new[i].head = NULL;
    return new;
}
void addEdge(vertex* graph, int vertexSrc, int vertexDest, int weight) {
    edge* new = (edge*) malloc(sizeof(edge));
    new->vertex = vertexDest;
    new->weight = weight;
    new->next = graph[vertexSrc].head;
    graph[vertexSrc].head = new;
}
void freeGraph(vertex* graph, int n) {
    for (int i = 0 ; i < n ; i++) {
        edge* current = graph[i].head;
        while (current) {
            edge* temp = current;
            current = current->next;
            free(temp);
        }
    }
}
int modifiedDijkstra(vertex* graph, const int n, int src, int dest) {
    vertexDijkstra set[n];
    bool inRoute = false;

    for (int i = 0 ; i < n ; i++) {
        set[i].relax = false;
        set[i].distance = INT_MAX;
    }

    set[src].distance = 0;
    
    int index = src;
    while (1) {
        set[index].relax = true;

        if (index < dest)
            inRoute = true;
        else if (index > dest)
            inRoute = false;
        else
            break;

        edge* aux = graph[index].head;
        while (aux) {
            if (inRoute) {
                if ( aux->vertex == index+1 && set[ aux->vertex ].distance > set[index].distance + aux->weight )
                    set[ aux->vertex ].distance = set[index].distance + aux->weight;
            } else
                if ( !set[ aux->vertex ].relax && set[ aux->vertex ].distance > set[index].distance + aux->weight )
                    set[ aux->vertex ].distance = set[index].distance + aux->weight;
            aux = aux->next;
        }

        index = extractMin(set, n);
    }

    return set[dest].distance;
}
int extractMin(vertexDijkstra set[], int n) {
    int min = INT_MAX;
    int index;

    for (int i = 0 ; i < n ; i++)
        if ( set[i].distance < min && !set[i].relax ) {
            min = set[i].distance;
            index = i;
        }
        
    return index;
}