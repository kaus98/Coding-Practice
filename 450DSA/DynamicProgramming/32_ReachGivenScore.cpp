#include <bits/stdc++.h> 
int countWays(int n)
{
    // Write your code here
    //Important Question
    // Got Explaination from here -> https://www.youtube.com/watch?v=SzaLN2r6P4E
    vector<int> dp(n+1, 0);
    dp[0] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] += dp[i-2];
    }

    for(int i = 5; i <= n; i++){
        dp[i] += dp[i-5];
    }

    for(int i = 7; i <= n; i++){
        dp[i] += dp[i-7];
    }

    //This we can use if repeated ways are allowed
    // for(int i = 1; i <= n; i++){
    //     //Check the condition for 2
    //     if(i >= 2 && dp[i-2] > 0) dp[i] += dp[i-2];

    //     //Check the condition for 5
    //     if(i >= 5 && dp[i-5] > 0) dp[i] += dp[i-5];

    //     //Check the condition for 7
    //     if(i >= 7 && dp[i-7] > 0) dp[i] += dp[i-7];
    // }
    // cout<<"DP ::"<<endl;
    // for(auto x: dp)cout<<x<<"\t";
    // cout<<endl;
    return dp[n];
}