void InsertAtBottom(stack<int> &st, int x){
    if(st.empty()){
        st.push(x);
        return;
    }
    int temp = st.top();
    st.pop();
    InsertAtBottom(st, x);
    st.push(temp);

}

void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.empty()) return;
    int t = stack.top();
    stack.pop();

    reverseStack(stack);
    InsertAtBottom(stack, t);

}