#include <bits/stdc++.h> 

int mod = 1000000007;

long long f(int n, int k, vector<long long> &dp){
    if(n==1) return k;

    if(n==2) return k*k;
    if(dp[n] != -1) return dp[n];

    
    // return dp[n] = ((f(n-1, k, dp)%mod + f(n-2, k, dp)%mod) * (k-1))%mod;

    return dp[n] = ((f(n-1, k, dp)*(k-1))%mod + (f(n-2, k, dp)*(k-1))%mod)%mod;
}


long long numberOfWays(int n, int k) {
    // Write your code here.
    vector<long long> dp(n+1, -1);
    return f(n, k, dp);
}

