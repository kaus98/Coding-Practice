// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        //Divide the arary to 2
        
        int sum = 0;
        for(int i = 0; i < N; i++){
            sum+= arr[i];
        }
        
        if(sum % 2 != 0) return 0;
        
        vector<vector<int>> dp(N+1, vector<int>((sum/2)+1, -1));
        
        return f(N, arr, sum/2, dp);
    }
    
    int f(int N, int arr[], int sum, vector<vector<int>> &dp){
        if(sum == 0) return 1;
        if(N == 0 && sum != 0) return 0;
        
        int include = 0;
        int exclude = 0;
        
        if(dp[N][sum] != -1) return dp[N][sum];
        if(sum >= arr[N-1]) {
            include = f(N-1, arr, sum-arr[N-1], dp);
        }
        exclude = f(N-1 , arr, sum, dp);
        
        return dp[N][sum] = (include||exclude);
    }
};