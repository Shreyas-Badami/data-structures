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
    void insertAtHead(T d);
    void displayLL();
};

template <class T>
void linklist<T>::insertAtHead(T d)
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
    l.insertAtHead(2);
    l.insertAtHead(6);
    l.displayLL();
    l.insertAtHead(7);
    l.displayLL();
}