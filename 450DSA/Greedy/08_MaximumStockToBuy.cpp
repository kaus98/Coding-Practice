#include <bits/stdc++.h> 
int max_shares(int k, int n, vector<int> &shares){
    // Write your code here.

    vector<pair<int, int>> pr;

    for(int i = 0; i < shares.size(); i++){
        pr.push_back({shares[i], i+1});
    }

    sort(pr.begin(), pr.end());
    int count = 0;

    for(auto x: pr){
        int cost = x.first;
        int day = x.second;

        int buy = min(day, k/cost);

        count+=buy;
        k-=buy;
        // while(k >= cost && day--){
        //     // cout<<"Buying :: "<<cost<<" :: "<<k<<endl;
        //     count++;
        //     k-=cost;
        // }
    }

    return count;
}