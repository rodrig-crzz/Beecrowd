/*
    1520 - Screws and Nuts
    author: rodrig-crzz
*/
#include <stdio.h>
#include <stdbool.h>

void combSort(int arr[], int size);
void search(int ele, int arr[], int size, int *l_shelve, int *h_shelve);

int main(void)
{
    int _n;
    int rack[10000];
    while(scanf("%d", &_n) != EOF)
    {
        int size = 0;
        while(_n--)
        {
            int _x;
            int _y;
            scanf("%d %d", &_x, &_y);

            for(int i = _x ; i <= _y ; i++)
                rack[size++] = i;
            
        }

        combSort(rack, size);

        int num;
        scanf("%d", &num);

        int lowest = 0;
        int highest = 0;

        search(num, rack, size, &lowest, &highest);

        if(lowest == -1 && highest == -1)
            printf("%d not found\n", num);
        else
            printf("%d found from %d to %d\n", num, lowest, highest);
    }
    return 0;
}

void combSort(int arr[], int size)
{
    int gap = size;
    bool swapped = true;
    while(gap > 1 || swapped)
    {
        gap /= 1.3;
        if(gap < 1)
            gap = 1;

        swapped = false;

        for(int i = 0 ; i < size-gap ; i++)
        {
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
void search(int ele, int arr[], int size, int *l_shelve, int *h_shelve)
{
    int i = 0;
    while(i <= size)
    {
        if(i == size || arr[i] > ele)
        {
            *l_shelve = -1;
            *h_shelve = -1;
            return;
        }
        if(arr[i] == ele)
        {
            *l_shelve = i;
            break;
        }
        i++;
    }
    int j = i;
    while(j < size && arr[j+1] == ele)
        j++;
    *h_shelve = j;
}
