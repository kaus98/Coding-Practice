//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long solve(int arr[], int n, int i, int j, vector<vector<int>> &dp){
        if(i>j) return 0;
        if(i==j) return arr[i];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        long long l = arr[i] + min(solve(arr, n, i+1, j-1, dp) , solve(arr, n, i+2, j, dp));
        long long r = arr[j] + min(solve(arr, n, i+1, j-1, dp) , solve(arr, n, i, j-2, dp));
        
        return dp[i][j] = max(l,r);
    }
    long long maximumAmount(int arr[], int n){
        // Your code here
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(arr, n, 0, n-1, dp);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends