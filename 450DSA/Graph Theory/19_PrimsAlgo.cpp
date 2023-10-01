#include <bits/stdc++.h> 


vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    unordered_map<int, vector<pair<int, int>>> mp;

    for(int i = 0; i < g.size(); i++){
        if(g[i].first.first != g[i].first.second) {
            mp[g[i].first.first].push_back({g[i].first.second, g[i].second});
            mp[g[i].first.second].push_back({g[i].first.first, g[i].second});
        } 
    }

    // for(int i = 1; i <= n; i++){
    //     cout<<" I "<<i<<endl;
    //     for(auto x: mp[i]){
    //         cout<<x.first << " :: "<<x.second<<"\t";
    //     }
    //     cout<<endl;
    // }
    vector<bool> visit(n+1, false);
    vector<int> distance(n+1, INT_MAX-1);
    vector<int> parent(n+1, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0,1});

    while(!pq.empty()){
        
        int node = pq.top().second;
        int dist = pq.top().first;
        // cout<<"Checking the node :: "<<node<<" \t "<<dist<<endl;
        pq.pop();

        if(!visit[node]){
            visit[node] = true;
            // cout<<"Updating the Node :: "<<node<<endl;
            for(auto x: mp[node]){
                pq.push({x.second, x.first});
                if (distance[x.first] > x.second && !visit[x.first]) {
                    distance[x.first] = x.second;
                    parent[x.first] = node;
                }
            }
            
        }
    }
    g.clear();

    // cout<<"Distances :: "<<endl;
    for(int i = 2; i <= n; i++){
        // cout<<distance[i]<<"\t";
        g.push_back({{parent[i], i}, distance[i]});
    }
    // cout<<endl;
    // cout<<"Node :: Distance :: "<<endl;
    // for(int i = 2; i <= n; i++){
    //     cout<<parent[i]<<"  "<<distance[i]<<"\t";
    // }
    // cout<<endl;
    return g;
}
