#include <bits/stdc++.h> 
bool detectNegativeCycle(int n, int m, vector<vector<int>> &edges)
{
	// Write your code here.
    vector<int> dist(n+1, 100000000);

    unordered_map<int, vector<pair<int, int>>>  mp;

    for(auto x: edges) mp[x[0]].push_back({x[1], x[2]});


    dist[1] = 0;

    for(int i = 0; i < n-1; i++){

        for(int x = 1; x <= n; x++){
            for(auto y: mp[x]){
                if((dist[x] + y.second) < dist[y.first]) dist[y.first] = (dist[x] + y.second);
            }
        }
    }

	for(int x = 1; x <= n; x++){
		for(auto y: mp[x]){
			if((dist[x] + y.second) < dist[y.first])  return true;
		}
	}


    return false;
}