#include <bits/stdc++.h> 

int mod = 1000000007;

long long solve(int n, int r, vector<vector<long long>> &dp){
	if(r==0) return 1;

	if(r>n) return 0;

	if(dp[n][r] != -1) return dp[n][r];

	return dp[n][r] = (solve(n-1, r, dp)%mod + (r*solve(n-1, r-1, dp))%mod)%mod;
}

long long P(int n, int k) {
	// Write your code here.
	vector<vector<long long>> dp(n+1, vector<long long>(k+1, -1));

	return solve(n, k, dp);
}

