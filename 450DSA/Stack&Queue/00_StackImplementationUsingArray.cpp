// Stack class.
class Stack {
    
public:
    vector<int>  arr;
    int cap;

    Stack(int capacity) {
        // Write your code here.
        // vector<int>  arr;
        this->cap = capacity;
    }

    void push(int num) {
        // Write your code here.

        if(arr.size() < this->cap) arr.push_back(num);
    }

    int pop() {
        // Write your code here.
        if(arr.size() == 0) return -1;

        int back = arr[arr.size()-1];
        arr.pop_back();
        return back;
    }
    
    int top() {
        // Write your code here.
        if(arr.size() == 0) return -1;
        int back = arr[arr.size()-1];
        return back;
    }
    
    int isEmpty() {
        // Write your code here.
        if(arr.size() == 0) return 1;
        else return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(arr.size() == this->cap) return 1;
        else return 0;
    }
    
};
