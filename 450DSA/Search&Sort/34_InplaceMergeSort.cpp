#include <bits/stdc++.h> 
bool comp(int a, int b) {return a>b;}


void mSort(vector<int> &arr, int low, int mid, int high){
    int mid2 = mid+1;

    while(low <= mid && mid2 <= high){
        if(arr[low] <= arr[mid2]) low++;
        else {

            // Shift All the elements by one distance to right so we can transfer the element from right to left array
            int ind = mid2;
            int val = arr[mid2];

            while(ind >= low){
                arr[ind] = arr[ind-1];
                ind--;
            }
            
            //Copy the number from right to left
            arr[low] = val;
            low++;
            mid2++;
            mid++;
        }
    }
}
void merge(vector<int> &arr, int low, int high){
    if(low>=high) return;

    int mid = (low+high)/2;
    
    merge(arr, low, mid);
    merge(arr, mid+1, high);

    mSort(arr, low, mid, high);
}
vector<int> mergeSort(vector<int> &arr)
{
    // Write your code here.
    // sort(arr.begin(), arr.end());
    merge(arr, 0, arr.size()-1);
    return arr;
}