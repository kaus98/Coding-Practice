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

int TimesArrayRotated(vector<int> arr, int head, int tail){
    cout<<"Searching in Head : "<<head << " and Tail : "<<tail<<endl;
    int left, right;
    int mid = (head+tail)/2;
    if (head == tail) return head;
    if (mid == 0) left = arr.size() - 1;
    else left = mid - 1;

    if (mid == arr.size()-1) right = 0;
    else right = mid + 1;

    if(arr[left] > arr[mid] && arr[right] > arr[mid]) return mid;
    
    if(arr[head] > arr[mid]) return TimesArrayRotated(arr, head, left);
    if(arr[tail] < arr[mid]) return TimesArrayRotated(arr, mid, tail);

    return -1;
}


int SearchRotatedArray(vector<int> arr, int search){
    cout<<"Searching the Int : "<<search<<endl;

    // Get the Minimum element Position from Array
    int result = TimesArrayRotated(arr, 0, arr.size());

    if (result==0) return BinarySearch(arr, search, 0, arr.size());
    else return max(BinarySearch(arr, search, 0, arr.size()) , BinarySearch(arr, search, 0, arr.size()));

    return -1;
}

int main(){
    vector<int> arr = {12,14,16,1,2,3,4,5,6,7,8,9,10};

    int result = SearchRotatedArray(arr, 5);
    cout<<"Result is "<<result;
    return 0;
}