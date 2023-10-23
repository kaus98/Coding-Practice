#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.

	int a1 = 0; 
	int a2 = 0;
	vector<int> res;

	while(a1 < m && a2 < n)
		if(arr1[a1] < arr2[a2])	res.push_back(arr1[a1++]);
		else res.push_back(arr2[a2++]);

	while(a1 < m) res.push_back(arr1[a1++]);
	while(a2 < n) res.push_back(arr2[a2++]);

	return res;
}