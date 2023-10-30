#include<vector>
#include<bits/stdc++.h>

bool checkMirror(int n, vector<vector<int>> &edgesA, vector<vector<int>> &edgesB)
{
    // Write your code here.
    int e = edgesA.size();
    unordered_map<int, stack<int>> mp;

    for(int i = 0; i < e; i++){
        mp[edgesA[i][0]].push(edgesA[i][1]);
    }

    for(int i = 0; i < e; i++){
        if(mp[edgesB[i][0]].top() != edgesB[i][1]) return false;
        mp[edgesB[i][0]].pop();
    }

    return true;

}