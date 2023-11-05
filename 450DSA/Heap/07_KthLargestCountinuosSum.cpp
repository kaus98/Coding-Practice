#include<bits/stdc++.h>
typedef pair<int, pair<int, int>> typ;

int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < arr.size(); i++){

		int sum = 0;

		for(int j = i; j < arr.size(); j++){
			sum += arr[j];

			pq.push(sum);
			if(pq.size() > k) pq.pop();
		}
	}

	return pq.top();
}