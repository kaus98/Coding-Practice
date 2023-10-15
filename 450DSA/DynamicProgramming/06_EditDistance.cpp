#include<bits/stdc++.h>

int min(int x, int y, int z) { return min(min(x, y), z); }

int f(string str1, string str2, int l1, int l2, vector<vector<int>> &dp){

    if(l1 == 0){
        return l2;
    }
    if(l2 == 0){
        return l1;
    }

    if(dp[l1][l2] != -1) return dp[l1][l2];
    int sol;
    if(str1[l1-1] == str2[l2-1]){
        sol = f(str1, str2, l1-1, l2-1, dp);
    }

    else {
            sol = 1 + min (
            f(str1, str2, l1-1, l2, dp),
            f(str1, str2, l1, l2-1, dp),
            f(str1, str2, l1-1, l2-1, dp)
        );
    }
    
    dp[l1][l2] = sol;
    return sol;
}

int editDistance(string str1, string str2)
{
    //write you code here

    vector<vector<int>> dp(str1.length()+1, vector<int>(str2.length()+1, -1));
    return f(str1, str2, str1.length(), str2.length(), dp);
    
}
