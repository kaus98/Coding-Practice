#include <bits/stdc++.h> 

void solve(map<int, vector<int>> &mp, vector<bool> &visit, int i){
	visit[i] = true;
	if(mp.find(i) == mp.end()) return;

	for(auto x: mp[i]){
		if(!visit[x]){
			solve(mp, visit, x);
		}
	}
}



int minConnectionChanges(int n, vector<vector<int>> &wires)
{
	// Write your code here
	map<int, vector<int>> mp;
    for(auto x: wires){
        mp[x[0]].push_back(x[1]);
        mp[x[1]].push_back(x[0]);
    }

	vector<bool> visit(n+1, false);

	//Calculate the number of components;
	int comp = 0;

	for(int i = 1; i <= n; i++){
		if(!visit[i]) {
			solve(mp, visit, i);
			comp++;
		}
	}
	
	// cout<<"Components are :: "<<comp<< " Wires size :: "<<wires.size() << " n :: "<<n <<endl;
	// if((wires.size()-n) < -1) return -1;

	if(wires.size() < n-1) return -1;
	return comp-1;

	// return 0;
}
