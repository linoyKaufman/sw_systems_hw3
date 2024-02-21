#include "StrList.h"
#include <stdio.h>
#include <string.h>

typedef struct _node
{
    char  *_data;
    struct _node * _next;
} Node;

typedef struct _StrList 
{
    Node* _head;
    size_t _size;
} StrList;


