#include <bits/stdc++.h> 
int smallestSubset(vector < int > arr, int n) 
{
	// Write Your Code here        
	int sum = 0;
	sort(arr.begin(), arr.end());

	for(auto x: arr) sum+=x;
	int remain =  0;
	int i;
	for(i = n-1; i>=0; i--){
		remain+=arr[i];
		if(remain > sum/2) break;
	}

	return n-i;

}