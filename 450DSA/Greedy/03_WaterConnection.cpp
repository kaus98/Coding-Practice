#include <bits/stdc++.h> 
vector<vector<int>> components(int n, int m, vector<vector<int>> &edges)
{
	// Write your code here
	unordered_map<int, pair<int, int>> mp;
	vector<bool> first(n+1, true);
	vector<vector<int>> result;
	for(auto x: edges){
		mp[x[0]] = {x[1], x[2]};
		first[x[1]] = false;
	}

	int prev, last;
	int root, weight;
	int nxtNode,  nxtWeight;
	pair<int, int> temp;
	for(int i = 1; i < n+1; i++){
		if(first[i]){
			weight = INT_MAX;
			root = prev = i;
			
			while(mp.find(prev) != mp.end()){
				temp = mp[prev];
				weight = min(temp.second, weight);
				prev = temp.first;
			}
			result.push_back({root, prev, weight});

		}
	}
	
	return result;
}