#include <bits/stdc++.h> 

int flipper(int i){
    if(i==1) return 0;
    return 1;
}

int f(vector<vector<int>> &t,vector<vector<int>> &c, int i, int j, vector<vector<int>> &dp){
    if(i == t.size()) {
        //we have reached the end
        return 0;
    }
    // We havent reached the end
    if(dp[i][j] != -1) return dp[i][j];
    //Check if we are first index
    if(i == 0){
        return dp[i][j] = f(t, c, i+1, j, dp) + t[i][j];
    } else{
        //This is not the First Index
        // So we can either move to next or Swift to other lane

        int same = f(t, c, i+1, j, dp) + t[i][j];
        int swift = f(t, c, i+1, flipper(j), dp) + c[i-1][j];

        return dp[i][j] = min(same, swift);
    }
}

int minTime(vector<vector<int>> &t,vector<vector<int>> &c)
{
    // Write your code here.
    vector<vector<int>> dp(t.size()+1, vector<int>(2, -1));

    int r1 = f(t, c, 0, 0, dp);
    int r2 = f(t, c, 0, 1, dp);

    return min(r1, r2);
}

