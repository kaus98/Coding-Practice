//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<int> a;
        for(int i=0;i<x.length();i++)
        {
            if(x[i]=='{' || x[i]=='(' || x[i]=='[') a.push(x[i]);
            else if(a.empty() || (x[i]==']' && a.top()!='[') || (x[i]==')' && a.top()!='(') || (x[i]=='}' && a.top()!='{')) return 0;
            else a.pop();
        }
        return (a.empty());
    }
    

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends