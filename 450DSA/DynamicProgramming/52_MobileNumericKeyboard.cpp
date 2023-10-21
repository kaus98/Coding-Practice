#include <bits/stdc++.h> 

int MOD = 1000000007;

int solve(map<int, string> &mp, int n, int index,  vector<vector<int>> &dp){
    if(n==1) return 1;

    if(dp[index][n] != -1) return dp[index][n];

    int result = 0;

    int pm = stoi(mp[index]);
    while(pm != 0){
        result = (result+solve(mp, n-1, pm%10  , dp)%MOD)%MOD;
        pm = pm/10;
    }

    return dp[index][n] = result;
}
int generateNumbers(int n)
{
    // Write your code here.
    map<int, string> mp;
    mp[0] = "80";
    mp[1] = "124";
    mp[2] = "2513";
    mp[3] = "326";
    mp[4] = "4517";
    mp[5] = "24568";
    mp[6] = "5639";
    mp[7] = "478";
    mp[8] = "70859";
    mp[9] = "896";

    int result = 0;
    vector<vector<int>> dp(10, vector<int>(n+1, -1));

    for(int i = 0; i < 10; i++){
        result = (result+solve(mp, n, i, dp))%MOD;
    }

    return result;
    
}