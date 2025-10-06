#include <iostream>
#define OVERFLOW 1
#define INVALID_INDEX 2
#define UNDERFLOW 3

using namespace std;

class Array
{
private:
    int capacity;
    int lastInd;
    int *ptr;

public:
    Array(int);

    bool isEmpty();
    void append(int);
    bool isFull();
    void insert(int, int);
    void edit(int, int);
    void del(int);
    int getValue(int);
    int count();
    ~Array();
    int find(int);
    void print();
};
Array::Array(int cap)
{
    capacity = cap;
    lastInd = -1;
    ptr = new int[capacity];
}

bool Array::isEmpty()
{
    return lastInd == -1;
}
void Array::append(int data)
{
    if (lastInd == capacity - 1)
        throw OVERFLOW;
    lastInd++;

    ptr[lastInd] = data;
}
bool Array::isFull()
{
    return lastInd == capacity - 1;
}
void Array::insert(int ind, int data)
{
    if (ind < 0 || ind > lastInd + 1)
    {
        throw INVALID_INDEX;
    }
    if (isFull())
    {
        throw OVERFLOW;
    }
    for (int i = lastInd; i >= ind; i--)
    {
        ptr[i + 1] = ptr[i];
    }
    ptr[ind] = data;
    lastInd++;
}
void Array::edit(int ind, int data)
{

    if (ind < 0 || ind > lastInd)
    {
        throw INVALID_INDEX;
    }
    ptr[ind] = data;
}
void Array::del(int ind)
{
    if (lastInd == -1)
    {
        throw UNDERFLOW;
    }
    for (int i = ind; i < lastInd; i++)
    {
        ptr[i] = ptr[i + 1];
    }
    lastInd--;
}

int Array::getValue(int ind)
{
    if (ind < 0 || ind > lastInd)
        throw INVALID_INDEX;
    return ptr[ind];
}
int Array::count()
{
    return lastInd + 1;
}

int Array::find(int ele)
{
    for (int i = 0; i < lastInd + 1; i++)
    {
        if (ptr[i] == ele)
        {
            return i;
        }
    }
    return -1;
}
void Array::print()
{
    if (isEmpty())
    {
        cout << "array is empty.";
        return;
    }
    cout << "Array is : ";
    for (int i = 0; i <= lastInd; i++)
    {
        cout << ptr[i] << " ";
    }
    cout << endl;
}
Array::~Array()
{
    delete[] ptr;
    cout << "destructor called" << endl;
}

int main()
{
    Array arr(5);
    arr.append(1);
    cout << endl;

    arr.print();
    arr.append(2);
    cout << endl;
    arr.print();
    arr.insert(1, 4);

    arr.print();
    arr.edit(1, 3);
    cout << endl;
    arr.print();
    arr.del(1);
    arr.print();
    cout << endl;
    cout << "Array 2 with copy constructor : " << endl;
    Array arr2 = arr;
    arr2.append(5);
    arr2.print();
    cout << "Array 1 :" << endl;
    arr.print();

    // Array a1(5);
    // a1.append(1);
    // a1.append(2);
    // a1.append(3);

    // Array a2 = a1;
    // a2.append(4);
    // cout << "Array 1 : ";
    // a1.print();
    // cout << "Array 2 : ";
    // a2.print();
    return 0;
}