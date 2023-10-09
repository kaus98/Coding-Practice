//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string s, string t)
    {
        
       map<char, char> abc;
        map<char, char> cba;

        if(s.length() != t.length()){
            return false;
        }

        // int i = 0;
        for(int i = 0; i < s.length(); i++){
            if (abc.find(s[i]) == abc.end()){
                if(cba.find(t[i]) == cba.end()){
                    abc[s[i]] = t[i];
                    cba[t[i]] = s[i];

                }
                else{
                    return false;
                }
                
            }
            else{
                if(abc[s[i]] != t[i] || cba[t[i]] != s[i]){
                    return false;
                }
            }
        }
        return true;
        
    }
};


//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends