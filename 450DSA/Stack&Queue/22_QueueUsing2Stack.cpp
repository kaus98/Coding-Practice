#include <bits/stdc++.h> 
class Queue{
    // Stacks to be used in the operations.
    stack<int> stk1, stk2;
    
    public:
    // Enqueues 'X' into the queue. Returns true after enqueuing.
    bool enqueue(int X){
        // Write your code here.
        stk1.push(X);
        return true;
    }

    /*
      Dequeues top element from queue. Returns -1 if the queue is empty, 
      otherwise returns the popped element.
    */
    int dequeue(){
        // Write your code here.

        if(stk1.empty()) return -1;

        while(stk1.size()){
            stk2.push(stk1.top());

            stk1.pop();
        }
        int temp = stk2.top();
        stk2.pop();

        while(stk2.size()){
            stk1.push(stk2.top());

            stk2.pop();
        }

        return temp;
    }
};