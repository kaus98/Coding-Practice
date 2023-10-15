#include <bits/stdc++.h> 

int f(vector<int> &arr, int N, int i, int j, vector<vector<int>> &dp){
    // Break Condition will go here
    if(i>=j) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int mn = INT_MAX-1;

    for(int k = i; k <= j-1; k++){
        int temp = f(arr, N, i, k, dp) + f(arr, N, k+1, j, dp) + arr[i-1]*arr[k]*arr[j];
        mn = min(mn, temp);
    }

    return dp[i][j] = mn;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
    return f(arr, N, 1, N-1, dp);
}
