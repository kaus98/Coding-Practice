#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;


int SearchNearlySortedArray(vector<int> arr, int search, int head, int tail, int k){
    if(head > tail) return -1;
    if(head == tail) {
        if(arr[head] == search) return head;
        else return -1;
    }

    int mid = (head+tail)/2;
    cout<<"Mid set to : "<<mid<<endl; 
    //Search in subArray K in both directions

    for( int i = mid-k; i <= mid+k; i++){
        cout<<"Searching in Index"<<i<<endl;
        if(i < arr.size() && i >= 0 && arr[i] == search) return i;
    }

    if(arr[mid] > search) return SearchNearlySortedArray(arr, search, head, mid-k, k);
    if(arr[mid] < search) return SearchNearlySortedArray(arr, search, mid+k, tail, k);

    return -1;
}


int main(){
    // vector<int> arr = {1,3,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,7,9,12,16,19,25,31,53,62,72,83,92,100};
    vector<int> arr = {10, 3, 40, 20, 50, 80, 70};
    int result;

    result = SearchNearlySortedArray(arr, 90, 0, arr.size(), 3);
    cout<< "Result is : "<<result<<endl;


    return -1;
}