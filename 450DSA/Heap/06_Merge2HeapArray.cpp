#include <bits/stdc++.h> 

void MaxHeapify(vector<int> &arr, int i, int n){
    int left = 2*i+1;
    int right = 2*i+2;
    int index = i;

    if(left >= n) return;

    if(left < n && arr[index] < arr[left]) index = left;

    if(right < n && arr[index] < arr[right]) index = right;

    if(index!=i){
        swap(arr[index], arr[i]);
        MaxHeapify(arr, index, n);
    }    

}

vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    // Write your code here

    for(int i = 0; i < m; i++){
        arr1.push_back(arr2[i]);

    }

    for(int i = arr1.size()/2; i >= 0; i--){
        MaxHeapify(arr1, i, arr1.size());
    }

    // cout<<"Response is :: "<<endl;
    // for(auto x: arr1)cout<<x<<"\t";
    return arr1;
}