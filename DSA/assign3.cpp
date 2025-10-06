#include <iostream>
#define OVERFLOW 1
#define INVALID_INDEX 2
#define UNDERFLOW 3

using namespace std;

class dynArray
{
private:
    int capacity;
    int lastInd;
    int *ptr;

public:
    dynArray(int);
    dynArray(dynArray &);
    dynArray &operator=(dynArray &);
    bool isEmpty();
    void append(int);
    bool isFull();
    void insert(int, int);
    void edit(int, int);
    void del(int);
    int getValue(int);
    int count();
    ~dynArray();
    int find(int);
    void print();
    void doubleArray();
    void halfArray();
};
void dynArray::doubleArray(){
    int *temp;
    temp = new int[capacity*2];
    for(int i = 0; i <= lastInd; i++){
        temp[i] = ptr[i];
    }
    delete[] ptr;
    ptr = temp;
capacity *= 2; 
}
void dynArray::halfArray(){
    int *temp;
    temp = new int[capacity/2];
    for(int i = 0; i <= lastInd; i++){
        temp[i] = ptr[i];
    }
    delete[] ptr;
    ptr = temp;
capacity /= 2; 
}
dynArray::dynArray(int cap)
{
    capacity = cap;
    lastInd = -1;
    ptr = new int[capacity];
}
dynArray::dynArray(dynArray &a)
{
    capacity = a.capacity;
    lastInd = a.lastInd;
    ptr = new int[capacity];
    for (int i = 0; i <= lastInd; i++)
    {
        ptr[i] = a.ptr[i];
    }
}
dynArray &dynArray::operator=(dynArray &a)
{
    if (ptr != nullptr)
    {
        delete[] ptr;
    }
    capacity = a.capacity;
    lastInd = a.lastInd;
    ptr = new int[capacity];
    for (int i = 0; i <= lastInd; i++)
    {
        ptr[i] = a.ptr[i];
    }

    return *this;
}
bool dynArray::isEmpty()
{
    return lastInd == -1;
}
void dynArray::append(int data)
{
    if (lastInd == capacity - 1)
        doubleArray();
    lastInd++;

    ptr[lastInd] = data;
}
bool dynArray::isFull()
{
    return lastInd == capacity - 1;
}
void dynArray::insert(int ind, int data)
{
    if (ind < 0 || ind > lastInd + 1)
    {
        throw INVALID_INDEX;
    }
    if (isFull())
    {
        doubleArray();
    }
    for (int i = lastInd; i >= ind; i--)
    {
        ptr[i + 1] = ptr[i];
    }
    ptr[ind] = data;
    lastInd++;
}
void dynArray::edit(int ind, int data)
{

    if (ind < 0 || ind > lastInd)
    {
        throw INVALID_INDEX;
    }
    ptr[ind] = data;
}
void dynArray::del(int ind)
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
    if(count() == capacity/2)
       halfArray();
}

int dynArray::getValue(int ind)
{
    if (ind < 0 || ind > lastInd)
        throw INVALID_INDEX;
    return ptr[ind];
}
int dynArray::count()
{
    return lastInd + 1;
}

int dynArray::find(int ele)
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
void dynArray::print()
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
dynArray::~dynArray()
{
    delete[] ptr;
    cout << "destructor called" << endl;
}

int main()
{
    // Array arr(5);
    // arr.append(1);
    // cout << endl;

    // arr.print();
    // arr.append(2);
    // cout << endl;
    // arr.print();
    // arr.insert(1, 4);

    // arr.print();
    // arr.edit(1, 3);
    // cout << endl;
    // arr.print();
    // arr.del(1);
    // arr.print();
    // cout << endl;
    // cout << "Array 2 with copy constructor : " << endl;
    // Array arr2 = arr;
    // arr2.append(5);
    // arr2.print();
    // cout << "Array 1 :" << endl;
    // arr.print();

    dynArray a1(5);
    a1.append(1);
    a1.append(2);
    a1.append(3);

    dynArray a2 = a1;
    a2.append(4);
    cout << "Array 1 : ";
    a1.print();
    cout << "Array 2 : ";
    a2.print();
    return 0;
}