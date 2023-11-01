#include <bits/stdc++.h> 
class Queue {
public:
    vector<int> arr;

    Queue() {
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(arr.size() == 0) return true;
        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        arr.push_back(data);
    }

    int dequeue() {
        // Implement the dequeue() function
        if (arr.size() == 0) return -1;
        int temp = arr[0];
        arr.erase(arr.begin());
        return temp;
    }

    int front() {
        // Implement the front() function
        if(arr.size() == 0) return -1;
        return arr[0];
    }
};