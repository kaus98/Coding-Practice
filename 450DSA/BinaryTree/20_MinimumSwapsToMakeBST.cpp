#include <bits/stdc++.h> 

//Find the Inorder Transversal from Array

void trans(vector<int> &arr, int index, vector<int> &result, int n){
	if(index >= n) return;

	trans(arr, 2*index+1, result, n);
	result.push_back(arr[index]);
	trans(arr, 2*index+2, result, n);

	return;
}
int minimumSwaps(vector<int>&arr, int n) {
	// Write your code here.

	vector<pair<int, int>> re;
	vector<int> result;
	int ans = 0;

	trans(arr, 0, result, n);\
	for(int i = 0; i < n; i++) re.push_back({result[i], i});
	sort(re.begin(), re.end());

	for(int i = 0 ; i < n; i++){
		if(i != re[i].second){
			swap(re[i].first , re[re[i].second].first);
			swap(re[i].second, re[re[i].second].second);
			ans++;
			i--;
		}
		
	}

	return ans;

}