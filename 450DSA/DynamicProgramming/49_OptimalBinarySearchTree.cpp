#include <bits/stdc++.h> 

int f(vector<int> &arr, vector<int> &freq, int i, int j, int height,map<pair<pair<int, int>, int>, int> &dp){

    if(i>j) return 0;
    if(i==j) return dp[{{i,j},height}] = freq[i]*height;

    if (dp.find({{i,j},height}) != dp.end())
      return dp[{{i,j},height}];

    int minCost = INT_MAX-1;
    int left, right, top;

    for(int k = i; k <= j; k++){
        top = freq[k]*height;
        left = f(arr, freq, i, k-1, height+1, dp);
        right = f(arr, freq, k+1, j, height+1, dp);

        minCost = min(minCost, top+left+right);
    }

    return dp[{{i,j},height}] = minCost;
}

int f3(vector<int> &arr, vector<int> &freq, int i, int j, int height,vector<vector<int>> &dp){

    if(i>j) return 0;
    if(i==j) return dp[i][j] = freq[i]*height;

    if(dp[i][j] != -1) return dp[i][j];

    int minCost = INT_MAX-1;
    int left, right, top;

    for(int k = i; k <= j; k++){
        top = freq[k]*height;
        left = f3(arr, freq, i, k-1, height+1, dp);
        right = f3(arr, freq, k+1, j, height+1, dp);

        minCost = min(minCost, top+left+right);
    }
    return dp[i][j] = minCost;
}


int f2(vector<int> &arr, vector<int> &freq, int i, int j, int height, map<string, int> &dp){

    if(i>j) return 0;

    string temp = to_string(i)+"|"+to_string(j)+"|"+to_string(height);

    

    if (dp.find(temp) != dp.end())
      return dp[temp];

    if(i==j) return dp[temp] = freq[i]*height;
    
    int minCost = INT_MAX-1;
    int left, right, top;

    for(int k = i; k <= j; k++){

        top = freq[k]*height;
        left = f2(arr, freq, i, k-1, height+1, dp);
        right = f2(arr, freq, k+1, j, height+1, dp);

        minCost = min(minCost, top+left+right);
    }

    return dp[temp] = minCost;
}

// Video for Solution
// https://www.youtube.com/watch?v=g20bLO7ZHSs&t=61s
int f4(vector<int> &arr, vector<int> &freq, int i, int j){
    //First one will be for Column
    //Second we will move up and down the row
    vector<vector<int>> dp(arr.size()+1, vector<int> (arr.size()+1, -1));
    for(int j = 0; j < arr.size(); j++){
        for(int i = j; i >= 0; i--){
            // cout<<"Accessing :: "<<i<<" :: "<<j<<endl;
            if(i == j) dp[i][j] = freq[i];
            else{
                int sum = 0;
                for(int k = i; k <= j; k++) sum+= freq[k];
                int minY = INT_MAX-1;
                for(int k = i; k <= j; k++){
                    int leftS = (k>i)?dp[i][k-1]:0;
                    int rightS = (k<j)?dp[k+1][j]:0;
                    minY = min( leftS+rightS+sum, minY);
                }
                dp[i][j] = minY;
            }
        }
    }
    return dp[0][arr.size()-1];
}


int minCostBST(vector<int> &arr, vector<int> &freq){
    // Write your code here.
    // vector<vector<int>> mp(arr.size()+1, vector<int>(arr.size()+1, -1));
    // map<pair<pair<int, int>, int>, int> mp;
    // map<string, int> mp;
    // return f2(arr, freq, 0, arr.size()-1, 1, mp);

    return f4(arr, freq, 0, arr.size()-1);
}   

