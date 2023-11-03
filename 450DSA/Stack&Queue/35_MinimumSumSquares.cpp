#include <bits/stdc++.h> 
int minimumValueFunction(string s, int n, int k) {
	// Write your code here

	map<char, int> mp;
	for(auto x: s) mp[x]++;

	priority_queue<int> pq;
	for(auto x: mp) pq.push(x.second);

	while(k--){
		int tp = pq.top(); pq.pop();
		pq.push(max(0, --tp));
	}

	int result = 0;
	while(!pq.empty()) {
		result += pq.top()*pq.top();
		pq.pop();
	}

	return result;

}