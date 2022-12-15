#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

int TrappedWaterStack(vector<int> arr){
  // Require to Return the Area of water trapped inside between walls
  // Beats 82% of solution on Leetcode
  // Beats 38.24% of memory on Leetcode
  stack<int> st;
  int ans = 0;
  for(int i = 0; i < arr.size(); i++){
    while(!st.empty() && (arr[st.top()] < arr[i])){
      // Calulations Here
      int hei = arr[st.top()];
      st.pop();
      if(!st.empty()) 
      {
        int dis = i - st.top() - 1;

        int hei2  = min(arr[i], arr[st.top()]) - hei;
        ans += hei2*dis;
        // cout<<"Calculating the Trapped Water. I : "<<i<<" hei : "<<hei<<" dis : "<<dis<<" hei2 : "<<hei2<<" ans : "<<ans; 
        cout<<"Arr[i] : "<<arr[i]<<"\t Arr[st.top()] : "<<arr[st.top()]<<"\t Height : "<<hei<<" Hei2 : "<<hei2<<" Dis : "<<dis<<endl;
      }
    }
    
    cout<<"Pushing i value to ST : "<<i<<endl;
    st.push(i);
    
  }
  return ans;
}

int TrappedWaterArray(vector<int> arr){
  // Beats 87.60% of solution on Leetcode
  // Beats 62.40% of memory on Leetcode
  int forward[arr.size()], backward[arr.size()];
  forward[0] = 0;
  backward[arr.size()-1] = arr.size()-1;
  for(int i = 1,j = arr.size()-2; i<arr.size();i++,j--){
    if(arr[i] > arr[forward[i-1]]) forward[i] = i;
    else forward[i] = forward[i-1];
    if(arr[j] > arr[backward[j+1]]) backward[j] = j;
    else backward[j] = backward[j+1];
  }

  for(auto x: forward) cout<<x<<"\t";
  cout<<endl;
  for(auto x: backward) cout<<x<<"\t";
  cout<<endl;
  
  int ans=0;
  int temp;
  for(int i = 0; i<arr.size();i++){
    if(forward[i] == i || backward[i]==i) continue;
    // temp = max( (backward[i] - forward[i] - 1) * (min(arr[backward[i]], arr[forward[i]]) - arr[i]) , 0 );
    temp = max((min(arr[backward[i]], arr[forward[i]]) - arr[i]) , 0 );
    ans+=temp;
    cout<<"Temp at i: "<<i<<"  ans : "<<ans<<" temp : "<<temp<<endl;
  }
  return ans;
}

int main(){
  vector<int> arr{1,4,2,3,5,7,2,5,3};
  int ans = TrappedWaterArray(arr);
  cout<<ans;
  return 0;
}