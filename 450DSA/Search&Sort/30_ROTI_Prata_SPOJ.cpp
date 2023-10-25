#include <bits/stdc++.h> 

bool isPossible(vector<int> &rank, int dishes, int mid){
    int dish = 0;

    for(auto x: rank){
        dish += (-1 + sqrt(1+(8*mid)/x))/2;

        if(dish >= dishes) return  true;
    }
    return false;
}

int minCookTime(vector<int> &rank, int m)
{
    // Write your code here

    long long int start = 0, end = 1000000, ans = -1, mid;

    while(start <= end){
        mid = start + (end-start)/2;

        if(isPossible(rank, m, mid)){
            ans = mid;
            end = mid-1;
        } else start = mid+1;
    }

    return ans;
}
