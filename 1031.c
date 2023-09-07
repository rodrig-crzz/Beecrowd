/*
    1031 - Power Crisis
    author: rodrig-crzz
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {off, on} status;
typedef struct region_struct
{   //linked list
    int _value;
    status _status;
    struct region_struct * _pointer;
} region_struct;

region_struct * insert_first();
region_struct * insert(region_struct * _l, int _v);
region_struct * create_list(region_struct * _l, int _rn, int _hrn);
region_struct * cut_list(region_struct * _l, int _rn);
void paste_list(region_struct * _l, region_struct * _pbl);
void restart_list(region_struct * _l);
int process(region_struct * _l, int _rn, int _m);

int main()
{
    region_struct * _regions_list = NULL;
    region_struct * _point_cut_list = NULL;
    int _regions_number;
    int _highest_regions_number = 0;

    while(1)
    {
        scanf("%i", &_regions_number);

        if(_regions_number == 0)
            return 0;
        if(_regions_number == 13)
            printf("1\n");
        else if(_regions_number > _highest_regions_number)
        {
            _regions_list = create_list(_regions_list, _regions_number, _highest_regions_number+1);
            _highest_regions_number = _regions_number;
            printf("%i\n", process(_regions_list, _regions_number, 2));
        }
        else if(_regions_number == _highest_regions_number)
            printf("%i\n", process(_regions_list, _regions_number, 2));
        else if(_regions_number < _highest_regions_number)
        {
            _point_cut_list = cut_list(_regions_list, _regions_number);
            printf("%i\n", process(_regions_list, _regions_number, 2));
            paste_list(_regions_list, _point_cut_list);
        }
    }
}

region_struct * insert_first()
{
    region_struct * _aux = (region_struct *) malloc(sizeof(region_struct));
    _aux->_value = 1;
    _aux->_status = off;
    _aux->_pointer = _aux;
    return _aux;
}
region_struct * insert(region_struct * _l, int _v)
{
    region_struct * _aux1 = _l;
    region_struct * _aux2 = (region_struct *) malloc(sizeof(region_struct));
    _aux2->_value = _v;
    _aux2->_status = on;
    _aux2->_pointer = _l;
    while(_aux1->_pointer != _l)
        _aux1 = _aux1->_pointer;
    _aux1->_pointer = _aux2;
    return _l;
}
region_struct * create_list(region_struct * _l, int _rn, int _hrn)
{
    if(_l == NULL)
    {
        _l = insert_first();
        _hrn++;
    }
    for(int i = _hrn ; i <= _rn ; i++)
        _l = insert(_l, i);
    return _l;
}
region_struct * cut_list(region_struct * _l, int _rn)
{
    region_struct * _head = _l;
    region_struct * _tail = NULL;
    while(_rn != _head->_value)
        _head = _head->_pointer;
    _tail = _head->_pointer;
    _head->_pointer = _l;
    _head = _head->_pointer;
    return _tail;
}
void paste_list(region_struct * _l, region_struct * _pbl)
{
    region_struct * _aux = _l;
    while(_aux->_pointer != _l)
        _aux = _aux->_pointer;
    _aux->_pointer = _pbl;
}
void restart_list(region_struct * _l)
{
    _l = _l->_pointer;
    while(_l->_value != 1)
    {
        _l->_status = on;
        _l = _l->_pointer;
    }
}
int process(region_struct * _l, int _rn, int _m)
{
    region_struct * _aux = _l;
    bool _verify = true;
    int _aux_rn = _rn;
    _aux_rn-=2;
    while(_aux_rn--)
    {
        for(int i = 1 ; i <= _m ; i++)
        {
            _aux = _aux->_pointer;
            if(_aux->_status == off)
                i--;
        }
        if(_aux->_value == 13)
        {
            _verify = false;
            restart_list(_l);
            break;
        }
        _aux->_status = off;
    }
    if(_verify)
        return _m;
    else
        return process(_l, _rn, _m+1);
}