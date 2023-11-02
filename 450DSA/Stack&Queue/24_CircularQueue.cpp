#include <bits/stdc++.h> 
class CircularQueue{
    public:
    // Initialize your data structure.
    queue<int> q;
    int size; 
    CircularQueue(int n){
        // Write your code here.
        size = n;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.
        if(q.size() == size) return false;
        q.push(value);
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        if(q.size() == 0) return -1;

        int ans = q.front();
        q.pop();
        return ans;
    }
};