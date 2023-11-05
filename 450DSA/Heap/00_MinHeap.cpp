#include <bits/stdc++.h> 

void heapify(vector<int> &arr, int i){
    int left = 2*i+1;
    int right = 2*i+2;
    int index = i;

    if(left >= arr.size()) return;

    if(left < arr.size() && arr[index] > arr[left]) index = left;

    if(right < arr.size() && arr[index] > arr[right]) index = right;

    if(index!=i){
        swap(arr[index], arr[i]);
        heapify(arr, index);
    }    

}

vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    // cout<<"Original Array : "<<endl;
    // for(auto x: arr) cout<<x<<"\t";
    // cout<<endl;

    int N = (arr.size()/2)-1;

    for(int i = N; i >=0; i--){
        heapify(arr, i);
    }

    // cout<<"Updated Array : "<<endl;
    // for(auto x: arr) cout<<x<<"\t";
    // cout<<endl;

    return arr;

}


