#include <bits/stdc++.h> 
int reverseEdges(int n, int start, int end, vector<vector<int>> &edgeList)
{
	// Write your code here
	// cout<<"Start and End :: "<<start<<"\t"<<end<<endl;
	unordered_map<int , vector<pair<int, int>>> mp;
	for(auto x: edgeList){
		mp[x[0]].push_back({x[1], 0});
		mp[x[1]].push_back({x[0], 1});
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	vector<int> visit(n, INT_MAX);
	visit[start] = 0;

	pq.push({0, start});

	int dist, node;
	int nextnode, nextdist;

	while(!pq.empty()){
		dist = pq.top().first;
		node = pq.top().second;
		pq.pop();

		for(auto x: mp[node]){
			nextnode = x.first;
			nextdist = x.second;

			if(nextdist+dist < visit[nextnode]){
				// cout<<"Updating the Visit :: "<<nextnode<<" "<<nextdist+dist<<endl;
				visit[nextnode] = nextdist+dist;
				pq.push({visit[nextnode], nextnode});
			}
		}
	}

	return visit[end];
}