#include <bits/stdc++.h> 
vector<int> searchInTheArray(vector<int>& arr, vector<int>& queries, int n, int q)
{
	// Write Your code here
	vector<long long int> sum(n+1 , 0);

	long long int temp;
	int max_q;
	max_q = *max_element(queries.begin(), queries.end());
	sum[0] = 0;

	for(int i = 1; i < min(n+1, max_q+1); i++){
		sum[i] = sum[i-1] + arr[i-1];
	}

	vector<int> result;
	for(int i = 0; i < q; i++){
		int j = upper_bound(arr.begin(), arr.end(), queries[i]) - arr.begin(); // Upper and Lower bound return iterator
		result.push_back(sum[j]);
	}
	return result;
}

