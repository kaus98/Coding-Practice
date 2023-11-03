vector < vector < int > > nearest(vector < vector < int >> & mat, int n, int m) {
    // Write your code here.

    vector<vector<int>> result(n, vector<int>(m, 0));

    queue<pair<pair<int, int>, int>> qu;

    int i,j, dist;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(mat[i][j] == 1) qu.push({{i,j}, 0});
        }
    }
        
    pair<pair<int, int>, int> temp;    
    while(!qu.empty()){
        temp = qu.front();
        qu.pop();
        i = temp.first.first;
        j = temp.first.second;
        dist = temp.second;
        result[i][j] = dist;

        //Looking Upward
        if(i-1 >= 0 && mat[i-1][j] == 0){
            mat[i-1][j] = 1;
            qu.push({{i-1,j}, dist+1});
        }

        //Looking Downward
        if(i+1 < n && mat[i+1][j] == 0){
            mat[i+1][j] = 1;
            qu.push({{i+1,j}, dist+1});
        }

        //Looking RightSide
        if(j+1 < m && mat[i][j+1] == 0){
            mat[i][j+1] = 1;
            qu.push({{i,j+1}, dist+1});
        }

        //Looking LeftSide
        if(j-1 >= 0 && mat[i][j-1] == 0){
            mat[i][j-1] = 1;
            qu.push({{i,j-1}, dist+1});
        }
    }

    return result;


}