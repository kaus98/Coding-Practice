#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

vector<int> SortNearlySortedArray(vector<int>& arr, int k){
  priority_queue<int> maxHeap;
  vector<int> arr;
  for(auto x: arr){
    maxHeap.push(x);
    if(maxHeap.size() > k) {
      arr.push_back(maxHeap.top());
      maxHeap.pop();
    }
  }
  while(!maxHeap.empty()){
    arr.push_back(maxHeap.top());
    maxHeap.pop();
  }
  return arr;
}

int main(){
  vector<int> arr{6,5,3,2,9,10,8,14,12,11};
  vector<int> k = KthSmallestElement(arr, 4);
  cout<<"Sorted Array is "<<endl;
  fors( auto x: :k) cout<<k<<"\t";
}