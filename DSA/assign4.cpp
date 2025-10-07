#include <iostream>
using namespace std;

struct node
{
    int item;
    node *next = nullptr;
};

class singleLL
{
private:
    node *start;

public:
    singleLL();
    void insertAtStart(int);
    void insertAtLast(int);
    void insertAtAfter(node *, int);
    node *search(int);
    void deleteFirst();
    void deleteLast();
    void deleteNode(int);
    ~singleLL();
};
singleLL::singleLL()
{
    start = nullptr;
}
void singleLL::insertAtStart(int data)
{
    node *n1 = new node;
    n1->item = data;
    n1->next = start;
    start = n1;
}
void singleLL::insertAtLast(int data)
{
    node *n1 = new node;
    node *t;
    n1->item = data;
    n1->next = nullptr;
    if (start == nullptr)
    {
        start = n1;
    }
    else
    {
        t = start;
        while (t->next != nullptr)
        {
            t = t->next;
        }
        t->next = n1;
    }
}
node *singleLL::search(int data)
{
    node *t = start;
    while (t != nullptr)
    {
        if (t->item == data)
            return t;
        t = t->next;
    }
    return nullptr;
}
void singleLL::insertAtAfter(node *t, int data)
{
    if (t != nullptr)
    {
        node *n1 = new node;
        n1->item = data;
        n1->next = t->next;
        t->next = n1;
    }
}
void singleLL::deleteFirst()
{
    node *t;

    if (start)
    {
        t = start;
        start = start->next;
        delete t;
    }
}
void singleLL::deleteLast()
{
    node *t;
    if (start)
    {
        if (start->next == nullptr)
        {
            delete start;
            start = nullptr;
        }
        else
        {
            t = start;
            while (t->next->next != nullptr)
            {
                t = t->next;
                delete t->next;
                t->next = nullptr;
            }
        }
    }
}
void singleLL::deleteNode(int data)
{
    node *t1, *t2;
    if (start)
    {
        t2 = search(data);
        if (t2)
        {
            t1 = start;
            if (t1 == t2)
            {
                deleteFirst();
            }
            else
            {
                while (t1->next != t2)
                {
                    t1 = t1->next;
                    t1->next = t2->next;
                    delete t2;
                }
            }
        }
    }
}
singleLL::~singleLL()
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