//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void solve(int N, int arr[], int sum, int i, bool &result){
        if(sum == 0){
            result = true;
            return;
        }
        if(sum < 0){
            return;
        }
        if(i==N){
            return;
        }
        if(result){
            return;
        }
        
        //Include
        solve(N, arr, sum-arr[i], i+1, result);
        
        //Exclude
        solve(N, arr, sum, i+1, result);
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i = 0; i < N; i++){
            sum+=arr[i];
        }
        
        if(sum%2 == 1) return 0;
        sum/=2;
        bool result = false;
        
        solve(N, arr, sum, 0, result);
        return result;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends