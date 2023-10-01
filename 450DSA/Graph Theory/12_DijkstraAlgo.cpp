//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        //Min Heap
        // //We will pair<int, int> 
        // for(int i = 0; i < (*adj).size(); i++){
        //     for(int j = 0; j < (*adj)[i].size();  j++){
        //         cout<<(*adj)[i][j]<<"\t";
        //     }
        //     cout<<endl;
        // }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> result(V, INT_MAX-1);
        result[S] = 0;
        pq.push({0, S});
        pair<int,int> temp;
        
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            
            for(auto x: adj[node]){
                int nextNode = x[0];
                int nextWeight = x[1];
                
                if((dist+nextWeight) < result[nextNode]){
                    result[nextNode] = dist+nextWeight;
                    pq.push({dist+nextWeight, nextNode});
                }
            }
        }
        return result;
        
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends