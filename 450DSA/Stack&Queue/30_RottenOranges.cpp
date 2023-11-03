#include<bits/stdc++.h>

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    // Approach -> To Transerve the array and get all the rotten oranges and fresh one and put them in queue.
    // We will infect each of them one by one and check how much time it will take

    // first pair of I,J location and other of time
    // define tt pair<pair<int, int>, int>;

    queue<pair<pair<int, int>, int>> qu;
    int rotten = 0;
    int fresh = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 2) {qu.push({{i,j}, 0}); rotten += 1;}
            else if(grid[i][j] == 1) fresh+=1;
        }
    }
    if(rotten == 0 || fresh == 0) return 0;
    int i,j,tm;
    pair<pair<int, int>, int> temp;
    int mxTime = INT_MIN+1;

    while(!qu.empty()){

        temp = qu.front();
        i = temp.first.first;
        j = temp.first.second;
        tm = temp.second;
        mxTime = max(mxTime, tm);
        qu.pop();

        int mxTime = 0;

        //Direction is Up
        if(i-1 >= 0 && grid[i-1][j] == 1){
            grid[i-1][j] = 2;
            fresh--;
            qu.push({{i-1, j}, tm+1});
        }

        //Direction is Down
        if(i+1 < n && grid[i+1][j] == 1 ){
            grid[i+1][j] = 2;
            fresh--;
            qu.push({{i+1, j}, tm+1});
        }
        
        //Direction is Right
        if(j+1 < m && grid[i][j+1] == 1){
            grid[i][j+1] = 2;
            fresh--;
            qu.push({{i, j+1}, tm+1});
        }

        //Direction is Left
        if(j-1 >= 0  && grid[i][j-1] == 1){
            grid[i][j-1] = 2;
            fresh--;
            qu.push({{i, j-1}, tm+1});
        }
    }

    if(fresh==0) return mxTime;
    return -1;
}