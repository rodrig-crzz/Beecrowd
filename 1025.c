/*
    1025 - Where is the Marble?
    author: rodrig-crzz
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void combSort(int *arr, int size);
int search(int *arr, int size, int elem);

int main(void)
{
    int *marbles;
    int _n;
    int _q;

    int _c = 1;

    while(scanf("%d %d", &_n, &_q) && _n != 0 && _q != 0)
    {
        printf("CASE# %d:\n", _c++);

        marbles = (int *) malloc(_n * sizeof(int));

        for(int i = 0 ; i < _n ; i++)
            scanf("%d", &marbles[i]);
        
        combSort(marbles, _n);
        
        int aux;
        for(int i = 1 ; i <= _q ; i++)
        {
            scanf("%d", &aux);
            int answer = search(marbles, _n, aux);
            if(answer > -1)
                printf("%d found at %d\n", aux, answer);
            else
                printf("%d not found\n", aux);
        }
        free(marbles);
    }

    return 0;
}

void combSort(int *arr, int size)
{
    int gap = size;
    bool swapped = true;

    while(gap != 1 || swapped)
    {
        gap /= 1.3;
        //shrink gap
        if(gap < 1)
            gap = 1;

        swapped = false;

        for(int i = 0 ; i < size-gap ; i++)
        {   //swap
            if(arr[i] > arr[i+gap])
            {
                int temp = arr[i];
                arr[i] = arr[i+gap];
                arr[i+gap] = temp;
                swapped = true;
            }
        }
    }
}
int search(int *arr, int size, int elem)
{
    for(int i = 0 ; i < size ; i++)
    {
        if(arr[i] == elem)
            return i+1;
        if(arr[i] > elem)
            return -1;
    }
    return -1;
}
