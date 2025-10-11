#include <iostream>
using namespace std;

struct node
{
    int item;
    node *next;
    node *prev;
};

class CDLL
{
private:
    node *start;

public:
    CDLL();
    ~CDLL();
    void insertAtFirst(int);
    void insertAtLast(int);
    node *search(int);
    void insertAfter(node *, int);
    void deleteFirst();
    void deleteLast();
    void deleteNode(int);
};
CDLL::CDLL()
{
    start = nullptr;
}
void CDLL::insertAtFirst(int data)
{
    node *n = new node;
    n->item = data;

    if (start == nullptr)
    {
        n->next = n;
        n->prev = n;
        start = n;
    }
    else
    {
        n->prev = start->prev;
        n->next = start;
        start->prev->next = n;
        start->prev = n;
        start = n;
    }
}
void CDLL::insertAtLast(int data)
{
    node *n = new node;
    n->item = data;
    if (start == nullptr)
    {
        n->prev = n;
        n->next = n;
        start = n;
    }

    else
    {
        n->next = start;
        n->prev = start->prev;
        start->prev->next = n;
        start->prev = n;
    }
}

node *CDLL::search(int data)
{

    node *t;
    if (start)
    {
        t = start;
        do
        {
            if (t->item == data)
                return t;
            t = t->next;
        } while (t != start);
    }
    return nullptr;
}
void CDLL::insertAfter(node *temp, int data)
{
    if (temp)
    {
        node *n = new node;
        n->item = data;
        n->prev = temp;
        n->next = temp->next;
        temp->next->prev = n;
        temp->next = n;
    }
}
void CDLL::deleteFirst()
{
    if (start)
    {
        if (start->next == start)
        {
            delete start;
            start = nullptr;
        }
        else
        {
            start->prev->next = start->next;
            start->next->prev = start->prev;
            node *t;
            t = start;
            start = start->next;
            delete t;
        }
    }
}
void CDLL::deleteLast()
{
    if (start)
    {
        if (start->next == start)
        {
            delete start;
            start = nullptr;
        }
        else
        {
            node *t = start->prev; // t points to last node
            t->prev->next = start;
            start->prev = t->prev;
            delete t;
        }
    }
}
void CDLL::deleteNode(int data)
{
    node *temp;
    temp = search(data);
    if (temp)
    {
        if (temp == start)
        {
            deleteFirst();
        }
        else
        {
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            delete temp;
        }
    }
}
CDLL::~CDLL()
{
    while (start)
    {
        deleteFirst();
    }
}
int main()
{

    return 0;
}
