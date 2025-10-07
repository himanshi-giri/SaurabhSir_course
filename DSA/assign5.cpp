#include <iostream>
using namespace std;

struct node
{
    node *prev;
    int item;
    node *next;
};

class DLL
{
private:
    node *start;

public:
    DLL();
    void insertAtStart(int);
    void insertAtLast(int);
    node *search(int);
    void insertAtAfter(node *, int);
    void deleteFirst();
    void deleteLast();
    void deleteNode(int);
    ~DLL();
};
DLL::DLL()
{
    start = nullptr;
}
void DLL::insertAtStart(int data)
{
    node *n1 = new node;

    n1->item = data;
    n1->next = start;
    n1->prev = nullptr;
    if (start)
    {
        start->prev = n1;
    }
    start = n1;
}
void DLL::insertAtLast(int data)
{
    node *n1 = new node;
    node *t = start;

    n1->item = data;
    n1->next = nullptr;
    if (start == nullptr)
    {
        n1->prev = start;
        start = n1;
    }
    else
    {
        while (t->next != nullptr)
            t = t->next;
        n1->prev = t;
        t->next = n1;
    }
}
node *DLL::search(int data)
{
    node *t = start;
    if (start)
    {
        while (t != nullptr)
        {
            if (t->item == data)
            {
                return t;
            }
            t = t->next;
        }
        return nullptr;
    }
}
void DLL::insertAtAfter(node *t, int data)
{
    if (t != nullptr)
    {
        node *n1 = new node;
        n1->item = data;
        n1->next = t->next;
        n1->prev = t;
        if (t->next != nullptr)
            t->next->prev = n1;
        t->next = n1;
    }
}
void DLL::deleteFirst()
{
    node *t;
    if (start)
    {
        t = start;
        start = start->next;
        if (start)
            start->prev = nullptr;
        delete t;
    }
}
void DLL::deleteLast()
{
    node *t;
    t = start;

    if (t->next == nullptr) // single node
    {
        delete start;
        start = nullptr;
    }
    else
    {
        while (t->next->next != nullptr)
            t = t->next;
        delete t->next;
        t->next = nullptr;
    }
}
void DLL::deleteNode(int data)
{
    node *temp;
    temp = search(data);
    if (temp)
    {
        if (temp->next != nullptr) // temp is not last node
            temp->next->prev = temp->prev;
        if (temp->prev != nullptr) // temp is not the first node
            temp->prev->next = temp->next;
        else // temp is first node
            start = start->next;
        delete temp;
    }
}
DLL::~DLL()
{
    while (start)
        deleteFirst();
}
int main()
{

    return 0;
}