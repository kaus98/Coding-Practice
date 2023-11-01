#include<bits/stdc++.h>

int longestValidParentheses(string str)
{
    // Write your code here.
    stack<int> st;
    st.push(-1);

    int mx = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '(') st.push(i);
        else {
            if(!st.empty()){
                st.pop();

                if(st.empty()) st.push(i);
                else mx = max(mx, i - st.top());
            }
        }
    }

    return mx;
}