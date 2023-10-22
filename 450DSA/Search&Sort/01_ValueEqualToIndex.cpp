#include <bits/stdc++.h> 
vector<int> valueEqualToIndices(vector<int>& numArray, int n) {
	// Write your code here.

	vector<int> result;

	for(int i = 0; i < n; i++){
		if(numArray[i] == i) result.push_back(i);
	}
	if(result.size() == 0) result.push_back(-1); 
	return result;
}