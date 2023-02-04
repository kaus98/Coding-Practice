#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

vector<int> NextSmallestRight(vector<int> arr){
  stack<int> st;
  vector<int> ans;
  for(int i = arr.size()-1; i>=0; i--) {
    while(!st.empty() && st.top() >= arr[i]) st.pop();
    if(st.empty()) ans.push_back(-1);
    else ans.push_back(st.top());
    st.push(arr[i]);
  }
  reverse(ans.begin(), ans.end());
  for(auto x : ans) cout<<x<<"\t";
  return ans;
}

int main(){
  // Question is to find the Nearest bigger element next to Right Side.
  vector<int> arr{1,4,2,3,5,4,1,2,4,6,2,5,1,0,9,2,8,2,1,6,7,3,65,3,4,6,2,1,7,3,9};
  vector<int>result = NextSmallestRight(arr);
  return 0;
}
