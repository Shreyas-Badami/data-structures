#include "my_dll.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    struct my_dll* list = (struct my_dll*)malloc(sizeof(struct my_dll));
    list->root = NULL;
    list->tail = NULL;
    list->size = 0;
    while (1)
    {
        char command[100];
        int n1; 
        int n2;
        scanf("%s", command);
        if (strcmp(command, "insert") == 0)
        {
            scanf("%d", &n1);
            insert(list, n1);
        }
        else if (strcmp(command, "print") == 0)
        {
            print(list);
        }
        else if (strcmp(command, "print_reverse") == 0)
        {
            print_reverse(list);
        }
        else if (strcmp(command, "get_size") == 0)
        {
            printf("%d\n",get_size(list));
        }
        else if (strcmp(command, "prune") == 0)
        {
            prune(list);
        }
        else if (strcmp(command, "find") == 0)
        {
            scanf("%d", &n1);
            printf("%d\n",find(list,n1));
        }
        else if (strcmp(command, "delete") == 0)
        {
            scanf("%d", &n1);
            delete(list,n1);
        }
        else if (strcmp(command, "insert_at") == 0)
        {
            scanf("%d", &n1);
            scanf("%d", &n2);
            insert_at(list,n1,n2);
        }
    }
}