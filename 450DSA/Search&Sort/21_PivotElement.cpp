#include <bits/stdc++.h> 
int findTheLargestElement(vector<int> &arr, int n) {
	// Write your code here.
	if(arr[0] <= arr[arr.size()-1]) {
        return arr[arr.size() - 1];
    }

	int start = 0;
    int end = arr.size()-1;

	while(start <= end){
        int mid = (start+end)/2;
        if(arr[mid] < arr[mid-1]) {
			return arr[mid-1];
        }

        if(arr[mid] >= arr[0]) start = mid+1;
        else end = mid-1;
    }

	return -1;

}