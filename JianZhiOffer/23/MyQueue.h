/* Implement a queue with linked list of class T */
#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>
using namespace std;

template <class T>
struct QNode
{
    T value;
    QNode<T>* pNext;
};

// Dequeue from head, enqueue from tail.
template <class T>
class MyQueue{
    unsigned int size;
    QNode<T>* head;
    QNode<T>* tail;
public:
    MyQueue();
    ~MyQueue();
    bool IsEmpty();
    void EnQueue(T x);
    T DeQueue();
    void PrintQueue();
    unsigned int len();
};


// Create a head node.
template<class T>
MyQueue<T>::MyQueue()
{
   QNode<T>* p = new QNode<T>;
   if(p == NULL)
       cout << "Not enough space." << endl;
   p->value = (T)0;
   p->pNext = NULL;
   head = p;
   tail = p;
   size = 0;
}

template<class T>
MyQueue<T>::~MyQueue()
{
    QNode<T>* p = new QNode<T>;
    while(head != NULL)
    {
        p = head;
        head = head->pNext;
        delete p;
    }
}

template<class T>
bool MyQueue<T>::IsEmpty()
{
    if(size == 0)
        return true;
    else
        return false;
}

template<class T>
void MyQueue<T>::EnQueue(T x)
{
    QNode<T>* p = new QNode<T>;
    if(p == NULL)
    {
        cout << "There is no space." << endl;
        return;
    }
    // Initialize p.
    p->value = x;
    p->pNext = NULL;
    // Insert p at the tail and move tail to it.
    tail->pNext = p;
    tail = p;
    size++;
}

template<class T>
T MyQueue<T>::DeQueue()
{
    if(size == 0)
    {
        cout << "The queue is empty." << endl;
        return 0;
    }

    // Delete from head.
    QNode<T>* p = head->pNext;
    head->pNext = p->pNext;
    T result = p->value;
    // Delete the node.
    delete p;
    p = NULL;
    size--;
    return result;
}

template<class T>
unsigned int MyQueue<T>::len()
{
    return size;
}

template<class T>
void MyQueue<T>::PrintQueue()
{
    QNode<T>* p = head->pNext;
    while(p != NULL)
    {
        cout << p->value << " ";
        p = p->pNext;
    }
    cout << endl;
}
#endif
