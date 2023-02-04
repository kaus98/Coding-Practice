#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

int KthSmallestElement(vector<int>& arr, int k){
  priority_queue<int> maxHeap;

  for(auto x: arr){
    maxHeap.push(x);
    if(maxHeap.size() > k) maxHeap.pop();
  }
  return maxHeap.top();
}

int main(){
  vector<int> arr{1,4,2,3,5,10,-1,7};
  int k = KthSmallestElement(arr, 4);
  cout<<"Kth Element is : "<<k;
}