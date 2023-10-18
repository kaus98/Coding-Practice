#include <bits/stdc++.h> 

int f(string s, string sr){

    vector<vector<int>> dp(s.length()+1, vector<int>(s.length()+1, 0));
    // cout<<"DP Array is :: "<<endl;

    for(int i = 1; i <= s.length(); i++){
        for(int j = 1; j <= s.length(); j++){

            if(s[i-1] == sr[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            // cout<<dp[i][j]<<"\t";
        }
        // cout<<endl;
    }

    return dp[s.length()][s.length()];
}

int longestPalindromeSubsequence(string s)
{
    // Write your code here.
    // Idea is to reverse the string and find longest common Subsequences
    
    string sr;
    for(int i = s.length()-1; i >=0; i--){
        sr.push_back(s[i]);
    }

    // cout<<"String is :: "<<s<<" :: "<<sr<<endl;
    int rec = f(s, sr);
    return rec;
}

