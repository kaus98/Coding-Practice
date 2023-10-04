//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& Arr, int N){
      //Code here.
      int buy = 0;
      int sell = 0;
      long long count = 0;
      
      while(buy < N && sell < N){
          while(buy < N && Arr[buy] <= 0) buy++;
          while(sell < N && Arr[sell] >= 0) sell++;
          if(buy==N || sell==N) break;
          
          int dist = abs(buy-sell);
          int wine = min(abs(Arr[buy]), abs(Arr[sell]));
        //   cout<<"Updating :: "<<buy<<"  "<<sell<<"  "<<"  "<<dist<<"  "<<wine<<"  "<<Arr[buy]<<"  "<<Arr[sell]<<endl;
          count += dist*wine;
          Arr[sell]+=wine;
          Arr[buy]-=wine;
      }
      
      return count;
  }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends