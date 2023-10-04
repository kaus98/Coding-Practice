#include<bits/stdc++.h>

bool sm( pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    vector<pair<int,int>> dp;

    for(int i = 0; i < start.size(); i++){
        dp.push_back({start[i], finish[i]});
    }

    sort(dp.begin(), dp.end(), sm);

    int count = 1;
    int end = dp[0].second;
    for(int i = 1; i < dp.size(); i++){
        if(dp[i].first >= end ){
            end = dp[i].second;
            count++;
        }
    }

    return count;

}