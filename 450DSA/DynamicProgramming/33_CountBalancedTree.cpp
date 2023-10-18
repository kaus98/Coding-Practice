#include <bits/stdc++.h> 

long long mod=1000000007;

long long f(int n, vector<long long> &dp){
    if(n==0 || n==1) return 1;

    if(dp[n] != -1) return dp[n];
    return dp[n] = ((f(n-1, dp)%mod)*((2*f(n-2, dp)%mod + f(n-1, dp)%mod)%mod))%mod;
}

long long countBalancedBinaryTree( int n)
{
    //    Write your code here.
    vector<long long> dp(n+1, -1);
    return f(n, dp);
}

