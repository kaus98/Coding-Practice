#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pi> pii;

vector<pi> KthClosestPointOrigin(vector<pi> arr, int K){
    priority_queue<pii> maxHeap;

    for(auto i: arr){
        maxHeap.push(make_pair(pow(i.first, 2) + pow(i.second, 2) , i ));
        if(maxHeap.size() > K) maxHeap.pop();
    }

    vector<pi> result;
    while(!maxHeap.empty()){
        result.push_back(maxHeap.top().second);
        maxHeap.pop();
    }

    return result;
}

int main(){
//   vector<int> arr{1,4,2,3,5,10,-1,7};
  vector<pi> arr;
  arr.push_back(make_pair(1,2));
  arr.push_back(make_pair(2,4));
  arr.push_back(make_pair(-2,2));
  arr.push_back(make_pair(0,2));
  arr.push_back(make_pair(5,2));

  arr = KthClosestPointOrigin(arr, 2);
  cout<<"Top K Element is : "<<endl;
  for(auto i : arr){
    cout<<"X : "<<i.first <<" Y: "<<i.second<<"\n";
  }
}

