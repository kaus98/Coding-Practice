//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        unordered_map<int, int> res;
        int mac = 0;
        res[0] = -1;
        int sum_till = 0;
        
        for(int i = 0; i < n; i++){
            sum_till += arr[i];
            
            if(res.find(sum_till) != res.end()){
                mac = max(mac, i - res[sum_till] + 1);
            } else{
                res[sum_till] = i;
            }
        }
        
        return mac;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends