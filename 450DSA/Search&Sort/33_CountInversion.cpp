//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int mergeSort(long long arr[], long long N, long long start, long long mid, long long end){
        vector<long long> temp;
        
        long long left = start;
        long long right = mid+1;
        
        long long count = 0;
        
        while(left <= mid && right <= end){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            } else {
                count += mid-left+1;
                temp.push_back(arr[right]);
                right++;
            }
        }
        
        while(left <= mid)temp.push_back(arr[left++]);
        
        while(right <= end) temp.push_back(arr[right++]);
        
        for(long long i = 0; i < temp.size(); i++){
            arr[start+i] = temp[i];
        }
        
        return count;
    }
    
    
    long long int merge(long long arr[], long long N, long long start, long long end){
        if(start >= end) return 0;
        
        long long count = 0;
        long long mid = (start+end)/2;
        count += merge(arr, N, start, mid);
        count += merge(arr, N, mid+1, end);
        count += mergeSort(arr, N, start, mid, end);
        
        return count;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return merge(arr, N, 0, N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends