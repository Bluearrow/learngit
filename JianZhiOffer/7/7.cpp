template <Typename T>
class CQueue
{
    stack<T> stack1;
    stack<T> stack2;
public:
    CQueue(void);
    ~CQueue(void);

    void appendTail(const T& node);
    T deleteHead();
};

template <Typename T>
CQueue<T>::appendTail(const T& node)
{
    stack1.push(node);
}

template <Typename T>
T CQueue<T>::deleteHead()
{
    // If stack2 is not empty.
    if(stack2.size() != 0)
        return stack2.pop();
    // If stack2 is empty and stack1 is not.
    else if(stack1.size() != 0)
    {
        // Pop all nodes to stack2.
        while(stack1.size() != 0)
            stack2.push(stack1.pop());
        return stack2.pop();
    }
    // There is no nodes in stack1 and stack2.
    else
    {
        cout << "There is no element to pop." << endl;
        return NULL;
    }
}
