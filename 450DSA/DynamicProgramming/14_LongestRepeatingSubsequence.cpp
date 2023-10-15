class Solution {
	public:
		int LongestRepeatingSubsequence(string s1)
    {
        // your code here
        vector<vector<int>> dp(s1.length()+1, vector<int>(s1.length()+1, -1));
        return f2( s1, s1, dp);
    }
    
    int f2(string s1, string s2, vector<vector<int>> &dp){
        for(int i = 0; i < s1.length()+1; i++) dp[i][0] = 0;
        for(int j = 0; j < s2.length()+1; j++) dp[0][j] = 0;
        
        
        for(int i = 1; i < s1.length()+1; i++){
            for(int j = 1; j < s2.length()+1; j++){
                
                if(s1[i-1] == s2[j-1] && i!= j) dp[i][j] = 1+dp[i-1][j-1];
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