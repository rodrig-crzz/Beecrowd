/*
    1912 - Help Seu Madruga
    author: rodrig-crzz
*/
#include <stdio.h>

int main(void)
{
    int _n;
    int _a;

    while(scanf("%d %d", &_n, &_a) && _n != 0 && _a != 0)
    {
        int columns[_n];
        double sum = 0;

        for(int i = 0 ; i < _n ; i++)
        {
            scanf("%d", &columns[i]);
            sum += columns[i];
        }

        if(_a > sum)
        {
            printf("-.-\n");
            continue;
        }
        if(_a == sum)
        {
            printf(":D\n");
            continue;
        }

        double _h = columns[0];
        double left = 0;
        double right = 10000;

        while(right-left > 1e-9)
        {
            _h = (left+right)/(double)2;
            sum = 0;

            for(int i = 0 ; i < _n ; i++)
                if(columns[i] > _h)
                    sum += columns[i]-_h;

            if(sum >= _a)
                left = _h;
            else
                right = _h;
        }

        printf("%.4lf\n", _h);
    }

    return 0;
}
