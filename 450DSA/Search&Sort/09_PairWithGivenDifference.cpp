#include<bits/stdc++.h>

string isPairDifferenceK(vector<int>arr, int n, int k) {
    // Write your code here.

    sort(arr.begin(), arr.end());

    int i = 0;
    int j = 0;

    while(j<n){
        int temp = arr[j] - arr[i];
        if(temp == k) return "Yes";
        
        if(temp < k) j++;
        else i++;
    }

    return "No";
}
