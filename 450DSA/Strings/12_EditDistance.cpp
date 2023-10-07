class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        int m = s.size()+1;
        int n = t.size()+1;
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            dp[i][0] = i;
        }
        
        for(int i = 0; i < n; i++){
            dp[0][i] = i;
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 + min({dp[i-1][j] , dp[i][j-1], dp[i-1][j-1]});
            }
        }
        
        return dp[m-1][n-1];
        
    }
};