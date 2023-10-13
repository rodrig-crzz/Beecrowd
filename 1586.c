/*
    1586 - Tug of War
    author: rodrig-crzz
*/
#include <stdio.h>
#include <stdbool.h>

#define max_students 100000
#define letters 11

int verify(char stud[][letters], const int quantity);
int strength(char *name);

int main(void)
{
    int _n;

    while(scanf("%d", &_n) && _n != 0)
    {
        char students[max_students][letters];

        for(int i = 0 ; i < _n ; i++)
            scanf("%s", students[i]);

        int answer = verify(students, _n);

        if(answer != -1)
            printf("%s\n", students[answer]);
        else
            printf("Impossibilidade de empate.\n");
    }
    return 0;
}

int verify(char stud[][letters], const int quantity)
{
    long long studs_streng[quantity];
    long long team_a = 0;
    long long streng_a = 0;
    long long team_b = 0;
    long long streng_b = 0;

    for(int i = 0, j = quantity ; i < quantity ; i++, j--)
    {
        studs_streng[i] = strength(stud[i]);
        team_a += studs_streng[i] * j;
        streng_a += studs_streng[i];
    }
    
    int position = quantity-1;

    while(team_a > team_b)
    {
        team_b += streng_b + studs_streng[position];
        streng_b += studs_streng[position];

        team_a -= streng_a;
        streng_a -= studs_streng[position];
        
        position--;

        if(team_a == team_b)
            return position;
    }

    return -1;
}
int strength(char *name)
{
    int i = 0;
    int value = 0;
    while(name[i] != '\0')
        value += name[i++];
    return value;
}
