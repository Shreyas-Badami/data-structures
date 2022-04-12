#ifndef MY_DLL
#define MY_DLL
#include "node.h"

struct my_dll
{
    struct Node *root;
    struct Node *tail;
    int size;
};

void insert(struct my_dll*, int);
void insert_at(struct my_dll*, int, int);
void delete(struct my_dll*, int);
int find(struct my_dll*, int);
void prune(struct my_dll*);
void print(struct my_dll*);
void print_reverse(struct my_dll*);
int get_size(struct my_dll*);

#endif