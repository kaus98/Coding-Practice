#include <bits/stdc++.h> 


//Is Safe to move to next grid
bool check(int x, int y, vector<vector<int>> &arr, vector<vector<bool>> &v, int n){
    if(x >= 0 && x < n && y >= 0 && y < n && arr[x][y] == 1 && v[x][y] == true) return true;
    return false;
}
//Recursion function to move to next index based on Down, Left, Right, UP

void f(vector<vector<int>> &arr, int n,  vector<vector<bool>> &v, int x, int y, vector<string> &result, string path){
    
    if(x == n-1 && y==n-1){
        //We have reached the path and can save the path to result
        result.push_back(path);
        return;
    }
    
    v[x][y] = false;

    //Checking for Down
    if(check(x+1, y, arr, v, n)) f(arr, n, v, x+1, y, result, path+"D");

    //Checking for Left
    if(check(x, y-1, arr, v, n)) f(arr, n, v, x, y-1, result, path+"L");

    //Checking for Right
    if(check(x, y+1, arr, v, n)) f(arr, n, v, x, y+1, result, path+"R");

    //Checking for Up
    if(check(x-1, y, arr, v, n)) f(arr, n, v, x-1, y, result, path+"U");

    v[x][y] = true;
    
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.

    vector<vector<bool>> visited(n , vector<bool>(n , true));
    vector<string> result;
    if(arr[0][0] == 0) {

        return result;

    }
    f(arr, n, visited, 0,0, result, "");
    return result;
    
    
}