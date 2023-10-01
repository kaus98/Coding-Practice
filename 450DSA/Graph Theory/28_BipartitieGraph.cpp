#include <bits/stdc++.h>

void bfs(list<int> *l, bool &result, int color, vector<int> &visit, int node){
	//if node is already painted and if with same color

	// if(visit[node] != -1 && visit[node] == color) result = false;

	if(!result) return;

	visit[node] = color;
	
	
	for(auto x: l[node]){
		if(visit[x] == -1) bfs(l, result, !color, visit, x);
		else if(visit[x] == color){
			result = false;
			return;
		}
	}
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
	int n = edges.size();
	list<int> *l = new list<int>[n];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < edges[i].size(); j++){
			if(edges[i][j] == 1){
				l[i].push_back(j);
				l[j].push_back(i);
			}
		}
	}

	vector<int> visit(n, -1);
	bool  result =  true;

	for(int i = 0; i < n; i++){
		if(visit[i] == -1) {
			bfs(l, result, 1, visit, i);
			if(!result) return result;
		}
	}
	

	return result;

}

