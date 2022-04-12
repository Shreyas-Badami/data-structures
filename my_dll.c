#include "my_dll.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void insert(struct my_dll* list, int data)
{
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    node->prev = list->tail;
    if (list->size != 0)
    {
        node->prev->next = node;
    }
    list->tail = node;
    if (list->size == 0)
    {
        list->root = node;
    }
    list->size++;
}

void insert_at(struct my_dll* list, int data, int index)
{
    if (index == 0)
    {
        struct Node *node = (struct Node*)malloc(sizeof(struct Node));
        node->data = data;
        list->root->prev = node;
        node->prev = NULL;
        node->next = list->root;
        list->root = node;
    }
    else if (index == list->size)
    {
        insert(list, data);
    }
    else
    {
        struct Node *node = (struct Node*)malloc(sizeof(struct Node));
        node->data = data;
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
    if (index == 0)
    {
        struct Node *temp = list->root;
        list->root = list->root->next;
        list->root->prev = NULL;
        free(temp);
    }
    else if(index == list->size-1)
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
        int numTermsToDelete = list->size/2;
        int index = 1;
        for (int i = 0; i < numTermsToDelete; i++)
        {
            delete(list, index);
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