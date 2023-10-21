#include <bits/stdc++.h> 

int solve(vector<int> &prices, int n, int k, int index, int trans, vector<vector<int>> &dp) {
    if(index == n) return 0;
    if(trans == k) return 0;

    if(dp[index][trans] != -1) return dp[index][trans];
    if(trans%2 == 0){
        //Buy now
        return dp[index][trans] = max( solve(prices, n, k, index+1, trans+1, dp) - prices[index] , solve(prices, n, k, index+1, trans, dp));
    } else {
        // Sell now
        return dp[index][trans] = max( solve(prices, n, k, index+1, trans+1, dp) + prices[index] , solve(prices, n, k, index+1, trans, dp));
    }

} 

//To understand the question better please watch 4 videos of Love Babbar
int solveTab(vector<int> &prices, int n, int k){
    vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));

    for(int i = n-1; i >= 0; i-- ){
        for(int j = 0; j < 2*k; j++){
            if(j%2 == 0){
                dp[i][j] = max(dp[i+1][j+1]-prices[i], dp[i+1][j]);
            } else {
                dp[i][j] = max(dp[i+1][j+1]+prices[i], dp[i+1][j]);
            }
        }
    }
    return dp[0][0];
}


int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
    // vector<vector<int>> dp(n+1, vector<int>(2*k, -1));

    // return solve(prices, n, 2*k, 0, 0, dp);

    return solveTab(prices, n, k);
}
