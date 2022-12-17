#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;


void TopKFrequentNumber(vector<int> arr, int K){
  unordered_map <int, int> um;
  unordered_map <int, int> ::iterator it;
  priority_queue <pi, vector <pi>, greater<pi>> minHeap;
  
  // Count the Frequency of Each unique Character in Vector
  for(auto i : arr){
    if(um.find(i) != um.end()) 
      um[i]++;
    else 
      um.insert(make_pair(i, 1));
  }

  for(it = um.begin(); it!=um.end(); it++){
    minHeap.push(make_pair(it->second, it->first));
    if(minHeap.top().first < K) 
      minHeap.pop();
  }

  while(!minHeap.empty()){
    cout<<"Value : "<<minHeap.top().second<<" Frequence : "<<minHeap.top().first<<endl;
    minHeap.pop();
  }
}

int main(){
  vector<int> arr{6,5,3,2,9,9,9,9,9,99,9,10,10,10,1,10,12,10,8,14,12,11,6,5,2,5,4};
  TopKFrequentNumber(arr, 2);

}
