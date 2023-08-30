//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int min1(int a, int b){
            if(a>b) return b;
            return a;
        }
        
        int min3(int a, int b, int c){
            if(a==b && a>c) return 2;
            if(a==b && a<c) return 1;
            if(a<b && a<c) {return 0;}
            if(b<a && b<c) {return 1;}
            return 2;
            
        }
       vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
        {
            //code here.
            int i = 0;
            int j = 0;
            int k = 0;
            set<int> count;
            while((i < n1) && (j < n2) && (k < n3)){
                
                if (a[i]==b[j] && b[j]==c[k]){
                    count.insert(a[i]);
                    i++;j++;k++;
                    //cout<<"Inserting the Element Here : "<<a[i]<<endl;
                }
                else{
                    int temp = min3(a[i], b[j], c[k]);
                    
                    if(temp == 0) i++;
                    else if(temp == 1) j++;
                    else k++;
                }
            }
            vector<int> count1(count.begin(), count.end());
            return count1;
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends