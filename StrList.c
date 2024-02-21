    #include <stdlib.h>
    #include "StrList.h"
    #include <stdio.h>
    #include <string.h>

    typedef struct _node
    {
        char *_data;
        struct _node *_next;
        struct _node *_head;
        struct _node *_size;
    } Node;

    typedef struct _StrList
    {
        Node *_head;
        size_t _size;
    } StrList;

    Node *Node_alloc(const char *data, Node *next)
    {
        Node *node1 = (Node *)malloc(sizeof(Node));

        if (node1 != NULL)
        {
            (*node1)._head = NULL;
            (*node1)._size = 0;
        }

        return node1;
    }

    void StrList_free(StrList *list)
    {
        Node *temp;
        Node *head = list->_head;

        for (int i = 0; i < list->_size; i++)
        {
            temp = head->_next;
            free(head);
            head = temp;
        }

        free(list);
    }

    size_t StrList_size(const StrList* StrList)
    {
        return StrList->_size;
    }

    void StrList_insertLast(StrList* StrList, const char* data)
    {
        Node* node1 = Node_alloc(data, NULL);
        //if the list is empty
        if (StrList->_head==NULL)
        {
            StrList->_head=node1;
        }
        else
        {
            Node* temp = StrList->_head;
            for (int i = 0; i < StrList->_size-1; i++)
            {
                temp = temp->_next;
            }
            temp->_next = node1;
            
        }
    }