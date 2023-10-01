#include <bits/stdc++.h> 

void bicheck(unordered_map<int, list<int>> &mp, bool &result, int node, int color, vector<int> &visit){
    
    if(!result) return;
    visit[node] = color;

    for(auto x: mp[node]){
        if(visit[x] == -1) bicheck(mp, result, x, !color, visit);
        else {
            if(visit[x]==color){
                result = false;
                return;
            }
        }
    }

    return;
}

bool twoCliques(int n, vector<vector<int>> &edgeList)
{
	// Write your code here 
    // This is test from smaller keyboard
    
    //Now the steps here include to change the adjacent matrix and take its complement

    vector<vector<bool>> cli(n, vector<bool>(n, true));

    for(auto x: edgeList){
        cli[x[0]][x[1]] = false;
        cli[x[1]][x[0]] = false;
    }

    unordered_map<int, list<int>> mp;
    // cout<<"Checking"<<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            // cout<<cli[i][j]<<"\t";
          if (cli[i][j] == true && i!=j) {
            mp[i].push_back(j);
            // mp[j].push_back(i);
          }
        }
        // cout<<endl;
    }

    vector<int> visit(n, -1);
    bool result = true;

    for(int i = 0; i < n; i++){
        if (visit[i] == -1) bicheck(mp, result, i, 0, visit);
    }
    

    return result;  

}

