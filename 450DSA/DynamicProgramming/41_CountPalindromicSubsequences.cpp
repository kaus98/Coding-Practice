int MOD = 1000000007;

int solve(string &s, int i, int j , vector<vector<int>> &dp){
	if(i == j) return 1;
	if(i > j) return 0;

	if(dp[i][j]!= -1) return dp[i][j];

	if(dp[i+1][j] == -1) dp[i+1][j] = solve(s, i+1, j, dp)%MOD;
	if(dp[i][j-1] == -1) dp[i][j-1] = solve(s, i, j-1, dp)%MOD;
	if(dp[i+1][j-1] == -1) dp[i+1][j-1] = solve(s, i+1, j-1, dp)%MOD;

	if(s[i] == s[j]) return dp[i][j] = (1 + dp[i+1][j] + dp[i][j-1])%MOD;
	else return dp[i][j] = (dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1])%MOD;
}

int countPalindromicSubsequences(string &s)
{
	// Write your code here.
	vector<vector<int>> dp(s.length(), vector<int> (s.length(), -1));
	return solve(s, 0, s.length()-1, dp);
}
