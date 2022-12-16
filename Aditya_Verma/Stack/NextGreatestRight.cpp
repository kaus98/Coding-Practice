#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

void NextGreatestRight(vector<int>& arr){
  stack<int> st;
  // st.push_back(-1);
  vector<int> ans;
  for(int i = arr.size() - 1; i>=0; i--) {
    while(!st.empty() && st.top() <= arr[i]) st.pop();
    if(st.empty()) ans.push_back(-1);
    else ans.push_back(st.top());
    // else if(st.top() > arr[i]) ans.push_back(st.top());
    // else cout<<"Unexpected Condition Found. Start Debugging !!";
    st.push(arr[i]);
  }
  reverse(ans.begin(), ans.end());
  for(auto x : ans) cout<<x<<"\t";
  // return ans;
}

int main(){
  // Question is to find the Nearest bigger element next to Right Side.

  vector<int> arr{1,4,2,3,5,7};
  NextGreatestRight(arr);
  return 0;
}
