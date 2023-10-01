int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.

    vector<vector<int>> dp(n+1 , vector<int>(n+1, 1000000000));

    for(auto x: edges) dp[x[0]][x[1]] = x[2];

    for(int i = 1; i <= n; i++){
        dp[i][i] = 0;
    }

    for(int k = 1; k <=n ; k++){
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if(dp[i][k] != 1000000000 && dp[k][j] != 1000000000 && dp[i][j] > (dp[i][k] + dp[k][j])){
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }

    return dp[src][dest];
}