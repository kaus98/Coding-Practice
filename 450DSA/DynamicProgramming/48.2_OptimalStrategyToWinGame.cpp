#include <bits/stdc++.h> 
/*
	Time complexity: O(N ^ 2)
	Space Complexity: O(N ^ 2)
	
	Where N is the number of coins. 
*/

int optimalStrategyOfGame(vector<int> coins, int n)
{
    /* 
        dp[i][j] represents the maximum amount you can win for the subarray coins[i, j]. 
        Given that you start first.
        Initially all the values in dp are initialised to 0.
    */
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 1; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            int a, b, c;
            // Opponent picks jth coin.
            a = (i + 1 < n && j - 1 >= 0) ? dp[i + 1][j - 1] : 0;

            // Opponent picks (i+1)th coin.
            b = (i + 2 < n) ? dp[i + 2][j] : 0;

            // Opponent picks (j-1)th coin.
            c = (j - 2 >= 0) ? dp[i][j - 2] : 0;

            /* 
                You pick either ith or jth coin.
                Choose the combination which gives maximum amount.
            */
            dp[i][j] = max((coins[i] + min(a, b)), (coins[j] + min(a, c)));
        }
    }

    return dp[0][n - 1];
}
