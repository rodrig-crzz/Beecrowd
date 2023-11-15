/*
    1912 - Reducing Details on a Map
    author: rodrig-crzz
*/
#include <stdio.h>
#include <stdlib.h>

typedef enum {out, in} status;
typedef struct
{
    int v1;
    int v2;
    int weight;
} edge;

int comparison(const void* a, const void* b);

//  PRIM algorithm
int prim(edge _edges[], int _vert, int _edg);

int main(void)
{
    int cities;
    int highways;

    scanf("%d %d", &cities, &highways);

    edge edges[highways];
    for(int i = 0 ; i < highways ; i++)
        scanf("%d %d %d", &edges[i].v1, &edges[i].v2, &edges[i].weight);
    
    qsort(edges, highways, sizeof(edge), comparison);

    printf("%d\n", prim(edges, cities, highways));

    return 0;
}

int comparison(const void* a, const void* b)
{
    return ((edge*) a)->weight - ((edge*) b)->weight;
}
int prim(edge _edges[], int _vert, int _edg)
{
    status vertStts[ _vert ];
    for(int i = 1 ; i < _vert ; i++)
        vertStts[i] = out;
    
    vertStts[0] = in;

    int count = 0;
    int i = 0;
    while(i < _edg)
    {
        if( vertStts[ _edges[i].v1-1 ] == in || vertStts[ _edges[i].v2-1 ] == in )
            if( vertStts[ _edges[i].v1-1 ] == out || vertStts[ _edges[i].v2-1 ] == out )
            {
                count += _edges[i].weight;
                vertStts[ _edges[i].v1-1 ] = vertStts[ _edges[i].v2-1 ] = in;
                i = 0;
                continue;
            }
        i++;
    }

    return count;
}