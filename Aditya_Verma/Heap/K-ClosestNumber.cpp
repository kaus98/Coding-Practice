#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;

vector<int> KthClosestNumber(vector<int> arr, int K, int X){
  //Get the top X numbers that are nearest to number of K.
  
  priority_queue <pi> maxHeap;
  vector<int> result;
  
  for(auto i: arr){
    maxHeap.push(make_pair(abs(i-K) , i));
    if(maxHeap.size() > X) maxHeap.pop();
  }

  while(!maxHeap.empty()){
    result.push_back(maxHeap.top().second);
    maxHeap.pop();
  }

  return result;
  
}

int main(){
  vector<int> arr{6,5,3,2,9,10,8,14,12,11};
  vector<int> k = KthClosestNumber(arr, 10, 5);
  cout<<"Sorted Array is "<<endl;
  for(auto x: k) cout<<x<<"\t";
}