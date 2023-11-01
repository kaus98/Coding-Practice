#include <bits/stdc++.h> 
class Stack
{
public:
    // Initialize your data structure.
    deque<int> q;
    Stack()
    {
    }

    // Pushes 'X' into the stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x)
    {
        // Write your code here.
        q.push_back(x);
        return true;
    }

    // Pops top element from Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop()
    {
        // Write your code here.
        if(q.size() > 0){
            int temp = q.back();
            q.pop_back();
            return temp;
        } else return -1;
    }

    // Returns the topmost element of the stack. In case the stack is empty, it returns -1.
    int top()
    {
        // Write your code here.
        if(q.size() > 0){
            return q.back();
        }
        else return -1;

    }

    // Returns true if the stack is empty, otherwise false.
    bool isEmpty()
    {
        // Write your code here.
        return q.empty();
    }

    // Returns the number of elements currently present in the stack.
    int size()
    {
        // Write your code here.
        return q.size();
    }
};