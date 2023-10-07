#include <bits/stdc++.h> 
string second_repeat(vector<string> &arr, int n){
    unordered_map<string,int> um;
    string ans = "";
    int maxi = 0;
    for(int i=0; i<n; i++){
        um[arr[i]]++;
    }
    for(auto it : um){
        if(it.second > maxi){
            ans = it.first;
            maxi = it.second;
        }
    }
    // erase the maximum occurance string
    um.erase(ans);
    ans = "";
    maxi = 0;
    for(auto it : um){
        if(it.second > maxi){
            ans = it.first;
            maxi = it.second;
        }
    }
    return ans;
}