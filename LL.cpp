#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *next;
};

template <class T>
class linklist
{
private:
    Node<T>* head;
public:
    linklist()
    { head = NULL; }
    void insert(T d);
    void displayLL();
};

template <class T>
void linklist<T>::insert(T d)
{
    Node<T> *newNode = new Node<T>;
    newNode->data = d;
    newNode->next = head;
    head = newNode;
}

template <class T>
void linklist<T>::displayLL()
{
    Node<T>* current = head;
    while( current != NULL )
    {
        cout << current->data << endl;
        current = current->next;
    }
}

int main()
{
    linklist<int> l;
    l.insert(2);
    l.insert(6);
    l.displayLL();
    l.insert(7);
    l.displayLL();
}