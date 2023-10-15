#include<bits/stdc++.h>

int f(int n, int x, int y, int z, vector<int> &dp){
	if(n==0) return 0;
	if(n < 0) return INT_MIN;

	if(dp[n] != -1) return dp[n];

	return dp[n] = max({f(n-x, x, y, z, dp), f(n-y, x, y, z, dp) , f(n-z, x, y, z, dp)}) + 1;
}

int cutSegments(int n, int x, int y, int z) {
	// Write your code here.

	vector<int> dp(n+1,-1);
	int result = f(n,x,y,z, dp);
	return (result < 0 )?0:result;
}