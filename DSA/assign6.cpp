#include <iostream>
using namespace std;

struct node
{
    int item;
    node *next;
};

class CLL
{
private:
    node *last;

public:
    CLL();
    ~CLL();
    void insertAtFirst(int);
    void insertAtLast(int);
    node *search(int);
    void insertAfter(node *, int);
    void deleteFirst();
    void deleteLast();
    void deleteNode(int);
};
CLL::CLL()
{
    last = nullptr;
}
void CLL::insertAtFirst(int data)
{
    node *n = new node;
    n->item = data;
    if (last == nullptr)
    {
        n->next = n;
        last = n;
    }
    if (last->next == last)
    {
        n->next = last;
        last->next = n;
    }
    else
    {
        n->next = last->next;
        last->next = n;
    }
}
void CLL::insertAtLast(int data)
{
    node *n = new node;
    n->item = data;
    if (last == nullptr)
    {
        n->next = n;
        last = n;
    }
    if (last->next == last)
    {
        n->next = last->next;
        last->next = n;
        last = n;
    }
    else
    {
        n->next = last->next;
        last->next = n;
        last = n;
    }
}

node *CLL::search(int data)
{
    node *t;
    if (last)
    {
        t = last->next;
        do
        {
            if (t->item == data)
                return t;
            t = t->next;
        } while (t != last->next);
    }
    return nullptr;
}
void CLL::insertAfter(node *temp, int data)
{
    if (temp)
    {
        node *n = new node;
        n->item = data;
        n->next = temp->next;
        temp->next = n;
        if (last == temp)
            last = n;
    }
}
void CLL::deleteFirst()
{
    if (last)
    {
        if (last->next == last)
        {
            delete last;
            last = nullptr;
        }
        else
        {
            node *t;
            t = last->next;
            last->next = t->next;
            delete t;
        }
    }
}
void CLL::deleteLast()
{
    if (last)
    {
        if (last->next == last)
        {
            delete last;
            last = nullptr;
        }
        else
        {
            node *t;
            t = last->next;
            while (t->next != last)
                t = t->next;
            t->next = last->next;
            delete last;
            last = t;
        }
    }
}
void CLL::deleteNode(int data)
{
    node *temp, *t;
    temp = search(data);
    if (temp)
    {
        if (temp == last)
        {
            deleteLast();
        }
        else
        {
            t = last->next;
            while (t->next != temp)
                t = t->next;
            t->next = temp->next;
            delete temp;
        }
    }
}
CLL::~CLL()
{
    while (last)
    {
        deleteFirst();
    }
}
int main()
{

    return 0;
}
