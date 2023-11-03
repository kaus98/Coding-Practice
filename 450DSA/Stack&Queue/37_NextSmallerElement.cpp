#include<bits/stdc++.h>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> st;

    for(int i = n-1; i>=0; i--){

        while(st.empty() != true && st.top() >= arr[i]){
            st.pop();
        }

        int tp = arr[i];
        if(!st.empty()) arr[i] = st.top();
        else arr[i] = -1;

        st.push(tp);
    }
    return arr;
}