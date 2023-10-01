#include <bits/stdc++.h> 

vector<int> kahnsAlgo(vector<vector<int>> &edges, int v){
    // unordered_map<int, vector<int>> l;
    //Simply converting map with list convert from 5% to 98%
    list<int> *l = new list<int>[v];
    vector<int> indegree(v, 0);
    queue<int> q;
    vector<int> result(v,0);
    int steps = 1;

    //Converting Adjacent matrix view
    for(int i = 0; i < edges.size(); i++){
        l[edges[i][0]].push_back(edges[i][1]);
    }

    //Counting the Ingree (Count of Inbound edges)
    for(int i = 0; i < v; i++){
        for(auto x: l[i]){
            indegree[x]++;
        }
    }

    //Pushing the Inbound matrix with 0 count to queue
    for(int i=0; i < v; i++) if(indegree[i] == 0) q.push(i); 
    
    //Pushing remaining to queue one by one
    while(!q.empty()){
        int n = q.size();

        while(n--){
            int node = q.front(); q.pop();
            result[node] = steps;

            for(auto x: l[node]){
                indegree[x]--;
                if(indegree[x] == 0) q.push(x);
            }
        }
        steps++;
    }

    return result;
}


vector<int> minTime(int n, int m, vector<vector<int>> &edges)
{
    // Write your code here
    vector<int> result = kahnsAlgo(edges, n);
    return result;
}
