#include<bits/stdc++.h>

vector<int> nextGreaterElement(vector<int>& arr, int n)
{
        // Your code here
        stack<int> st;
        int temp;
        
        for(int i = n-1; i >= 0; i--){
            temp = arr[i];
            
            while(st.size() > 0 && st.top() <= temp){
                st.pop();
            }
            
            if(st.size() == 0) arr[i] = -1;
            else arr[i] = st.top();

            st.push(temp);
        }
        
        return arr;
}