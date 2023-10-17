#include <bits/stdc++.h> 
int maximumDifference(string &str)
{
    // Write your code here.

    vector<int> dp(str.length(), -1);
    int ma = INT_MIN+1;

    if(str[0]=='0') dp[0] = 1;

    for(int i = 0; i < str.length(); i++){
        
        if(str[i] == '1'){
            dp[i] = max(dp[i-1]-1, -1);
        }
        else {
            dp[i] = max(dp[i-1]+1, 1);
        }
        // cout<<"Checking for :: "<<i<<" :: "<<str[i]<<" :: "<<dp[i]<<endl;
        ma = max(ma, dp[i]);

    }
    // cout<<"MA :: "<<ma;
    // cout<<"DP Array :: "<<endl;
    // for(auto x: dp) cout<<x<<"\t";
    return ma;
}
