#include <bits/stdc++.h> 
int countSubarrays(int n, vector<int> &arr){
    // Write your code here.

    unordered_map<int, int> mp;

    int count = 0, sum = 0;
    mp[0] = 1;
    for(int i = 0; i < n; i++){
        sum+= arr[i];

        if(mp.find(sum) == mp.end()) mp[sum]++;
        else count += mp[sum]++;
        
    }

    return count;
}