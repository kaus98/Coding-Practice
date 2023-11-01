class SpecialStack {
    public:
    stack<int> st;
    int mini = INT_MAX;

    void push(int data) {
        // Implement the push() function.
        // st.push(data);
        // If this is first element or pushing element is greater than current Min
        if(st.size() == 0) {st.push(data); mini = data;}
        else if(data>mini) st.push(data);
        else {
            st.push(2*data - mini);
            mini = data;
        }
    }

    void pop() {
        // Implement the pop() function.
        if(st.empty()) return;
        if(st.top() > mini) st.pop();
        else {
            mini = 2*mini - st.top();
            st.pop();
        }
    }

    int top() {
        // Implement the top() function.
        // return st.top();
        if(st.empty()) return -1;
        if(st.top() > mini) return st.top();
        else return mini;
    }

    int getMin() {
        // Implement the getMin() function.
        return mini;
    }  
};