#include <bits/stdc++.h> 
int isPreorderValid(vector<int> &arr) 
{
    // Write your code here
    stack<int> st;
    int root = INT_MIN;

    int n = arr.size();

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] < root) return 0;
        while(!st.empty() && st.top() < arr[i]){
            root = st.top(); st.pop();
        }

        st.push(arr[i]);
    }

    return 1;
}
