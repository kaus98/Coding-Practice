#include <bits/stdc++.h> 
vector<int> maxOfSubarray(vector<int> nums, int n, int k) 
{
	// Write your code here
	if(k == 1) return nums;
	
	priority_queue<pair<int, int>> pq;
	vector<int> result;

	for(int i = 0; i < k; i++){
		pq.push({nums[i], i});
	}

	result.push_back(pq.top().first);

	for(int i = k; i < n; i++){
		while(pq.top().second <= i-k) pq.pop();
		pq.push({nums[i], i});
		result.push_back(pq.top().first);
	}

	return result;

}
