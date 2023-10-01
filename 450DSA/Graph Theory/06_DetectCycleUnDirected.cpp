
#include<bits/stdc++.h>

bool solve(map<int, vector<int>> &mp, map<int, bool> &visit,  int i){
    visit[i] = true;

    for(auto x: mp[i]){
		if(visit[x]) return true;
        else{
            bool result = solve(mp, visit, x);
			if(result) return result;
        }
    }
    visit[i] = false;
	return false;
}

string cycleDetection(vector<vector<int>>& edges, int v, int e)
{
	// Write your code here
	map<int, vector<int>> mp;
    for(auto x: edges){
        mp[x[0]].push_back(x[1]);
        // mp[x[1]].push_back(x[0]);
    }

	map<int, bool> visit;
	bool result = false;
	for(int i = 0; i < v; i++){
        if(!visit[i]){
            result = solve(mp, visit, i);
			if(result) return "YES";
        }
    }
	return "NO";
}

