#include <bits/stdc++.h> 

typedef pair<int, int> pi;

vector<int> sortedMatrix(vector<vector<int>> &mat, int n) {
    // Write your code here.

    priority_queue<pi, vector<pi>, greater<pi> > pq; 
    vector<int> visit(n, 1);

    for(int i = 0; i < n; i++){
        pq.push({mat[i][0], i});
    }
    vector<int> result;

    while(!pq.empty()){
        auto tp = pq.top();
        pq.pop();
        result.push_back(tp.first);
        
        if(visit[tp.second] < n) {
            pq.push({mat[tp.second][visit[tp.second]], tp.second});
            visit[tp.second]++;
        }
    }

    return result;
}