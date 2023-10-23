#include <bits/stdc++.h> 


int countBits(int x){
    int count = 0;
        
    while(x){
        if(x&1) count++;
        x = x>>1;
    }
    return count;
}


void sortSetBitsCount(vector<int>& arr, int n)
{
	// Write your code here
	unordered_map<int, vector<int>> mp;
        
    for(int i = 0; i < n; i++){
        mp[countBits(arr[i])].push_back(arr[i]);
    }
    int j = 0;
    for(int i = 32; i > 0; i--){
        for(auto x: mp[i]){
            arr[j] = x;
            j++;
        }
    }
}