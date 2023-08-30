//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

    // Using extra O(N) memory to sort the order but the order is maintained
    void rearrange1(int arr[], int n) {
        
        vector<int> positive;
        vector<int> negative;
        
        for(int i = 0; i < n; i++){
            if (arr[i] >=0) positive.push_back(arr[i]);
            else negative.push_back(arr[i]);
        }
        
        
        int i = 0; int j = 0;
        
        while(i < positive.size() && j < negative.size()){
            arr[i+j] = positive[i];
            arr[i+j+1] = negative[j];
            i++;j++;
        }
        while(i < positive.size()) arr[i+j] = positive[i++];
        while(j < negative.size()) arr[i+j] = negative[j++];
        // while()
    }
    
    //Using the No Extra Space and also maintaining the order
    void rearrange(int arr[], int n){
        int neg_count = 0;
        for(int i = 0 ; i < n-neg_count; i++){
            if(arr[i]  < 0) {rotateArrayClockwise(arr, i , n-1, n); neg_count++;i--;}
        }
        
        // for(int k = 0; k < n; k++){
        //     cout<<arr[k]<<"\t";
        // }
        // cout<<endl;
        // cout<<"Negative Count : "<<neg_count<<endl;
        for(int i = 1; i < n; i+=2) {
            if(arr[i] >=0 && neg_count > 0){
                rotateArrayAntiClockwise(arr, i , n-neg_count, n);
                neg_count--;
            }
        }
        // for(int k = 0; k < n; k++){
        //     cout<<arr[k]<<"\t";
        // }
        // cout<<endl;
    }
    
    // Using No Extra Space and trying to maintain the order
    // This is not working
	void rearrange2(int arr[], int n) {
	   // code here
	   // There will be 2 cases when first number is positive and when first number is not positive
	   
	   int pos_i = 0;
	   //int pos_j = 0;
	   
	   int neg_i = 0;
	   //int neg_j = 0;
	   
	   int i = 0;
	   int j = 1;
	   while(pos_i < n && neg_i < n && i<n && j<n){
	       if(arr[i] < 0){
	           //Find next Positive numner and swapbetween
	           //cout<<"Checking the position i : "<<i << " "<< arr[i]<<endl;
	           while(pos_i < n){
	               if (arr[pos_i] >= 0) break;
	               pos_i++;
	           }
	           if(pos_i == n) break;
	           swapBetween(arr, i,  pos_i);
	           //for(int k = 0; k < n; k++){
            //         cout<<arr[k]<<"\t";
            //   }
            //   cout<<endl;
               
	           pos_i++;
	       }
	       pos_i = max(pos_i, i);
	       neg_i = max(neg_i, j);
	       if(arr[j] >= 0){
	           //find next negative number and swapbetween
	           //cout<<"Checking the position j : "<<j << " "<< arr[j]<<endl;
	           while(neg_i < n){
	               if (arr[neg_i] < 0) break;
	               neg_i++;
	           }
	           if(neg_i == n) break;
	           swapBetween(arr, j, neg_i);
	           //for(int k = 0; k < n; k++){
            //         cout<<arr[k]<<"\t";
            //   }
            //   cout<<endl;
	           neg_i++;
	       }
	       pos_i = max(pos_i, i);
	       neg_i = max(neg_i, j);
	       j+=2;
	       i+=2;
	   }
	    
	}
	
	void rotateArrayClockwise(int arr[], int i, int j, int n){
	    int temp = arr[i];
	    int k = i;
	    while(k<j){
	        arr[k] = arr[k+1];
	        k++;
	    }
	    arr[k] = temp;
	    
	   // cout<<"ClockWise Array is : ";
	   // for(k = 0; k < n; k++){
    //         cout<<arr[k]<<"\t";
    //     }
    //     cout<<endl;
	    
	}
	
	void rotateArrayAntiClockwise(int arr[], int i, int j, int n){
    	int temp = arr[j];
    	int k = j;
    	while( k > i){
    	    arr[k] = arr[k-1];
    	    k--;
    	}
    	arr[i] = temp;
    // 	cout<<"Anti ClockWise Array is : ";
	   // for(k = 0; k < n; k++){
    //         cout<<arr[k]<<"\t";
    //     }
    //     cout<<endl;
	}
	
	void swapBetween(int arr[], int i, int j){
	    cout<<"Swapping between i : "<<i<<" j : "<<j << " "  <<arr[i]<<" "<<arr[j]<<endl;
	    int temp = arr[i];
	    arr[i] = arr[j];
	    while(i<j){
	        i++;
	        int f1 = arr[i];
	        arr[i] = temp;
	        temp = f1;
	    }
	    cout<<"Array is : ";
	    for(int k = 0; k < sizeof(arr)/sizeof(arr[0]); k++){
            cout<<arr[k]<<"\t";
        }
        cout<<endl;
        
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends