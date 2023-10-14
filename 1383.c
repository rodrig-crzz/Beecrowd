/*
    1383 - Sudoku
    author: rodrig-crzz
*/
#include <stdio.h>
#include <stdbool.h>

#define size 9

bool verify(int mult_array[][size]);

int main(void)
{
    int _n;
    int instance = 1;
    scanf("%d", &_n);

    while(_n--)
    {
        printf("Instancia %d\n", instance++);
        
        int mult_array[size][size];

        for(int i = 0 ; i < size ; i++)
            for(int j = 0 ; j < size ; j++)
                scanf("%d", &mult_array[i][j]);

        if(verify(mult_array))
            printf("SIM\n\n");
        else
            printf("NAO\n\n");
    }

    return 0;
}

bool verify(int mult_array[][size])
{
    for(int i = 0 ; i < size ; i++)
    {
        int aux[size];
        for(int j = 0 ; j < size ; j++)
            aux[j] = 0;
        for(int j = 0 ; j < size ; j++)
        {
            int k = mult_array[i][j]-1;
            aux[k]++;
        }
        for(int j = 0 ; j < size ; j++)
            if(aux[j] != 1)
                return false;
    }
    for(int i = 0 ; i < size ; i++)
    {
        int aux[size];
        for(int j = 0 ; j < size ; j++)
            aux[j] = 0;
        for(int j = 0 ; j < size ; j++)
        {
            int k = mult_array[j][i]-1;
            aux[k]++;
        }
        for(int j = 0 ; j < size ; j++)
            if(aux[j] != 1)
                return false;
    }
    for(int i = 0 ; i < size ; i += 3)
        for(int j = 0 ; j < size ; j += 3)
        {
            int aux[size];
            for(int k = 0 ; k < size ; k++)
                aux[k] = 0;
            for(int k = i ; k < i+3 ; k++)
                for(int l = j ; l < j+3 ; l++)
                {
                    int n = mult_array[k][l]-1;
                    aux[n]++;
                }
            for(int k = 0 ; k < size ; k++)
                if(aux[k] != 1)
                    return false;
        }
    return true;
}
