#include <bits/stdc++.h> 

void f(unordered_map<int, vector<int>> &mp, vector<bool> &visit, int node, stack<int> &st){
    
    visit[node] = true;
    for(auto x: mp[node]){
        if(!visit[x]){
            f(mp, visit, x, st);
        }
    }
    st.push(node);
}

vector<int> ts(unordered_map<int, vector<int>> &mp, int v){
    
    vector<bool> visit(v+1, false);
    vector<int> result;
    stack<int> st;

    for(int i = 0; i < v; i++){
        if(!visit[i]) f(mp, visit, i, st);
    }

    while(!st.empty()){
        result.push_back(st.top());
        st.pop();
    }

    return result;
}

vector<int> kahnSorting(unordered_map<int, vector<int>> &mp, int v, vector<vector<int>> &edges){
    vector<int> count(v, 0);
    queue<int> qu;
    vector<int> result;

    for(auto x: edges){
        count[x[1]]++;
    }
    
    for(int i = 0; i < v; i++){
        if(count[i] == 0){
            qu.push(i);
            count[i] = -1;
        }
    }

    while(!qu.empty()){

        //Make all the next element of front to empty
        int top = qu.front();
        qu.pop();
        // cout<<"Top element is "<<top<<endl;
        result.push_back(top);

        for(auto x: mp[top]){
            count[x]--;
            if(count[x] == 0){
                qu.push(x);
                count[x] = -1;
            }
        }
    }

    return result;

}


vector<int> KahnAlgo(int n, vector<vector<int>> &edges){
    list<int> *l = new list<int>[n];
    vector<int> indegree(n, 0);

    for(auto x: edges){
        l[x[0]].push_back(x[1]);
        indegree[x[1]]++;
    }
    queue<int> qu;
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0) qu.push(i);
    }
    
    int top;
    vector<int> result;

    while(!qu.empty()){
        top = qu.front();
        qu.pop();
        result.push_back(top);

        for(int x: l[top]){
            indegree[x]--;
            if(indegree[x] == 0) qu.push(x);
        }
    }

    return result;
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<int> result;
    // unordered_map<int, vector<int>> mp;
    // for(auto x: edges){
    //     mp[x[0]].push_back(x[1]);
    // }

    // result = ts(mp, v);

    result = KahnAlgo(v, edges);
    return result;
}

// unordered_map<int, vector<int>> pm;
    // for(auto x: edges){
    //     pm[x[1]].push_back(x[0]);
    // }
    // for(auto x: pm){
    //     count[x.first] = x.second.size();
    // }
