#ifndef NODE_H
#define NODE_H

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

#endif