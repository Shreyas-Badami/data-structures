#include "my_dll.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void insert_impl(struct my_dll* list, struct Node *node)
{
    node->prev = list->tail;
    if (list->size != 0)
    {
        list->tail->next = node;
    }
    else
    {
        list->root = node;
    }
    list->tail = node;
    list->size++;
}

void insert(struct my_dll* list, int data)
{
    struct Node *node = (struct Node*)calloc(1, sizeof(struct Node));
    assert(node != NULL);
    node->data = data;
    insert_impl(list, node);
}

void insert_at(struct my_dll* list, int data, int index)
{
    if (index > list->size || index < 0)
    {
        return;
    }
    struct Node *node = (struct Node*)calloc(1, sizeof(struct Node));
    node->data = data;
    if (index == 0)
    {
        list->root->prev = node;
        node->prev = NULL;
        node->next = list->root;
        list->root = node;
    }
    else if (index == list->size)
    {
        insert_impl(list, node);
    }
    else
    {
        struct Node *currNode = list->root;
        struct Node *prevNode = NULL;
        for (int i = 0; i < index; i++)
        {
            prevNode = currNode;
            currNode = currNode->next;
        }
        node->prev = prevNode;
        node->next = currNode;
        prevNode->next = node;
        currNode->prev = node;
    }
    list->size++;
}

void delete(struct my_dll* list, int index)
{
    if (index > list->size || index < 0)
    {
        return;
    }
    if (index == 0)
    {
        struct Node *temp = list->root;
        list->root = list->root->next;
        list->root->prev = NULL;
        free(temp);
    }
    else if (index == list->size-1)
    {
        struct Node *temp = list->tail;
        list->tail = temp->prev;
        assert(list->tail != NULL);
        list->tail->next = NULL;
        free(temp);
    }
    else
    {
        struct Node *currNode = list->root;
        struct Node *prevNode = NULL;
        for (int i = 0; i < index; i++)
        {
            prevNode = currNode;
            currNode = currNode->next;
        }
        prevNode->next = currNode->next;
        currNode->next->prev = prevNode;
        free(currNode);
    }
    list->size--;
}

int find(struct my_dll* list, int term)
{
    int found = -1;
    int index = 0;
    struct Node *currNode = list->root;
    while (currNode != NULL)
    {
        if (currNode->data == term)
        {
            found = index;
            break;
        }
        currNode = currNode->next;
        index++;
    }
    return found;
}

void prune(struct my_dll* list)
{
    if (list->size <= 1)
    {
        return;
    }
    else
    {
        struct Node* currNode = list->root;
        /*
        while (currNode->next != NULL && currNode->next->next != NULL)
        {
            currNode = currNode->next->next;
            struct Node* temp = currNode->prev;
            currNode->prev = temp->prev;
            temp->prev->next = currNode;
            free(temp);
            list->size--;
        }
        */
       int index = 0;
       while (currNode != NULL)
       {
           struct Node* temp = currNode;
           currNode = currNode->next;
           if (index % 2 == 1)
           {
               temp->prev->next = temp->next;
               if (temp->next != NULL)
               {
                   temp->next->prev = temp->prev;
               }
               else if (list->tail == temp)
               {
                   list->tail = temp->prev;
               }
               free(temp);
               list->size--;
           }
           index++;
       }
    }
}

void print(struct my_dll* list)
{
    struct Node *currNode = list->root;
    while (currNode != NULL)
    {
        printf("%d ",currNode->data);
        currNode = currNode->next;
    }
    printf("\n");
}

void print_reverse(struct my_dll* list)
{
    struct Node *currNode = list->tail;
    while (currNode != NULL)
    {
        printf("%d ",currNode->data);
        currNode = currNode->prev;
    }
    printf("\n");
}

int get_size(struct my_dll* list)
{
    return list->size;
}