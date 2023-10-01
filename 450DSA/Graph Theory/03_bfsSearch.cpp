vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    // cout<<"Starting :: "<<endl;
    // map<int, vector<int>> arr;
    // list<int> *l = new list<int>[n];
    vector<bool> visit(n, false);

    // for(auto i: adj){
    //     l[i[0]].push_back(i[1]);
    //     // cout<<"Pushing :: "<<i[0]<< " :: "<<i[1]<<endl; 
    //     // arr[i[1]].push_back(i[0]);
    // }
    
    queue<int> qu;
    qu.push(0);
    // visit[0] = 
    vector<int> result;

    while(!qu.empty()){
        int temp = qu.front();
        qu.pop();
        if(visit[temp] == false){
            result.push_back(temp);
            visit[temp] = true;
            for(auto x: adj[temp]){
                qu.push(x);
            }
        }      
    }

    return result;

}