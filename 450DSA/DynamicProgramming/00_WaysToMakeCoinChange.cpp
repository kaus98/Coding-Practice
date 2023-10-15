#include <bits/stdc++.h> 

long f(int *arr, int n, int value, vector<vector<long>> &dp){
    // If value cant be formed with first value of arr anymore
    if(n == 0){

        if(value%arr[0] == 0) {dp[arr[0]][value] = 1; return 1;}
        else {dp[arr[0]][value] = 0; return 0;}
    }
    
    if(dp[n][value] != -1) return dp[n][value];

    long ways = 0;
    //Not Included
    ways += f(arr, n-1, value, dp);

    if(arr[n] <= value) {
        ways += f(arr, n, value-arr[n], dp);
    }
    
    dp[n][value] = ways;
    return ways;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<long>> dp(n+1, vector<long>(value+1, -1));

    return f(denominations, n-1, value, dp);
}

