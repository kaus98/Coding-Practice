#include <bits/stdc++.h> 
class TwoStack {

public:

    // Initialize TwoStack.
    vector<int> arr;
    int sz;
    int back2 = 0;
    int back1 = 0;
    TwoStack(int s) {
        // Write your code here.
        // arr.resize(s);
        this->sz = s;
        this->back1 = -1;
        this->back2 = s;
        this->arr.resize(s);
    }
    
    // Push in stack 1.
    void push1(int num) {
        // Write your code here.
        // if(arr.size() < sz) {arr.insert(arr.begin(), num); back1++;}
        if(back1+1 < back2) arr[++back1] = num;
    }

    // Push in stack 2.
    void push2(int num) {
        // Write your code here.
        // if(arr.size() < sz) {arr.push_back(num); back2++;}
        if(back2-1 > back1) arr[--back2] = num;
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        // Write your code here.
        if(back1==-1) return -1;
        return arr[back1--];
        // int temp = arr[0];
        // arr.erase(arr.begin());
        // back1--;
        // return temp;
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        // Write your code here.
        if(back2==sz) return -1;
        return arr[back2++];

        // if(arr.size() == 0 || back2 == 0 || back1 == sz) return -1;
        // int temp = arr[arr.size()-1];
        // arr.pop_back();
        // back2--;
        // return temp;
    }
};

