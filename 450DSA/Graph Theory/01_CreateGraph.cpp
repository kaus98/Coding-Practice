vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.

    vector<vector<int>> arr(n);
    for(int i = 0; i < n; i++){
        arr[i].push_back(i);
    }

    for(auto i: edges){
        arr[i[0]].push_back(i[1]);
        arr[i[1]].push_back(i[0]);
    }
    return arr;
}