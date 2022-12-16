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

int main(){
  // Question is to find the Nearest bigger element next to Right Side.
  vector<int> arr{2,1,5,6,2,3};
  int result = MaximumAreaHistogram(arr);
  cout<< "Result is : "<<result;
  return 0;
}