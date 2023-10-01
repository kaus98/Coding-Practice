#include<bits/stdc++.h>

void solve(map<int, vector<int>> &mp, map<int, bool> &visit, vector<int> &abc, int i){
    visit[i] = true;
    abc.push_back(i);

    for(auto x: mp[i]){
        if(!visit[x]){
            solve(mp, visit, abc, x);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    // for(int i = 0; i < edges.size(); i++){
    //     for(int j = 0; j < edges[i].size(); j++){
    //         cout<<edges[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl<<endl;

    map<int, vector<int>> mp;
    for(auto x: edges){
        mp[x[0]].push_back(x[1]);
        mp[x[1]].push_back(x[0]);
    }

    map<int, bool> visit;
    vector<vector<int>> result;

    for(int i = 0; i < V; i++){
        if(!visit[i]){
            vector<int> abc;
            solve(mp, visit, abc, i);
            result.push_back(abc);
        }
        
    }
    return result;
}