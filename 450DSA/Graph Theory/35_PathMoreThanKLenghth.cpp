//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution {
public:
    bool pathMoreThanK(int V, int E, int K, int *arr) 
    { 
       //  Code Here
       unordered_map<int, vector<pair<int, int>>> mp;
       
       for(int i = 0; i < 3*E; i+=3){
           mp[arr[i]].push_back({arr[i+1], arr[i+2]});
           mp[arr[i+1]].push_back({arr[i], arr[i+2]});
        }
        
        bool result = false;
        vector<bool> visit(V, false);
        solve(mp, K, 0, 0, result, visit);
        
        return result;
    } 
    void solve(unordered_map<int, vector<pair<int, int>>> mp, int K, int node, int distance, bool &result, vector<bool> &visit){
        if(distance >= K) {
            result = true;
        }
        
        if(result) return;
        visit[node] = true;
        int nextNode;
        int dis; 
        
        for(auto x: mp[node]){
            nextNode = x.first;
            dis = x.second;
            
            if(!visit[nextNode]){
                solve(mp, K, nextNode, dis+distance, result, visit);
            }
        }
        visit[node] = false;
        
        return;
    }
};






//{ Driver Code Starts.


int main() {
	//code
    int t;cin >> t;
    while(t--)
    {
        int V, E, K;
        cin >> V >> E >> K;
        int a[3*E + 1];
        for(int  i=0;i<3*E;i++){
            cin >> a[i];
        }
        
        Solution obj;
        if(obj.pathMoreThanK(V, E, K, a)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends