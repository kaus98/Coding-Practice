#include <bits/stdc++.h> 
int findMaxValue(vector<vector<int>>& mat, int n) {
	// Write your code here.

	vector<vector<int>> dp(n+1, vector<int> (n+1, INT_MIN));
	int pair = INT_MIN;
	for(int i = n-1; i > 0; i--){
		for(int j = n-1; j > 0; j--){
			dp[i][j] = max({dp[i+1][j+1] , dp[i+1][j], dp[i][j+1], mat[i][j]});
			pair = max(pair, dp[i][j] - mat[i-1][j-1]);
		}
	}

	return pair;
	
}