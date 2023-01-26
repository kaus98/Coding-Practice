#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

int BinarySearch(vector<int> arr, int search, int head, int tail){
    if(head > tail) return -1;
    if(head == tail) {
        if(arr[head] == search) return head;
        else return -1;
        }

        
    int bin  = (head + tail)/2;

    if(arr[bin] > search) return BinarySearch(arr, search, head, bin);
    if(arr[bin] == search) return bin;
    if(arr[bin] < search) return BinarySearch(arr, search, bin+1, tail);

    return -1;
}

int ReverseBinarySearch(vector<int> arr, int search, int head, int tail){
    if(head > tail) return -1;
    if(head == tail) {
        if(arr[head] == search) return head;
        else return -1;
        }

        
    int bin  = (head + tail)/2;

    if(arr[bin] < search) return ReverseBinarySearch(arr, search, head, bin);
    if(arr[bin] == search) return bin;
    if(arr[bin] > search) return ReverseBinarySearch(arr, search, bin+1, tail);

    return -1;
}

int PeakBitonicElement(vector<int> arr, int head, int tail){
    cout<<"Searching in Head : "<<head << " and Tail : "<<tail<<endl;

    int i = (head+tail)/2;

    if(i == 0 || i == arr.size()-1) return i;

    if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) return i;
    if(arr[i] > arr[i-1]) return PeakBitonicElement(arr, i+1, tail);
    else return PeakBitonicElement(arr, head, i);

    return -1;
}


int SearchRotatedArray(vector<int> arr, int search){
    cout<<"Searching the Int : "<<search<<endl;

    // Get the Minimum element Position from Array
    int result = PeakBitonicElement(arr, 0, arr.size());

    if (result==0) return BinarySearch(arr, search, 0, arr.size());
    else return max(BinarySearch(arr, search, 0, arr.size()) , ReverseBinarySearch(arr, search, 0, arr.size()));

    return -1;
}

int main(){
    vector<int> arr = {1,2,3,4,12,13,14,15,16,10,9,8,5,4,2,1};
    int result = PeakBitonicElement(arr, 0, arr.size());

    int sr = max(BinarySearch(arr, 5, 0, result), ReverseBinarySearch(arr, 5, result, arr.size()));


    cout<<"Result is "<<result<<" Value is : "<< arr[result]<<endl << "Found Element at : "<<sr<<" Value "<< arr[sr];
    return -1;
}
