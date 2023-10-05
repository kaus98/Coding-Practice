#include <bits/stdc++.h>

vector<int> findCommonElements(vector<vector<int>> &mat)
{
    // Write your code here
    int n = mat.size();
    int m = mat[0].size();

    unordered_map<int, int> mp;
    

    for(int i = 0; i < n; i++){
        set<int> st;

        for(int j = 0; j < m; j++){
            st.insert(mat[i][j]);
        }

        for(auto x: st){
            mp[x]++;
        }
    }

    vector<int> result;

    for(auto x: mp){
        if(x.second == n) result.push_back(x.first);
    }

    return result;

}
