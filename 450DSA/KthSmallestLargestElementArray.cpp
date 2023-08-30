
#include <bits/stdc++.h>

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	//Solution with Sorting
	sort(arr.begin(), arr.end());
	vector<int> result;
	result.push_back(arr[k-1]);
	result.push_back(arr[n-k]);

	return result;
}

vector<int> kthSmallLargePriority(vector<int> &arr, int n, int k)
{
	
	priority_queue<int> maxHeap;
	priority_queue <int, vector<int>, greater<int>> minHeap;

	for(auto x: arr){
		maxHeap.push(x);
		if(maxHeap.size() > k) maxHeap.pop();
		
		minHeap.push(x);
		if(minHeap.size() > k) minHeap.pop();
	}

	vector<int> result;
	result.push_back(maxHeap.top());
	result.push_back(minHeap.top());

	return result;
}


int kthSmall(vector<int> &arr, int n, int k){
	priority_queue<int> maxHeap;

	for(auto x: arr){
		maxHeap.push(x);
		if(maxHeap.size() > k) maxHeap.pop();
	}
	return maxHeap.top();
}

int kthLarge(vector<int> &arr, int n, int k){
	priority_queue <int, vector<int>, greater<int>> minHeap;

	for(auto x: arr){
		minHeap.push(x);
		if(minHeap.size() > k) minHeap.pop();
	}
	return minHeap.top();
}
