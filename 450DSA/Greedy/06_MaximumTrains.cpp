#include <bits/stdc++.h> 
int maxStop(vector<vector<int>> &trains, int n, int m)
{
    // Write your code here

    unordered_map<int , vector<pair<int, int>>> mp;

    for(auto x: trains) mp[x[2]].push_back({x[1], x[0]});

    int count = 0;

    for(auto x: mp){
        sort(x.second.begin(), x.second.end());

        count++;
        int accepted = x.second[0].first;
        for(int i = 1; i < x.second.size(); i++){
            if(accepted <= x.second[i].second){
                accepted = x.second[i].first;
                count++;
            }
        }
    }

    return count;
}
