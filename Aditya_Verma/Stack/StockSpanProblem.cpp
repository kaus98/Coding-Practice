#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

vector<int> StockSpanProblem(vector<int> arr) {
  stack<int> st;
  vector<int> ans;
  for(int i =0; i<arr.size(); i++) {
    while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
    if(st.empty()) ans.push_back(i+1);
    else ans.push_back(i - st.top());
    st.push(i);
  }
  
  for(auto x : ans) cout<<x<<"\t";
  return ans;
}

int main(){
  // Question is to find the Nearest bigger element next to Right Side.
  vector<int> arr{1,1,1,4,2,3,5,4,1,2,4,6,2,5,1,0,9,2,8,2,1,6,7,3,65,3,4,6,2,1,7,3,9};
  vector<int>result = StockSpanProblem(arr);
  return 0;
}
