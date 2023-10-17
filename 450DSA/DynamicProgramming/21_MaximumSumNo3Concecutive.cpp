#include <bits/stdc++.h> 
int maxSum(vector<int> &a, int n) 
{
	// Write your code here.

	vector<int> dp(a.size(), 0);


	dp[0] = a[0];
	dp[1] = a[0]+a[1];

	dp[2] = max({a[2] + a[0] , a[1]+a[2] , dp[1]});

	for(int i = 3; i < n; i++){
		dp[i] = max({
			a[i] + a[i-1] + dp[i-3], // Current and last is taken
			dp[i-1], // Current is not taken
			a[i] + dp[i-2] // Current and 2nd last is taken
		});
	}

	return dp[n-1];
}
