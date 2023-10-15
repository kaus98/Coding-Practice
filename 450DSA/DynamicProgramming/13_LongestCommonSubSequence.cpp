// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, -1));
        return f2(n-1, m-1, s1, s2, dp);
    }
    int f(int n, int m, string s1, string s2 ,vector<vector<int>> &dp ){
        if(n < 0 || m < 0) return 0;
        
        if(dp[n][m] != -1) return dp[n][m];
        
        if(s1[n] == s2[m]){
            return dp[n][m] = 1 + f(n-1, m-1, s1, s2, dp);
        }


        return dp[n][m] = max(f(n-1, m, s1, s2,dp), f(n, m-1, s1, s2,dp));
        
    }
    
    int f2(int n, int m, string s1, string s2, vector<vector<int>> &dp){
        for(int i = 0; i < s1.length()+1; i++) dp[i][0] = 0;
        for(int j = 0; j < s2.length()+1; j++) dp[0][j] = 0;
        
        
        for(int i = 1; i < s1.length()+1; i++){
            for(int j = 1; j < s2.length()+1; j++){
                
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        // cout<<"DP array Looks like :: "<<endl;
        // for(int i = 0; i < s1.length()+1; i++){
        //     for(int j = 0; j < s2.length()+1; j++){
        //         cout<<dp[i][j]    <<"\t";
        //     }
        //     cout<<endl;
        // }
        return dp[s1.length()][s2.length()];
    }
};
