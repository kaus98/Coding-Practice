#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

int SearchFirstBinarySearch(vector<int> arr, int search, int head, int tail){
    if(head == tail) return head;
    int temp = (head + tail)/2;
    if(arr[temp] == search) return SearchFirstBinarySearch(arr, search, head, temp);
    if(arr[temp]<search) return SearchFirstBinarySearch(arr, search, temp, tail);
    return -1;
}

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
    cout<<"Head : "<<head <<" Tail :"<<tail << endl; 
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

int AutoSearched(vector<int> arr, int search){
    //Automatically find which Binary Search to use
    if (arr[0] < arr[1]){
        return BinarySearch(arr, search, 0, arr.size());
    }
    else{
        return ReverseBinarySearch(arr, search, 0, arr.size());
    }
    return -1;
}

vector<int> FirstLastOccurance(vector<int> arr, int search){
    // Two way of Finding First and last occurance is 
    // Find any and scroll linearly to either directions to find occrances
    // Or we can continue to move binarly

    // Find the first occurance and considering pipeline is ascending in order.
    int head = 0;
    int tail = arr.size();

    int pivot = BinarySearch(arr, search, head, tail); // This Pivot can be first, last or any in middle

    int first = 0;
    int tail = arr.size();

    first = SearchFirstBinarySearch(arr,search, head, )
    
    // At first i was thinking for this approach but i am going to try with different
}

int main(){
    vector<int> arr = {1,2,6,7,9,12,16,19,25,31,53,62,72,83,92,100};
    int result;

    result = BinarySearch(arr, 9, 0, arr.size());
    cout<< "Binary Search Index is : "<<result+1 << " Value : "<<arr[result]<<endl;

    reverse(arr.begin(),arr.end());
    result = ReverseBinarySearch(arr, 9, 0, arr.size());

    cout<< "Reverse Binary Search Index is : "<<result+1 << " Value : "<<arr[result]<<endl;
    return -1;
}