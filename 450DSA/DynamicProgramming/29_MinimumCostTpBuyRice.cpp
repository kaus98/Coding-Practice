#include <bits/stdc++.h> 

int f(int n, int w, vector<int> cost, int i, map<pair<int, int>, int> &mp){
    if(i==n && w!= 0) return INT_MAX;
    if(w==0) return 0;

    if(mp.find({i, w}) != mp.end()){
        return mp[{i,w}];
    }

    int inc = INT_MAX;   
    if(i <= w && cost[i] != -1){
        inc =  f(n, w-i-1, cost, i, mp);
        if(inc != INT_MAX) inc += cost[i];
    }

    int exc = f(n, w, cost, i+1, mp);
    return mp[{i,w}] = min(inc, exc);
}

int minCost(int n, int w, vector<int> cost) {
    // Write your code here.
    map<pair<int, int>, int> mp;

    int res = f(n, w, cost, 0, mp);
    if(res == INT_MAX) return -1;
    return res;
}


