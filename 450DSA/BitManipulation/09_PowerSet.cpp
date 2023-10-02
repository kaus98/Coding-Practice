//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> result;
		    
		    int size = pow(2, s.size());
		    int counter, j;
		    
		    for(counter = 1; counter <= size; counter++){
		        string temp = "";
		        for(j = 0; j < s.size(); j++){
		            if(counter & (1<<j)){
		                temp+=s[j];
		            }
		        }
		        result.push_back(temp);
		    }
		    sort(result.begin(), result.end());
		    result.erase(result.begin());
		  //  cout<<"Size :: "<<result.size()<<endl;
		    return result;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends