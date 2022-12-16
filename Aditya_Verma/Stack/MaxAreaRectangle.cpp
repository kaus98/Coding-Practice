#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;


vector<int> NextSmallestLeft(vector<int> arr){
  stack<int> st;
  vector<int> ans;
  for(int i =0; i<arr.size(); i++) {
    while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
    if(st.empty()) ans.push_back(-1);
    else ans.push_back(st.top());
    st.push(i);
  }
  // reverse(ans.begin(), ans.end());
  cout << "Printing Left Smallest : "<<endl;
  for(auto x : ans) cout<<x<<"\t";
  cout<<endl;
  return ans;
}

vector<int> NextSmallestRight(vector<int> arr){
  stack<int> st;
  vector<int> ans;
  for(int i = arr.size()-1; i>=0; i--) {
    while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
    if(st.empty()) ans.push_back(arr.size());
    else ans.push_back(st.top());
    st.push(i);
  }
  
  reverse(ans.begin(), ans.end());
  cout << "Printing Right Smallest : "<<endl;
  for(auto x : ans) cout<<x<<"\t";
  cout<<endl;
  return ans;
}


int MaximumAreaHistogram(vector<int> arr){
  vector<int> NextR = NextSmallestRight(arr);
  vector<int> NextL = NextSmallestLeft(arr);
  int maximum = 0;

  for(int i = 0; i < arr.size(); i++){
    maximum = max(maximum, (NextR[i]-NextL[i]-1)*arr[i]);
  }
  return maximum;
}

int maximalRectangle(vector<vector<char>>& matrix) {
  vector<int> arr ;
  for(int i = 0 ; i < matrix[0].size(); i++){
    arr.push_back(matrix[0][i]-48);
  }
  int ans = MaximumAreaHistogram(arr);

  for(int i = 1; i < matrix.size(); i++){
    for(int j = 0; j < matrix[0].size(); j++){
      if(matrix[i][j] == 48) arr[j] = 0;
      else arr[j] += 1;
    }
    ans = max(ans, MaximumAreaHistogram(arr));
  }
  return ans;
}

int main(){
  //Tested on Leetcode. Workes Fine.
  return 0;
}