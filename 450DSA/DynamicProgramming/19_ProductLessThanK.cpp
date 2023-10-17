#include <bits/stdc++.h> 

int f(vector<int> &a, int n, int p, int i, int pro, vector<vector<int>> &dp){

    if(i == n) return 0;

    if(dp[i][pro] != -1) return dp[i][pro];
    //Include
    int inc = 0;
    if(a[i] * pro <= p){
        inc = f(a, n, p, i+1, a[i]*pro, dp)+1;
    }

    int exc = f(a, n, p, i+1, pro, dp);

    return dp[i][pro] = inc+exc;

}

int countSubsequences(vector < int > & a, int n, int p) {
    // Write your code here.
    vector<vector<int>> dp(n+1, vector<int>(p+1, -1));
    return f(a, n, p, 0, 1, dp);
}

