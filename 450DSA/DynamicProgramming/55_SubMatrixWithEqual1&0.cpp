#include <bits/stdc++.h> 

int solve(vector<int> &dp, int start, int end){
	int maxDiff = INT_MIN;
	unordered_map<int, int> mp;
	
	//This is very important. Please note here
	mp[0] = -1;
	int sum = 0;

	for(int i = 0; i < dp.size(); i++){
		sum += dp[i];
		if(mp.find(sum) != mp.end()){
			maxDiff = max(maxDiff , i - mp[sum]);
		} else {
			mp[sum] = i;
		}
	}

	if(maxDiff == INT_MIN) return maxDiff;

	return (maxDiff)*(end-start+1);
}


void sumArray(vector<vector<int>> &arr, vector<int> &dp, int i){
    for(int j = 0; j < arr.size(); j++){
        dp[j] = dp[j]+arr[j][i];
    }
    return;
}


int largestSubMatrix(int n, int m, vector<vector<int>> mat) {
    // Write your code here.

    for(int i = 0; i < mat.size(); i++) for(int j = 0; j < mat[0].size(); j++) if(mat[i][j] == 0) mat[i][j] = -1;
	int output = 0;

	for(int left = 0; left < mat[0].size(); left++){
		vector<int> dp(mat.size(), 0);

		for(int right = left; right < mat[0].size(); right++){
			sumArray(mat, dp, right);

			// int temp = solve(dp, left, right);
			// if(temp > output) output = temp;
			
			output = max(solve(dp, left, right), output);
		}
	}

	return output;
}
    