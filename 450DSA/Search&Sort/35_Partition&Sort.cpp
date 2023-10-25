#include <bits/stdc++.h> 
vector<int> sortArray(vector<int> &arr)
{
	// Write your code here
	sort(arr.begin(), arr.end());
	return arr;
	
	map<int, int> mp;
	int i = 0;

	for(auto x: arr) mp[x]++;
	for(auto x: mp){
		while(x.second != 0){
			arr[i++] = x.first;
			x.second--;
		}
	}
	return arr;
}