#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

vector<int> SortNearlySortedArray(vector<int> arr, int k){
  //Sort the Array that is nearly sorted and only shuffeled by factor of x
  priority_queue <int, vector<int>, greater<int>> minHeap;
  vector<int> result;
  for(auto x: arr){
    minHeap.push(x);
    if(minHeap.size() >= k) {
      result.push_back(minHeap.top());
      minHeap.pop();
    }
  }
  while(!minHeap.empty()){
    result.push_back(minHeap.top());
    minHeap.pop();
  }
  return result;
}

int main(){
  vector<int> arr{6,5,3,2,9,10,8,14,12,11};
  vector<int> k = SortNearlySortedArray(arr, 4);
  cout<<"Sorted Array is "<<endl;
  for(auto x: k) cout<<x<<"\t";
}