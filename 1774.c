/*
    1774 - Routers
    author: rodrig-crzz
*/
#include <stdio.h>
#include <stdlib.h>

//  macros to the algorithm
#define bothOut(a, b) (a == out && b == out ? 1 : 0)
#define bothIn(a, b) (a != out && b != out ? 1 : 0)
#define onlyOneIn(a, b) (a != out ? a : b)

#define out -1

typedef struct
{
    int v1;
    int v2;
    int weight;
} edge;

//  KRUSKAL algorithm
int kruskal(edge _edges[], int _verts, int _edge);

//  comparison function to the qsort function
int comparison(const void* a, const void* b);

int main(void)
{
    int routers;
    int cables;
    scanf("%d %d", &routers, &cables);

    edge* edges = (edge*) malloc(cables * sizeof(edge));
    for(int i = 0 ; i < cables ; i++)
        scanf("%d %d %d", &edges[i].v1, &edges[i].v2, &edges[i].weight);

    qsort(edges, cables, sizeof(edge), comparison);

    printf("%d\n", kruskal(edges, routers, cables));
    free(edges);

    return 0;
}

int kruskal(edge _edges[], int _verts, int _edge)
{
    int sttsVert[_verts];

    //  initialize arrays with NULL and distinct keys
    for(int i = 0 ; i < _verts ; i++)
        sttsVert[i] = out;

    int count = 0;

    for(int i = 0 ; i < _edge ; i++)
    {
        int k = _edges[i].v1-1;// vertex 1 of the edge
        int l = _edges[i].v2-1;// vertex 2 of the edge

        if( bothOut(sttsVert[k], sttsVert[l]) )
            sttsVert[k] = sttsVert[l] = k;

        else if( bothIn(sttsVert[k], sttsVert[l]) )
        {
            if(sttsVert[k] == sttsVert[l])
                continue;
            int temp = sttsVert[k];
            for(int n = 0 ; n < _verts ; n++)
            {
                if(sttsVert[n] == temp)
                    sttsVert[n] = sttsVert[l];
            }
        }

        else
            sttsVert[k] = sttsVert[l] = onlyOneIn(sttsVert[k], sttsVert[l]);

        count += _edges[i].weight;
    }

    return count;
}
int comparison(const void* a, const void* b)
{
    return ((edge*) a)->weight - ((edge*) b)->weight;
}