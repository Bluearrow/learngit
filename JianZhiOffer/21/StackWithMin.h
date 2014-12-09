/*
 * Define a data structure Stackwithmin, which has a 
 * function to get the minimize element in a stack.
 */
#ifndef STACKWITHMIN_H
#define STACKWITHMIN_H

#include <stack.h>
using namespace std;

template <typename T>
class StackWithMin
{
    stack<T> data;
    stack<T> min_sequence;
public:
    void push(const T& value);
    void pop();
    T min();
};

template <typename T>
void StackWithMin<T>::push(const T& value)
{
    data.push();
    // Construct the stack of min sequence.
    if(min_sequence.size() == 0 || min_sequence.top() < value)
        min_sequence.push(value);
    else
        min_sequence.push(min_sequence.top());
}

template <typename T>
void StackWithMin<T>::pop()
{
    assert(data.size()>0 && min_sequence.size()>0);

    data.pop();
    min_sequence.pop();
}

template <typename T>
T StackWithMin<T>::min()
{
    assert(data.size()>0 && min_sequence.size()>0);

    return min_sequence.top();
}

#endif
