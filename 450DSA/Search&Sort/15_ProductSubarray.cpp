//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here        
        if(n == 0 || n == 1)return nums;
        if(n == 2) {
            swap(nums[0], nums[1]);
            return nums;
        }
        vector<long long int> arr(n,0);
        
        long long int pro = 1;
        
        int zr = 0;
        
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) zr++;
        }
        // cout<<"Zero came as :: "<<zr<<endl;
        for(int i = 0; i < n; i++){
            if(zr > 1) {
                arr[i] = 0;   
            }
            
            else if(nums[i] == 0) {
                arr[i] = 0;
                
            } 
            
            else {
                pro = pro*nums[i];
            }
            
        }
        // cout<<"Product came as :: "<<pro<<endl;
        if (zr > 1) return arr;
        
        for(int i = 0; i < n; i++){
            if(nums[i] != 0) arr[i] = pro/nums[i];
            else nums[i] = 0;
        
        }
        return arr;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends