//https://www.geeksforgeeks.org/merge-k-sorted-arrays/
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

vector<int> MergeKSorted(vector<vector <int>> arr){
    priority_queue <pii, vector<pii>, greater<pii>> minHeap;
    for(int i = 0; i<arr.size(); i++){
        cout<<"Inserting Value " << arr[i][0]<<endl;
        minHeap.push(make_pair(arr[i][0], make_pair(i, 0)));
    }
    
    int i,j;
    vector<int> result;
    while(!minHeap.empty()){
        pii ipp = minHeap.top();
        minHeap.pop();
        result.push_back(ipp.first);
        cout<<"Max Heap Top Value is : "<<ipp.first<<endl;
        pi ip = ipp.second;

        if(ip.second + 1 < arr[ip.first].size()) minHeap.push(make_pair(arr[ip.first][ip.second+1] , make_pair(ip.first , ip.second+1)));
        
    }
    return result;
}   

int main(){
    vector<vector<int>> arr;
    arr.push_back({ 23, 34, 90, 2000 });
    arr.push_back({ 2, 6, 12, 34 });
    arr.push_back({ 1, 9, 20, 1000 });

    vector<int> result = MergeKSorted(arr);

    cout<<"Sorted Array is : "<<endl;
    for(auto x: result) cout<<x<<"\t";
    return 0;
}