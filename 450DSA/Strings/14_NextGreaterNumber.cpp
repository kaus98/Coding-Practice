//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int ancor = -1;
        for(int i = N-1; i > 0; i--){
            if(arr[i-1] < arr[i]){
                ancor = i-1;
                break;
            }
        }
        
        if (ancor == -1){
            reverse(arr.begin(), arr.end());
            return arr;
            
        }
        //Search for larger element than ancor
        for(int i = N-1; i > ancor; i--){
            if(arr[ancor] < arr[i]){
                swap(arr[ancor], arr[i]);
                break;
            }
        }
        
        //Reverse the remaining elments
        
        for(int i = ancor+1, j = N-1; i <j; i++,j--){
            swap(arr[i], arr[j]);
        }
        
        return arr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends