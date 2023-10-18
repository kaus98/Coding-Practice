#include<bits/stdc++.h>


int f(int n, int w, vector<int> &profit, vector<int> &weight, int i, vector<vector<int>> &dp){

    if(i == n && w!=0) return INT_MIN;// If we dont have any weight but knapsack is still not filled then it will fill at infinite

    if(w == 0) return 0; // If Knapsack is filled, then we can return 0 since it will take no more profit

    if(dp[i][w] != -1) return dp[i][w];
    //If Including the value to array
    int inc = INT_MIN;
    if(weight[i] <= w){
        inc = f(n,w-weight[i], profit, weight, i, dp);
        if(inc  != INT_MIN) inc += profit[i];
        // else inc = 0;
        
    }

    int exc = f(n, w, profit, weight, i+1, dp);
    
    return dp[i][w] = max(inc, exc);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    // map<pair<int, int>, int> mp;
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    return max(0, f(n,w,profit, weight, 0, dp));
}

