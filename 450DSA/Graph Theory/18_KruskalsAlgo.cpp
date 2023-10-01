#include<bits/stdc++.h>

int FindParent(vector<int> &parent, int node){
  if(parent[node] == node) return node;
  
  //Adding Reassigned Parent address is shortcut to change the parent and find  parent faster next time
  return parent[node]=FindParent(parent, parent[node]);
}

void unionSet(vector<int> &parent, vector<int> &rank, int u, int v){

    u = FindParent(parent, u);
    v = FindParent(parent, v);

    if(rank[u] < rank[v]){
      parent[u] = v;
    } else if(rank[u] > rank[v]){
      parent[v] = u;
    } else{
      parent[v] = u;
      rank[u]++;
    }
}

bool mec(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  /*
    Don't write main().
    Don't read input, it is passed as function argument.    
    No need to print anything.
    Taking input and printing output is handled automatically.
  */

  sort(edges.begin(), edges.end(), mec);

  vector<bool> visit(n, false);
  int count = 0;
  int weight = 0;
  vector<int> parent(n+1, 0);
  vector<int> rank(n+1, 0);
  for(int i = 0; i <= n; i++) parent[i] = i;

  for(auto x: edges){
    int u = FindParent(parent,x[0]);
    int v = FindParent(parent,x[1]);
    
    if(u!=v){
      unionSet(parent, rank, u, v);
      weight+= x[2];
    }
  }

  return weight;

}