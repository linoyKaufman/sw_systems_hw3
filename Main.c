#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "StrList.h"

int main()
{
    StrList *list = SrtList_alloc();
    int choice;
    printf("choose a number from the menu\n");
    scanf("%d", &choice);
    while (choice != 0)
    {
        if (choice == 1)
        {
            printf("hhhh");
        }
        if (choice == 2)
        {
        }
        if (choice == 3)
        {
            for (int i = 0; i < StrList_size(list); i++)
            {
                StrList_printAt(list, i);
            }
        }
        if (choice == 4)
        {
            int sizeList = StrList_size(list);
            printf("%d", sizeList);
        }
        if (choice == 5)
        {
            int index;
            printf("enter the index\n");
            scanf("%d", &index);
            StrList_printAt(list, index);
        }
        if (choice == 6)
        {
            int len = StrList_len(list);
            printf("%d", len);
        }

        if (choice == 7)
        {
            int count;
            char *st;
            printf("enter the String\n");
            scanf("%c", st);
            st = (char *)malloc(100 * sizeof(char));// 100 is the max length of string
            count = StrList_count(list, st);
            printf("the string %s appears %d times\n", st, count);
        }
        if (choice == 8)
        {
        }
        if (choice == 9)
        {
        }
        if (choice == 10)
        {
        }
        if (choice == 11)
        {
        }
        if (choice == 12)
        {
        }
        if (choice == 13)
        {
            

        }
    }
}