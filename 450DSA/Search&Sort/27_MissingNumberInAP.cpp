#include <bits/stdc++.h> 
int missingNumber(vector<int> &arr, int n) 
{
    // Write your code here.
    // Case when there are only 2 elements. then missing must be middle one

    if(n == 2) return (arr[1] - arr[0]) / 2;

    int a = arr[0];
    int b = min(arr[1]-arr[0], arr[n-1]-arr[n-2]);


    int start = 1;
    int end = n-1;

    while(start <= end){
        int mid = start + (end-start)/2;

        if(arr[mid] - arr[mid-1] != b) return arr[mid-1]+b;

        if(arr[mid] == a+mid*b) start = mid+1;
        else end = mid-1;
    }

    return -1;
}
