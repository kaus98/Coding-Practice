int coinGameWinner(int n, int a, int b)
{
	// Write your code here.

	vector<int> dp(n+1, 1);
	dp[0] = 0;
	for(int i = 2; i <= n; i++){
		if(!dp[i-1]) dp[i] = 1;
		else if(i-a >= 0 && !dp[i-a]) dp[i] = 1;
		else if(i-b >= 0 && !dp[i-b]) dp[i] = 1;
		else dp[i] = 0;
	}

	return dp[n];
}

