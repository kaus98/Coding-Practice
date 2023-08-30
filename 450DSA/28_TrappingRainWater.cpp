//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        left[0] = arr[0];
        right[n-1] = arr[n-1];
        for(int i = 1; i < n; i++){
            
            //Going left to right
            left[i] = max(arr[i], left[i-1]);
            //Going to right to left
            right[n-i-1] = max(arr[n-i-1], right[n-i]);
            
        }
        long long result = 0;
        for(int i = 1; i < n; i++){
            result = result + max(0 , min(left[i], right[i]) - arr[i]);
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends