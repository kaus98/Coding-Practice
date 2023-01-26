#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

int SearchUnsortedArray(vector<int> arr, int head, int tail){
    // Search the element in array that is in peak element 
    // Peak Element : Element that is greater than both element on both sides
    // Array is unsorted but have to use binary search


    int bin = (head+tail)/2;
    printf("Head : %d Tail : %d Bin : %d Value : %d \n",head, tail, bin, arr[bin]);

    if(bin == 0){
        if (arr[0] >= arr[1]) return 0;
        else return SearchUnsortedArray(arr, 1, tail);
    }
    if(bin == arr.size()-1) {
        if (arr[bin] >= arr[bin-1]) return bin;
        else return SearchUnsortedArray(arr, head, bin);
    }

    if (arr[bin] >= arr[bin-1] && arr[bin] >= arr[bin+1]) return bin;
    else if (arr[bin] < arr[bin-1]) return SearchUnsortedArray(arr, head, bin);
    else return SearchUnsortedArray(arr, bin+1, tail);
}


int main(){
    vector<int> arr = {1,3,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,100,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,7,9,12,16,19,25,31,53,62,72,83,92,100,6,6,6,6,6,6,6,6,6,6,6,6,7,7};
    int result;

    result = SearchUnsortedArray(arr, 0, arr.size());
    cout<< "Index is : "<<result<< " Element is : "<<arr[result] << endl;


    return -1;
} 