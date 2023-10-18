#include <bits/stdc++.h> 
int minimumSum (vector<int>& arr, int n)
{
    // Write your code here.

    // Count the negative and minimum number from Array

    int mi = INT_MAX-1;
    int count = 0;
    
    for(auto x: arr){
        if(x < 0) {count++;}
        mi = min(mi, x);
    }

    if(count < 2) return mi;
    
    int prev_sum = 0;
    int neg = 0;
    for(auto x: arr){
        prev_sum = min(0, prev_sum + x);
        neg = min(prev_sum, neg);
    }
    return neg;

}
