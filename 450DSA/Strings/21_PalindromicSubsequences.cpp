class Solution{
    public:
    long long MOD = 1000000007;
    
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       //Your code here
       vector<vector<long long int>> dp(str.length()+1, vector<long long int>(str.length()+1, -1));
       
       return f(str, 0, str.length()-1, dp);
       
    }
    
    // First method should be of Recursion
    
    long long f(string &str, int i, int j, vector<vector<long long int>> &dp){
        
        
        if(i > j) return 0;
        
        if(i==j) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(str[i] == str[j]) return dp[i][j] = (1+f(str, i+1,j,dp)+f(str, i, j-1, dp))%MOD;
        else return dp[i][j] = (f(str, i+1, j, dp)+ f(str, i, j-1, dp) - f(str, i+1, j-1, dp)+ MOD)%MOD;
    }
    // return 
     
};