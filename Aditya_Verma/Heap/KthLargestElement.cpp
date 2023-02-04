#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

int KthLargestElement(vector<int>& arr, int k){
  priority_queue <int, vector<int>, greater<int>> minHeap;

  for(auto x: arr){
    minHeap.push(x);
    if(minHeap.size() > k) minHeap.pop();
  }
  return minHeap.top();
}

int main(){
  vector<int> arr{1,4,2,3,5,10,-1,7};
  int k = KthLargestElement(arr, 4);
  cout<<"Kth Element is : "<<k;
}