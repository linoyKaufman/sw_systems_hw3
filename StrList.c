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

    size_t StrList_size(const StrList *StrList)
    {
        return StrList->_size;
    }

    void StrList_insertLast(StrList *StrList, const char *data)
    {
        Node *node1 = Node_alloc(data, NULL);
        // if the list is empty
        if (StrList->_head == NULL)
        {
            StrList->_head = node1;
        }
        else
        {
            Node *temp = StrList->_head;
            for (int i = 0; i < StrList->_size - 1; i++)
            {
                temp = temp->_next;
            }
            temp->_next = node1;
        }
        (StrList->_size)++;
    }

    void StrList_insertAt(StrList *StrList, const char *data, int index)
    {
        Node *node1 = Node_alloc(data, NULL);
        Node *temp = StrList->_head;
        Node *temp2 = StrList->_head;

        if (index == 0)
        {
            node1->_next = StrList->_head;
            StrList->_head = node1;
        }

        else if (index < (StrList->_size))
        {
            for (int i = 0; i < index - 2; i++)
            {
                temp = temp->_next;
                temp2 = temp->_next;
            }
            temp->_next = node1;
            node1->_next = temp2;
        }
        else{
        StrList_insertLast(StrList,data);
        }
        ++(StrList->_size);
    }

    char *StrList_firstData(const StrList *StrList)
    {
        if (StrList->_head != NULL)
        {
            return StrList->_head->_data;
        }

        return;
    }

    void StrList_print(const StrList *StrList)
    {
        if (StrList->_head != NULL)
        {
            Node *temp = StrList->_head;
            for (int i = 0; i < StrList->_size; i++)
            {
                printf("%s", temp->_data);
                temp = temp->_next;
            }
        }
        else
        {
            printf("\n");
        }
    }

    void StrList_printAt(const StrList *Strlist, int index)
    {
        Node *temp = Strlist->_head;
        if (index < Strlist->_size)
        {
            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->_next;
            }
            printf("%s", temp->_data);
        }
    }

    int StrList_printLen(const StrList *Strlist)
    {
        Node *temp = Strlist->_head;
        int totalnum = 0;

        while (temp != NULL)
        {
            totalnum = totalnum + strlen(temp->_data);
            temp = temp->_next;
        }

        return totalnum;
    }

    int StrList_count(StrList *StrList, const char *data)
    {
        Node *temp = StrList->_head;
        int count = 0;
        while (temp != NULL)
        {
            if (strcmp(temp->_data, data) == 0)
            {
                count++;
            }
            temp = temp->_next;
        }
        return count;
    }

    void StrList_remove(StrList *StrList, const char *data)
    {

        if (strcmp(StrList->_head->_data, data) == 0)
        {
            Node *temp = StrList->_head->_next;
            free(StrList->_head);
            StrList->_head = temp;
        }

        Node *temp = StrList->_head->_next;
        Node *temp2 = StrList->_head->_next;
        Node *prev = StrList->_head;

        while (temp != NULL)
        {
            if (strcmp(temp->_data, data) == 0)
            {
                temp = temp->_next;
                free(temp2);
                prev->_next = temp;
                temp2 = temp;
                (StrList->_size)--;
            }
            temp = temp->_next;
            temp2 = temp2->_next;
            prev = prev->_next;
        }
    }

    void StrList_removeAt(StrList *StrList, int index)
    {
        if (index == 0)
        {
            Node *temp = StrList->_head->_next;
            StrList->_head = temp;
        }
        else
        {
            Node *temp = StrList->_head;
            Node *prev = StrList->_head;
            for (int i = 0; i < index; i++)
            {
                prev = temp;
                temp = temp->_next;
            }
            prev->_next = temp->_next;

            free(temp);
            (StrList->_size)--;
        }
    }
    int StrList_isEqual(const StrList *StrList1, const StrList *StrList2)
    {
        if (StrList1->_size != StrList2->_size)
        {
            return 0;
        }

        Node *list1 = StrList1->_head;
        Node *list2 = StrList1->_head;

        for (int i = 0; i < StrList2->_size; i++)
        {
            if (strcmp(list1->_data, list2->_data) == 1)
            {
                return 0;
            }

            else
            {
                list1 = list1->_next;
                list2 = list2->_next;
            }
        }
        return 1;
    }

    StrList *StrList_clone(const StrList *StrList)
    {
        StrList *copy1 = StrList_alloc();
        Node *temp = StrList->_head;
        for (int i = 0; i < StrList->_size; i++)
        {
            StrList_insertLast(copy1, temp->_data);
            temp = temp->_next;
        }
        return copy1;
    }

void StrList_reverse( StrList* StrList)
{
    Node* now = StrList->_head;
    Node* prev = NULL;
    Node* next = NULL;
    while (now != NULL) 
    {
        next = now->_next;
        now->_next = prev;
        prev = now;
        now= next;
    }
    StrList->_head = prev;
}

 void StrList_sort( StrList* StrList)
 {
       Node *i ;
       Node *j;
    char temp[STRING_SIZE];

    
    for (i= StrList->_head; i != NULL; i = i->_next) {
        for (j = i->_next; j != NULL; j = j->_next) {
            if (strcmp(i->_data, j->_data) > 0) {    
                strcpy(temp, i->_data);
                strcpy(i->_data, j->_data);
                strcpy(j->_data, temp);
            }
        }
    }
}

 int StrList_isSorted(StrList* StrList)
 {
    Node* temp = StrList->_head;
    while (temp != NULL && temp->_next != NULL)
    {
        if (temp->_data != NULL && temp->_next->_data != NULL) 
        {
            if (strcmp(temp->_data, temp->_next->_data) > 0)
            {
                 return 0;
            }
           
        }
        temp = temp->_next;
    }
    return 1;        
}