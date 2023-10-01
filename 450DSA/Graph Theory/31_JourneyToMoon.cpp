#include<bits/stdc++.h>

int dfs(vector<bool> &visit,list<int> *mp , int node, int n){
	if (node >= n) return 0;

	if(visit[node]) return 0;

	int sum = 1;
	visit[node] = true;

	for(auto x: mp[node]){
		sum += dfs(visit, mp, x, n);
	}

	return sum;
}


int countWays(int n, vector<vector<int>> &fruitIds) {
	// Write your code here.
	list<int> *l = new list<int>[n];

	for(auto x: fruitIds){
		l[x[0]].push_back(x[1]);
		l[x[1]].push_back(x[0]);
	}

	unordered_map<int, int> mp;
	vector<bool> visit(n, false);

	int fruit = 0;
	int sum;
	for(int i = 0; i < n; i++){
		if(!visit[i]){
			sum = dfs(visit, l, i, n);
			mp[fruit] = sum;
			fruit++;
		}
	}
	sum = n*(n-1)/2;

	for(auto x: mp){
		// cout<<"I "<<x.first<<" \t"<<x.second<<endl;
		sum -= (x.second * (x.second-1))/2;
	}
	return sum;
}

