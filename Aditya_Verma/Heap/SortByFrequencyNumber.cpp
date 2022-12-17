#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;


vector<int> SortFrequentNumber(vector<int> arr){
  unordered_map <int, int> um;
  unordered_map <int, int> ::iterator it;
  // priority_queue <pi, vector <pi>, greater<pi>> minHeap;
  priority_queue <pi> maxHeap;
  
  // Sort by the Frequency of Number 
  for(auto i : arr){
    if(um.find(i) != um.end()) 
      um[i]++;
    else 
      um.insert(make_pair(i, 1));
  }

  for(it = um.begin(); it!=um.end(); it++){
    maxHeap.push(make_pair(it->second, it->first));
  }

  int i = 0;
  while(!maxHeap.empty()){
    for(int j = 0; j < maxHeap.top().first; j++){
      arr[i] = maxHeap.top().second;
      i++;
    }
    maxHeap.pop();
  }

  return arr;
}

int main(){
  vector<int> arr{6,5,3,2,9,9,9,9,9,99,9,10,10,10,1,10,12,10,8,14,12,11,6,5,2,5,4};

  vector<int> k = SortFrequentNumber(arr);
  cout<<"Sorted Array is "<<endl;
  for(auto x: k) cout<<x<<"\t";
}
