#include<bits/stdc++.h>

int mod = 1000000007;

int solve(int n, int r , vector<vector<int>> &dp){
    if(r==0 || n==r) return 1;
        
    if(dp[n][r] != -1) return dp[n][r];
        
    return dp[n][r] = (solve(n-1, r-1, dp) + solve(n-1, r, dp))%mod;
}

int calculateBinomialCoefficient(int n, int r) {
	// Write your code here.
	if(r==0 || n==r) return 1;
    if(n < r) return 0;

	vector<vector<int>> dp(n+1, vector<int>(r+1, -1));
    return solve(n , r, dp);
}
