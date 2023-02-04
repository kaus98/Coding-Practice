#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

// Given a array find the sum of element between x and y smallest element;

int KthSmallestElement(vector<int>& arr, int k){
    priority_queue<int> maxHeap;

    for(auto x: arr){
        maxHeap.push(x);
        if(maxHeap.size() > k) maxHeap.pop();
    }
    return maxHeap.top();
}

int FirstApproach(vector<int>& arr, int e1, int e2){
    // Assuming e1 is smaller than e2
    e1 = KthSmallestElement(arr, e1);
    e2 = KthSmallestElement(arr, e2);
    cout<< "E1 : "<<e1<<endl;
    cout<< "E2 : "<<e2<<endl;
    int result = 0;
    for(auto i: arr){
        if(i>e1 && i<e2){
            result += i;
        }
    }
    return result;
}

int SecondApproach(vector<int>& arr, int e1, int e2){
    priority_queue<int> maxHeap;

    for(auto x: arr){
        maxHeap.push(x);
        if(maxHeap.size() > e2) maxHeap.pop();
    }
    int result = 0;
    maxHeap.pop();
    while(maxHeap.size()!= e1){
        result+= maxHeap.top(); maxHeap.pop();
    }
    return result;
}


int main(){
    vector<int> arr{1,4,2,3,5,10,-1,7};
    int k = SecondApproach(arr, 1, 5);
    cout<<"Kth Element is : "<<k;
}