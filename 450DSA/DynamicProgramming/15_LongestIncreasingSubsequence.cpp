#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int f(int arr[], int n, int i, int m1, vector<vector<int>> &dp){

        if(i == n) return 0;
        if(dp[i][m1+1] != -1) return dp[i][m1+1];
        
        int  inc = INT_MIN+1;
        if(m1 == -1 || arr[i] > arr[m1]){
            
            inc = f(arr, n, i+1, i ,dp)+1;
        }
    
        int exc = f(arr, n, i+1, m1, dp);
    
        return dp[i][m1+1] = max(inc, exc);
    }
    
    
    int dpBinarySearch(int arr[], int n){
        vector<int> result;

        if(n == 0) return 0;
        result.push_back(arr[0]);

        for(int i = 1; i < n; i++){
            if(arr[i] > result.back()) result.push_back(arr[i]);
            else {
                int index = lower_bound(result.begin(), result.end(), arr[i]) - result.begin();
                result[index] = arr[i];
            }
        }

        return result.size();
    }
    
    int longestSubsequence(int n, int a[])
    {
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return f(a, n, 0, -1, dp);
        return dpBinarySearch(a, n);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends